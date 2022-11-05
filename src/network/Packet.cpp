#include <network/Packet.h>
#include <cstring>
#include <cstdlib>

Packet::Packet() {
    net_packet = new xnet_packet_t();

    aborted = false;
    header_size = 0;
}


// Overload 1
Packet::Packet(uint16_t data_size) {
    net_packet = new xnet_packet_t(data_size);
    
    aborted = false;
    header_size = 0;
}


Packet::~Packet() {
    delete net_packet;
}


// void Packet::alloc_packet(uint16_t data_size) {
//     net_packet->data = net_packet->payload + XNET_CFG_PACKET_MAX_SIZE - data_size;
//     net_packet->size = data_size;
// }


void Packet::add_header(uint16_t new_header_size) {
    net_packet->data -= new_header_size;
    net_packet->size += new_header_size;
}
    

void Packet::remove_header() {
    net_packet->data += header_size;
    net_packet->size -= header_size;
}


void Packet::set_header_size(uint16_t header_size) {
    this->header_size = header_size;
    // if (net_packet->data == net_packet->payload + XNET_CFG_PACKET_MAX_SIZE) {

    // }
}


uint16_t Packet::get_header_size() {
    return header_size;
}


void Packet::recv_header() {  }


void Packet::set_aborted(bool op) {
    aborted = op;
}


bool Packet::is_aborted() {
    return aborted;
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