#include <network/ArpController.h>
#include <network/EtherController.h>

#include <cstdio>

ArpController::ArpController() {
}


ArpController::ArpController(EtherController* ether_controller) {
    this->ether_controller = ether_controller;
}


ArpController::~ArpController() {
}

// 生成一个 ARP Announcement 报文
// 返回值：返回一个 arp 报文
ArpPacket* ArpController::arp_make_announcement() {
    ArpPacket* arp_packet = new ArpPacket();
    arp_packet->spawn_announcement_packet();
    return arp_packet;
}


// 生成一个 ARP Response 报文
// 参数：接收到的 request 报文
// 返回值：返回一个 ARP 报文
ArpPacket* ArpController::arp_make_response(ArpPacket* arp_packet) {
    ArpPacket* arp_response_packet = new ArpPacket();
    arp_response_packet->spawn_reply_packet(arp_packet);
    return arp_response_packet;
}


void ArpController::arp_in(ArpPacket* arp_packet) {
    printf("[ArpController] Received an arp_packet.\n");
    arp_packet->print();
    // arp_packet.
    uint16_t opcode = arp_packet->get_opcode();
    switch (opcode) {
        case XARP_REQUEST: {
            printf("[ArpController] Analyzing an arp request packet..\n");
            ArpPacket* response_arp_packet = arp_make_response(arp_packet);
            arp_out(response_arp_packet);
            break;
        }
        case XARP_REPLY: {

            break;
        }
    }
}


void ArpController::arp_out(ArpPacket* arp_packet) {
    Ether* ether_packet = new Ether(arp_packet, arp_packet->get_target_mac(), XNET_PROTOCOL_ARP);
    ether_controller->ethernet_out_to(ether_packet);
}