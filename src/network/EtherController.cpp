#include <network/EtherController.h>
#include <cstdio>

void EtherController::init() {
    arp_controller = new ArpController();
}


EtherController::EtherController() {
    init();
}


EtherController::~EtherController() { } 


void EtherController::ethernet_in(Ether* ether_packet) {
    printf("EtherController: Packet* received.\n");
    // Ether* ether_packet = new Ether(ether_packet);

    uint16_t protocol = ether_packet->get_protocol();
    ether_packet->remove_header();

    switch (protocol) {
    case XNET_PROTOCOL_ARP:
        printf("EtherController: switch to case XNET_PROTOCOL_ARP");
        // ArpPacket* arp_packet = new ArpPacket((ArpPacket*)ether_packet);
        // delete ether_packet;
        // arp_controller->arp_in(arp_packet);
        
        break;
    
    case XNET_PROTOCOL_IP:

        break;

    default:
        break;
    }
}