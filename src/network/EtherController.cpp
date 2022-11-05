#include <network/EtherController.h>
#include <cstdio>

void EtherController::init() {
    arp_controller = new ArpController();
}


EtherController::EtherController() {
    init();
}


EtherController::~EtherController() { } 


void EtherController::ethernet_in(Packet* packet) {
    printf("ether_controller: Packet* received.\n");
    Ether* ether_packet = new Ether((Ether*)packet);

    uint16_t protocol = ether_packet->get_protocol();
    ether_packet->remove_header();

    switch (protocol) {
    case XNET_PROTOCOL_ARP:
        /* code */
        
        break;
    
    case XNET_PROTOCOL_IP:

        break;

    default:
        break;
    }
}