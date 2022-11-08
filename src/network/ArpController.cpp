#include <network/ArpController.h>
#include <network/EtherController.h>

#include <cstdio>
#include <cstring>
#include <ctime>

inline const static xnet_time_t sys_get_time() {
    return clock() / CLOCKS_PER_SEC;
}


void ArpController::constructor_init() {
}


ArpController::ArpController() {
}


ArpController::ArpController(EtherController* ether_controller) {
    this->ether_controller = ether_controller;
}


ArpController::~ArpController() {
}


ArpController::xarp_entry_t::xarp_entry_t() {
    ip_addr.addr = 0;
    memset(mac_addr, 0, XNET_MAC_ADDR_SIZE);
    state = XARP_ENTRY_FREE;
    tmo = 0;
    retry_cnt = 0;
}


ArpController::xarp_entry_t::xarp_entry_t(uint8_t* src_ip, uint8_t* src_mac_addr) {
    memcpy(&ip_addr.array, src_ip, XNET_IPV4_ADDR_SIZE);
    memcpy(mac_addr, src_mac_addr, XNET_MAC_ADDR_SIZE);
    state     = XARP_ENTRY_OK;
    tmo       = XARP_CFG_ENTRY_TMO;
    retry_cnt = XARP_CFG_MAX_RETRIES;
    arp_timer = sys_get_time();
}

// 更新 ARP 表
void ArpController::arp_entries_update(ArpPacket* arp_packet) {
    uint8_t* sender_ip = arp_packet->get_sender_ip();
    uint8_t* sender_mac = arp_packet->get_sender_mac();

    
    if (arp_entries.size() == 0) {
        arp_entries.push_back(new xarp_entry_t(sender_ip, sender_mac));
    }
    else if (arp_entries.size() > 0) {
        for (auto& entry : arp_entries) {
            if (memcmp(entry->ip_addr.array, sender_ip, XNET_IPV4_ADDR_SIZE) != 0) {
                continue;
            }

            memcpy(&entry->ip_addr.addr, sender_ip, XNET_IPV4_ADDR_SIZE);
            memcpy(entry->mac_addr, sender_mac, XNET_MAC_ADDR_SIZE);
            entry->state     = XARP_ENTRY_OK;
            entry->tmo       = XARP_CFG_ENTRY_TMO;
            entry->retry_cnt = XARP_CFG_MAX_RETRIES;
        }
    }
}

// 检查这个结构体中的表项是否超时
bool ArpController::xarp_entry_t::check_tmo(uint32_t sec) {
    xnet_time_t curr = sys_get_time();
    if (sec == 0) {
        arp_timer = curr;
        return false;
    }
    else if (curr - arp_timer >= sec) {
        arp_timer = curr;
        return true;
    }
    return false;
}


// 生成一个 ARP Announcement 报文
// 返回值：返回一个 arp 报文
ArpPacket* ArpController::arp_make_announcement() {
    ArpPacket* arp_packet = new ArpPacket();
    arp_packet->spawn_announcement_packet();
    return arp_packet;
}


// 生成一个 ARP Response 报文
// 参数：接收到的 request 报文
// 返回值：返回一个 ARP 报文
ArpPacket* ArpController::arp_make_response(ArpPacket* arp_packet) {
    ArpPacket* arp_response_packet = new ArpPacket();
    arp_response_packet->spawn_reply_packet(arp_packet);
    return arp_response_packet;
}


// 生成一个 ARP Request 报文，
// 请求指定 IP 的主机，返回一个 ARP 响应报文
// 参数：所需请求的 IP 地址
// 返回值：返回一个 ARP 报文
ArpPacket* ArpController::arp_make_request(const xipaddr_t* ipaddr) {
    ArpPacket* arp_request_packet = new ArpPacket();
    arp_request_packet->spawn_request_packet(ipaddr);
    return arp_request_packet;
}


