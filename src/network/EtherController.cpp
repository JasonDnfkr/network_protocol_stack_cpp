#include <network/EtherController.h>
#include <network/ArpPacket.h>
#include <pcap_device.h>
#include <network/Driver.h>
#include <network/ArpController.h>
#include <network/Config.h>

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
    // arp_packet->print();
    Ether* ether_packet = new Ether(arp_packet, ether_broadcast, XNET_PROTOCOL_ARP);
    ethernet_out_to(ether_packet);
}


// EtherController 轮询
void EtherController::ethernet_poll(Ether* packet) {
    // 屎山代码，驱动传来的数据包
    // 还没有写一个可以在类内让 hdr 自动指向数据的函数，
    // 所以只能借助构造函数来暂时实现
    if (packet) {
        Ether* ether_packet = new Ether(packet);
        delete packet;
        ethernet_in(ether_packet);
    }
    arp_controller->arp_entries_poll();
}


void EtherController::ethernet_in(Ether* ether_packet) {
    debug_low("[EtherController] Packet* received.\n");
    
    uint16_t protocol = ether_packet->get_protocol();
    ether_packet->remove_header();

    switch (protocol) {
        case XNET_PROTOCOL_ARP: {
            debug_low("EtherController: switch to case XNET_PROTOCOL_ARP\n");
            ArpPacket* arp_packet = new ArpPacket((ArpPacket*)ether_packet);
            // arp_packet->check();
            delete ether_packet;
            if (arp_packet->is_aborted()) {
                debug_low("EtherController: ARP packet aborted.\n");
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
