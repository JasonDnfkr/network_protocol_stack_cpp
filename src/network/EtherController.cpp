#include <network/EtherController.h>
#include <network/ArpPacket.h>
#include <pcap_device.h>
#include <network/Driver.h>

#include <cstdio>

void EtherController::init() {
    arp_controller = new ArpController();
}


EtherController::EtherController() {
    init();
}


EtherController::~EtherController() { } 


// 以太网控制器初始化
// 自动发送一个 42 ARP Announcement 无回报报文
void EtherController::ethernet_init() {
    ArpPacket* arp_packet = arp_controller->arp_make_request(&netif_ipaddr);
    arp_packet->print();
    Ether* ether_packet = new Ether(arp_packet, ether_broadcast, XNET_PROTOCOL_ARP);
    driver->driver_send(ether_packet);
}


void EtherController::ethernet_in(Ether* ether_packet) {
    printf("EtherController: Packet* received.\n");
    
    uint16_t protocol = ether_packet->get_protocol();
    ether_packet->remove_header();

    switch (protocol) {
    case XNET_PROTOCOL_ARP: {
        printf("EtherController: switch to case XNET_PROTOCOL_ARP\n");
        ArpPacket* arp_packet = new ArpPacket((ArpPacket*)ether_packet);
        delete ether_packet;
        arp_controller->arp_in(arp_packet);
        break;
    }
    case XNET_PROTOCOL_IP:

        break;

    default:
        break;
    }
}

void EtherController::ethernet_out_to(const Ether* ether_packet, const uint8_t* mac_addr, xnet_protocol_t protocol) {
    // Ether* ether_packet = new Ether(arp_packet, ether_broadcast, XNET_PROTOCOL_ARP);
    // 增加一个 Ether update 用于内部自身修改
    
}
