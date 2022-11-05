#include <network/Ether.h>

#include <cstdlib>
#include <cstring>
#include <cstdio>

void Ether::recv_header() {
    hdr = (xether_hdr_t*)get_data();
    for (int i = 0; i < XNET_MAC_ADDR_SIZE; i++) {
        printf("%d", hdr->src_mac[i]);
        if (i < XNET_MAC_ADDR_SIZE - 1) printf("-");
        else printf("\n");
    }
    if (get_size() <= get_header_size()) {
        set_aborted(true);
        return;
    }
}


Ether::Ether() {

}


Ether::Ether(const Ether* ether_packet) {
    net_packet = new xnet_packet_t(ether_packet->net_packet);
    aborted = ether_packet->aborted;
    set_header_size(sizeof(xether_hdr_t));
    recv_header();
}


Ether::~Ether() {
}


uint16_t Ether::get_protocol() {
    return swap_order16(hdr->protocol);
}
