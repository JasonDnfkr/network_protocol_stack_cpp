#include <network/ArpPacket.h>

#include <cstring>
#include <cstdio>

void ArpPacket::spawn_header() {
    hdr = (xarp_hdr_t*)get_data();
    if (get_size() <= get_header_size()) {
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


// 构建一个 arp 请求报文。
// 参数：target_ip
// 包内构建，无返回值
void ArpPacket::spawn_request_packet(const xipaddr_t* ipaddr) {
    hdr->hardware_type   = swap_order16(XARP_HW_ETHER);
    hdr->protocol_type   = swap_order16(XNET_PROTOCOL_IP);
    hdr->hardware_length = XNET_MAC_ADDR_SIZE;
    hdr->protocol_length = XNET_IPV4_ADDR_SIZE;
    hdr->opcode          = swap_order16(XARP_REQUEST);
    memcpy(hdr->sender_mac, netif_mac, XNET_MAC_ADDR_SIZE);
    memcpy(hdr->sender_ip, netif_ipaddr.array, XNET_IPV4_ADDR_SIZE);
    memset(hdr->target_mac, 0, XNET_MAC_ADDR_SIZE);
    memcpy(hdr->target_ip, ipaddr->array, XNET_IPV4_ADDR_SIZE);
}


uint16_t ArpPacket::get_protocol() {
    return swap_order16(hdr->protocol_type);
}


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