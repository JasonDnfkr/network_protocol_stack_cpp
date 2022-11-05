#include <network/ArpController.h>

#include <cstdio>

ArpController::ArpController(/* args */) {
}


ArpController::~ArpController() {
}


void arp_make_request(const xipaddr_t* ipaddr) {
    ArpPacket* arp_packet = new ArpPacket();
}



void arp_in(ArpPacket* arp_packet) {
    printf("ArpController: recv arp_packet.\n");
}
