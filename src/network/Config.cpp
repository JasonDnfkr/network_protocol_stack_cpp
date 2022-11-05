#include <network/Config.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>

const char *src_ip = "192.168.254.1";
const char src_mac_addr[6] = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66 };


xnet_packet_t::_xnet_packet_t() {
    size = 0;
    data = 0;
    memset(payload, 0, XNET_CFG_PACKET_MAX_SIZE);
}

// Constructor:
// 将 data 指针指向 payload 相应的位置
xnet_packet_t::_xnet_packet_t(uint16_t data_size) {
    memset(payload, 0, XNET_CFG_PACKET_MAX_SIZE);
    data = payload + XNET_CFG_PACKET_MAX_SIZE - data_size;
    size = data_size;
}


xnet_packet_t::_xnet_packet_t(const _xnet_packet_t* net_packet) {
    size = net_packet->size;
    memcpy(payload, net_packet->payload, XNET_CFG_PACKET_MAX_SIZE);
    data = payload + XNET_CFG_PACKET_MAX_SIZE - size;
}


xnet_packet_t::~_xnet_packet_t() {
    // free(payload);
    // printf("Destructor");
}