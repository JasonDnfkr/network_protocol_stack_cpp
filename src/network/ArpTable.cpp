#include <network/ArpTable.h>
#include <network/ArpController.h>
#include <cstring>
#include <ctime>

void ArpTable::constructor_init() {
}


ArpTable::ArpTable() {
    constructor_init();
}


ArpTable::~ArpTable() {
}


ArpTable::xarp_entry_t::xarp_entry_t() {
    ip_addr.addr = 0;
    memset(mac_addr, 0, XNET_MAC_ADDR_SIZE);
    state = XARP_ENTRY_FREE;
    tmo = 0;
    retry_cnt = 0;
}


ArpTable::xarp_entry_t::xarp_entry_t(uint8_t* src_ip, uint8_t* mac_addr) {
    memcpy(&ip_addr.array, src_ip, XNET_IPV4_ADDR_SIZE);
    memcpy(mac_addr, src_mac_addr, XNET_MAC_ADDR_SIZE);
    state     = XARP_ENTRY_OK;
    tmo       = XARP_CFG_ENTRY_TMO;
    retry_cnt = XARP_CFG_MAX_RETRIES;
}


void ArpTable::update(ArpPacket* arp_packet) {
    uint8_t* sender_ip = arp_packet->get_sender_ip();
    uint8_t* sender_mac = arp_packet->get_sender_ip();

    
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


xnet_time_t ArpTable::sys_get_time() {
    return clock() / CLOCKS_PER_SEC;
}


bool ArpTable::xarp_entry_t::check_tmo(uint32_t sec) {
    xnet_time_t curr = clock() / CLOCKS_PER_SEC;
    if (sec == 0) {
        arp_timer = curr;
        return false;
    }
    else if (curr - arp_timer >= sec) {
        arp_timer = sec;
        return true;
    }
    return false;
}


void ArpTable::arp_table_poll() {
    if (arp_entries.size() == 0) {
        return;
    }
    // for (auto& entry : arp_entries) {
    //     if (entry->check_tmo(XARP_TIMER_PERIOD)) {
    //         switch (entry->state) {
    //             case XARP_ENTRY_OK: {

    //             }
    //         }
    //     }
    // }
}