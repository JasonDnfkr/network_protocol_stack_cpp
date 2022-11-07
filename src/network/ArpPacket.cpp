#include <network/ArpPacket.h>
#include <network/Config.h>

#include <cstring>
#include <cstdio>

void ArpPacket::spawn_header() {
    hdr = (xarp_hdr_t*)get_data();
    if (get_size() < get_header_size()) {
        set_aborted(true);
        return;
    }
}


ArpPacket::ArpPacket() {
    net_packet = new xnet_packet_t(sizeof(xarp_hdr_t));
    spawn_header();
}


ArpPacket::ArpPacket(const ArpPacket* arp_packet) {
    init_constructor(arp_packet, sizeof(xarp_hdr_t));
}


ArpPacket::~ArpPacket() {  } 

// 构建一个 arp annoucement 请求报文 (request)
// 包内构建，无返回值
void ArpPacket::spawn_announcement_packet() {
    hdr->hardware_type   = swap_order16(XARP_HW_ETHER);
    hdr->protocol_type   = swap_order16(XNET_PROTOCOL_IP);
    hdr->hardware_length = XNET_MAC_ADDR_SIZE;
    hdr->protocol_length = XNET_IPV4_ADDR_SIZE;
    hdr->opcode          = swap_order16(XARP_REQUEST);
    memcpy(hdr->sender_mac, netif_mac, XNET_MAC_ADDR_SIZE);
    memcpy(hdr->sender_ip, netif_ipaddr.array, XNET_IPV4_ADDR_SIZE);
    memset(hdr->target_mac, 0, XNET_MAC_ADDR_SIZE);
    memcpy(hdr->target_ip, netif_ipaddr.array, XNET_IPV4_ADDR_SIZE);
}


// 构建一个 arp 响应报文 (reply)
// 参数：需要回应的 ARP 报文
// 包内构建，无返回值
void ArpPacket::spawn_reply_packet(ArpPacket* dest_arp_packet) {
    hdr->hardware_type   = swap_order16(XARP_HW_ETHER);
    hdr->protocol_type   = swap_order16(XNET_PROTOCOL_IP);
    hdr->hardware_length = XNET_MAC_ADDR_SIZE;
    hdr->protocol_length = XNET_IPV4_ADDR_SIZE;
    hdr->opcode          = swap_order16(XARP_REPLY);
    memcpy(hdr->sender_mac, netif_mac, XNET_MAC_ADDR_SIZE);
    memcpy(hdr->sender_ip, netif_ipaddr.array, XNET_IPV4_ADDR_SIZE);
    memcpy(hdr->target_mac, dest_arp_packet->get_sender_mac(), XNET_MAC_ADDR_SIZE);
    memcpy(hdr->target_ip, dest_arp_packet->get_sender_ip(), XNET_IPV4_ADDR_SIZE);
}

uint16_t ArpPacket::get_protocol() {
    return swap_order16(hdr->protocol_type);
}


void ArpPacket::check() {
    if ((swap_order16(hdr->hardware_type) != XARP_HW_ETHER) ||
            (hdr->hardware_length != XNET_MAC_ADDR_SIZE) ||
            (swap_order16(hdr->protocol_type) != XNET_PROTOCOL_IP) ||
            (hdr->protocol_length != XNET_IPV4_ADDR_SIZE)
            || ((swap_order16(hdr->opcode) != XARP_REQUEST) && (swap_order16(hdr->opcode) != XARP_REPLY))) {
        set_aborted(true);
        return;
    }

    if (!is_xipaddr_equal_buf(&netif_ipaddr, hdr->target_ip)) {
        set_aborted(true);
        return;
    }
}

// 输出 ARP 报头信息
void ArpPacket::print() {
    printf("==========================================\n");
    printf("Address Resolution Protocol (%s)\n", swap_order16(hdr->opcode) == XARP_REQUEST ? "request" : "reply");
    printf("Hardware type: %s (%d)\n", swap_order16(hdr->hardware_type) == XARP_HW_ETHER ? "Ethernet" : "Other", swap_order16(hdr->hardware_type));
    printf("Protocol type: %s (0x%04x)\n", swap_order16(hdr->protocol_type) == XNET_PROTOCOL_IP ? "IPv4" : "Other", swap_order16(hdr->protocol_type));
    printf("Hardware size: %d\n", hdr->hardware_length);
    printf("Protocol size: %d\n", hdr->protocol_length);
    printf("Opcode: %s (%d)\n", swap_order16(hdr->opcode) == XARP_REQUEST ? "request" : "reply", swap_order16(hdr->opcode));
    printf("Sender MAC address: %s\n", str_mac_addr(hdr->sender_mac).c_str());
    printf("Sender IP Address: %s\n", str_ip_addr(hdr->sender_ip).c_str());
    printf("Target MAC address: %s\n", str_mac_addr(hdr->target_mac).c_str());
    printf("Target IP Address: %s\n", str_ip_addr(hdr->target_ip).c_str());
    printf("==========================================\n");
}


// inline uint16_t ArpPacket::get_opcode() {
//     return swap_order16(hdr->opcode);
// }

// // 获取 sender_ip
// inline uint8_t* ArpPacket::get_sender_ip() {
//     return hdr->sender_ip;
// }

// // 获取 sender_mac
// inline uint8_t* ArpPacket::get_sender_mac() {
//     return hdr->sender_mac;
// }

// // 获取 target_ip
// inline uint8_t* ArpPacket::get_target_ip() {
//     return hdr->target_ip;
// }

// // 获取 target_mac
// inline uint8_t* ArpPacket::get_target_mac() {
//     return hdr->target_mac;
// }