#include <network/ArpPacket.h>


void ArpPacket::recv_header() {
    hdr = (xarp_hdr_t*)get_data();
    if (get_size() <= get_header_size()) {
        set_aborted(true);
        return;
    }
}


ArpPacket::ArpPacket() {
    set_header_size(sizeof(xarp_hdr_t));
    recv_header();
}


ArpPacket::ArpPacket(const ArpPacket* ether_packet) {
    // 这里接收到的是 Ether* 包，有完整的 Ethernet II 报头，要去掉
    net_packet = new xnet_packet_t(ether_packet->net_packet);
    aborted = ether_packet->aborted;
    set_header_size(sizeof(xarp_hdr_t));
    
    recv_header();
}


uint16_t ArpPacket::get_protocol() {
    return swap_order16(hdr->protocol_type);
}