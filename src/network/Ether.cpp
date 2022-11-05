#include <network/Ether.h>

#include <cstdlib>
#include <cstring>

void Ether::get_header() {
    hdr = (xether_hdr_t*)get_data();
    if (get_size() <= get_header_size()) {
        set_aborted(true);
        return;
    }
}


Ether::Ether() {

}


Ether::Ether(const Ether* packet) {
    // memcpy(net_packet, packet->net_packet, sizeof(xnet_packet_t));
    net_packet = new xnet_packet_t(packet->net_packet);
    aborted = packet->aborted;
    set_header_size(sizeof(xether_hdr_t));
    get_header();
}


Ether::~Ether() {

}


uint16_t Ether::get_protocol() {
    return swap_order16(hdr->protocol);
}
