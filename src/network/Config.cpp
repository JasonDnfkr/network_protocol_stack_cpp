#include <network/Config.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>

const char *src_ip = "192.168.254.1";
const char src_mac_addr[6] = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66 };
const xipaddr_t netif_ipaddr = XNET_CFG_NETIF_IP;
const uint8_t netif_mac[6] = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66 };
const uint8_t ether_broadcast[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };


xnet_packet_t::_xnet_packet_t() {
    size = 0;
    data = 0;
    memset(payload, 0, XNET_CFG_PACKET_MAX_SIZE);
}

// Constructor:
// 生成一个大小为 data_size 的数据包
// 将 data 指针指向 payload 相应的位置
xnet_packet_t::_xnet_packet_t(uint16_t data_size) {
    memset(payload, 0, XNET_CFG_PACKET_MAX_SIZE);
    data = payload + XNET_CFG_PACKET_MAX_SIZE - data_size;
    size = data_size;
}

// Constructor:
// 获取从网络上接收到的数据包
xnet_packet_t::_xnet_packet_t(const _xnet_packet_t* net_packet) {
    memset(payload, 0, XNET_CFG_PACKET_MAX_SIZE);
    size = net_packet->size;
    memcpy(payload, net_packet->payload, XNET_CFG_PACKET_MAX_SIZE);
    data = payload + (net_packet->data - net_packet->payload);
}


xnet_packet_t::~_xnet_packet_t() {
    // free(payload);
    // printf("Destructor");
}


std::string str_mac_addr(uint8_t* mac_addr) {
    char tmp[18];
    sprintf(tmp, "%02x:%02x:%02x:%02x:%02x:%02x", mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    return tmp;
}

std::string str_ip_addr(uint8_t* ip_addr) {
    char tmp[16];
    sprintf(tmp, "%d.%d.%d.%d", ip_addr[0], ip_addr[1], ip_addr[2], ip_addr[3]);
    return tmp;
}