#include <network/Ether.h>
#include <network/ArpPacket.h>

#include <cstdlib>
#include <cstring>
#include <cstdio>

void Ether::spawn_header() {
    hdr = (xether_hdr_t*)get_data();
    if (get_size() <= get_header_size()) {
        set_aborted(true);
        return;
    }
}


Ether::Ether() {

}

// Constructor: 接收数据包
Ether::Ether(const Ether* ether_packet) {
    init_constructor(ether_packet, sizeof(xether_hdr_t));
    // net_packet = new xnet_packet_t(ether_packet->net_packet);
    // aborted = ether_packet->aborted;
    
    // set_header_size(sizeof(xether_hdr_t));
    // recv_header();
}


// Constructor: 接收 arp 数据包，套上 xether 报头，并处理
Ether::Ether(const Ether* arp_packet, const uint8_t* mac_addr, xnet_protocol_t protocol) {
    net_packet = new xnet_packet_t(arp_packet->net_packet);
    aborted = arp_packet->aborted;

    set_header_size(sizeof(xether_hdr_t));
    add_header(header_size);
    spawn_header();

    memcpy(hdr->dest_mac, mac_addr, XNET_MAC_ADDR_SIZE);
    memcpy(hdr->src_mac, netif_mac, XNET_MAC_ADDR_SIZE);
    hdr->protocol = swap_order16(protocol);
}


Ether::~Ether() {
}


uint16_t Ether::get_protocol() {
    return swap_order16(hdr->protocol);
}