void ArpController::arp_in(ArpPacket* arp_packet) {
    printf("[ArpController] Received an arp_packet, sender ip: %s, sender mac: %s\n", str_ip_addr(arp_packet->get_sender_ip()).c_str(), str_mac_addr(arp_packet->get_sender_mac()).c_str());
    // arp_packet.
    uint16_t opcode = arp_packet->get_opcode();
    switch (opcode) {
        case XARP_REQUEST: {
            printf("[ArpController] Analyzing an arp request packet..\n");
            ArpPacket* response_arp_packet = arp_make_response(arp_packet);
            arp_entries_update(arp_packet);
            arp_out(response_arp_packet, ether_broadcast);
            break;
        }
        case XARP_REPLY: {
            arp_entries_update(arp_packet);
            break;
        }
    }
}

// 发送一个 ArpPacket* arp_packet, 目的 mac 是该 arp_packet 的 mac 地址
void ArpController::arp_out(ArpPacket* arp_packet) {
    Ether* ether_packet = new Ether(arp_packet, arp_packet->get_target_mac(), XNET_PROTOCOL_ARP);
    ether_controller->ethernet_out_to(ether_packet);
}


// 发送一个 ArpPacket* arp_packet, 目的 mac 是第二个参数
void ArpController::arp_out(ArpPacket* arp_packet, const uint8_t* dest_mac_addr) {
    Ether* ether_packet = new Ether(arp_packet, dest_mac_addr, XNET_PROTOCOL_ARP);
    ether_controller->ethernet_out_to(ether_packet);
}


void ArpController::arp_entries_poll() {
    if (arp_entries.empty()) {
        return;
    }

    std::vector<int> need_erase;

    for (int i = 0; i < arp_entries.size(); i++) {
        if (arp_entries[i]->check_tmo(XARP_TIMER_PERIOD)) {
            switch (arp_entries[i]->state) {
                case XARP_ENTRY_OK: {
                    printf("[ArpController] arp_entries[%d], ip: %s, timeout: %d\n", i, str_ip_addr(arp_entries[i]->ip_addr.array).c_str(), arp_entries[i]->tmo);
                    arp_entries[i]->tmo--;
                    if (arp_entries[i]->tmo == 0) {
                        ArpPacket* arp_request_packet = arp_make_request(&arp_entries[i]->ip_addr);
                        arp_out(arp_request_packet, arp_entries[i]->mac_addr);
                        printf("[ArpController] arp_entries[%d], ip %s, sent out a boardcast arp for resolving to mac: %s.\n",
                         i, str_ip_addr(arp_entries[i]->ip_addr.array).c_str(),
                         str_mac_addr(arp_entries[i]->mac_addr).c_str());
                        arp_entries[i]->state = XARP_ENTRY_RESOLVING;
                        arp_entries[i]->tmo = XARP_CFG_ENTRY_PENDING_TMO;
                    }
                    break;
                }
                case XARP_ENTRY_RESOLVING: {
                    arp_entries[i]->tmo--;
                    if (arp_entries[i]->tmo == 0) {
                        arp_entries[i]->retry_cnt--;
                        printf("[ArpController] arp_entries[%d], ip: %s, retry_cnt: %d\n", i, str_ip_addr(arp_entries[i]->ip_addr.array).c_str(), arp_entries[i]->retry_cnt);
                        if (arp_entries[i]->retry_cnt == 0) {
                            arp_entries[i]->state = XARP_ENTRY_FREE;
                            need_erase.push_back(i);
                        }
                        else {
                            ArpPacket* arp_request_packet = arp_make_request(&arp_entries[i]->ip_addr);
                            arp_out(arp_request_packet, ether_broadcast);                        
                            printf("[ArpController] arp_entries[%d], ip %s, sent out a boardcast arp for resolving to mac: %s.\n",
                            i, str_ip_addr(arp_entries[i]->ip_addr.array).c_str(),
                            str_mac_addr(arp_entries[i]->mac_addr).c_str());                            
                         arp_entries[i]->state = XARP_ENTRY_RESOLVING;
                            arp_entries[i]->tmo = XARP_CFG_ENTRY_PENDING_TMO;
                        }
                    }
                    break;
                }
            }
        }
    }

    if (need_erase.empty()) {
        return;
    }

    for (int i : need_erase) {
        printf("[ArpController] arp_entries[%d] free.\n", i);
        arp_entries.erase(arp_entries.begin() + i);
    }
}