#include <network/EtherController.h>
#include <network/ArpPacket.h>
#include <pcap_device.h>
#include <network/Driver.h>
#include <network/ArpController.h>

#include <cstdio>

void EtherController::init() {
    arp_controller = new ArpController(this);
}


EtherController::EtherController() {
    init();
}

EtherController::EtherController(Driver* driver) {
    this->driver = driver;
    init();
}


EtherController::~EtherController() { } 


// 以太网控制器初始化
// 自动发送一个 42 ARP Announcement 无回报报文
void EtherController::ethernet_init() {
    ArpPacket* arp_packet = arp_controller->arp_make_announcement();
    arp_packet->print();
    Ether* ether_packet = new Ether(arp_packet, ether_broadcast, XNET_PROTOCOL_ARP);
    ethernet_out_to(ether_packet);
}


void EtherController::ethernet_in(Ether* ether_packet) {
    printf("EtherController: Packet* received.\n");
    
    uint16_t protocol = ether_packet->get_protocol();
    ether_packet->remove_header();

    switch (protocol) {
        case XNET_PROTOCOL_ARP: {
            printf("EtherController: switch to case XNET_PROTOCOL_ARP\n");
            ArpPacket* arp_packet = new ArpPacket((ArpPacket*)ether_packet);
            // arp_packet->check();
            delete ether_packet;
            if (arp_packet->is_aborted()) {
                printf("EtherController: ARP packet aborted.\n");
                delete arp_packet;
                break;
            }
            arp_controller->arp_in(arp_packet);
            break;
        }
        case XNET_PROTOCOL_IP: {
            break;
        }

        default: {
            break;
        }
    }
}

void EtherController::ethernet_out_to(Ether* ether_packet) {
    driver->driver_send(ether_packet);
}
