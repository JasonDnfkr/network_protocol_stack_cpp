#include <network/ArpController.h>

ArpController::ArpController(/* args */) {
}


ArpController::~ArpController() {
}


void arp_make_request(const xipaddr_t* ipaddr) {
    ArpPacket* arp_packet = new ArpPacket();
}



void arp_in(Ether* ether_packet) {

}
