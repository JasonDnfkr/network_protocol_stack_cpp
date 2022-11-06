#include <network/ArpController.h>

#include <cstdio>

ArpController::ArpController(/* args */) {
}


ArpController::~ArpController() {
}

// 生成一个 arp 请求包 (request)
// 参数：发送方的 ip 地址
// 返回值：返回一个 arp 报文
ArpPacket* ArpController::arp_make_request(const xipaddr_t* ipaddr) {
    ArpPacket* arp_packet = new ArpPacket();
    arp_packet->spawn_request_packet(ipaddr);
    return arp_packet;
}



void ArpController::arp_in(ArpPacket* arp_packet) {
    printf("ArpController: recv arp_packet.\n");
    arp_packet->print();
    // arp_packet.
}
