#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <cstdint>

#define swap_order16(v)   ((((v) & 0xff) << 8) | (((v) >> 8) & 0xff))


// Ether 包最大字节数：1516
#define XNET_CFG_PACKET_MAX_SIZE        1516
// MAC 地址长度
#define XNET_MAC_ADDR_SIZE              6


typedef struct _xnet_packet_t {
    uint16_t size;
    uint8_t* data;
    uint8_t payload[XNET_CFG_PACKET_MAX_SIZE];
} xnet_packet_t;

typedef enum _xnet_err_t {
    XNET_ERR_OK = 0,
    XNET_ERR_IO = -1,
} xnet_err_t;

typedef enum _xnet_protocol_t {
    XNET_PROTOCOL_ARP = 0x0806,     // ARP协议
    XNET_PROTOCOL_IP  = 0x0800,      // IP协议
} xnet_protocol_t;

#endif