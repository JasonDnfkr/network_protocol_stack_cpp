#include <network/Packet.h>
#include <cstring>
#include <cstdlib>

Packet::Packet(/* args */) {
    net_packet = (xnet_packet_t*) malloc(sizeof(xnet_packet_t));
    memset(net_packet, 0, sizeof(net_packet));
    // memset(&rx_packet, 0, sizeof(rx_packet));
}

// Overload 1
Packet::Packet(uint16_t data_size) {
    net_packet = (xnet_packet_t*) malloc(sizeof(xnet_packet_t));
    memset(net_packet, 0, sizeof(net_packet));
    // memset(&rx_packet, 0, sizeof(rx_packet));
    net_packet->data = net_packet->payload + XNET_CFG_PACKET_MAX_SIZE - data_size;
    net_packet->size = data_size;
}


Packet::~Packet() {
}

void Packet::alloc_packet(uint16_t data_size) {
    net_packet->data = net_packet->payload + XNET_CFG_PACKET_MAX_SIZE - data_size;
    net_packet->size = data_size;
}
    

uint8_t* Packet::get_data() {
    return net_packet->data;
}

uint16_t Packet::get_size() {
    return net_packet->size;
}

void Packet::set_size(uint16_t size) {
    net_packet->size = size;
}