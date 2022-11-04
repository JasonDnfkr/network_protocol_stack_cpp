#ifndef __ETHER_H__
#define __ETHER_H__

#include <network/Packet.h>

#include <cstdint>

class Ether : public Packet {
private:
    typedef struct _xether_hdr_t {
        uint8_t dest[XNET_MAC_ADDR_SIZE];           // 目标mac地址
        uint8_t src[XNET_MAC_ADDR_SIZE];            // 源mac地址
        uint16_t protocol;                          // 协议/长度
    } xether_hdr_t;


};

#endif