#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <cstdint>


// 2字节大小端转换
#define swap_order16(v)   ((((v) & 0xff) << 8) | (((v) >> 8) & 0xff))


// Ether 包最大字节数：1516
#define XNET_CFG_PACKET_MAX_SIZE        1516
// 本软件协议栈的虚拟网卡 IP
#define XNET_CFG_NETIF_IP               { 192, 168, 254, 2 } 
// MAC 地址长度
#define XNET_MAC_ADDR_SIZE              6
// IP 地址长度
#define XNET_IPV4_ADDR_SIZE             4


// typedef struct _xnet_packet_t xnet_packet_t;


// 最底层的以太网数据包结构
typedef struct _xnet_packet_t {
    uint16_t size;
    uint8_t* data;
    uint8_t payload[XNET_CFG_PACKET_MAX_SIZE];

    _xnet_packet_t();
    _xnet_packet_t(uint16_t data_size);
    _xnet_packet_t(const _xnet_packet_t* net_packet);
    ~_xnet_packet_t();
} xnet_packet_t;

// 错误码
typedef enum _xnet_err_t {
    XNET_ERR_OK = 0,
    XNET_ERR_IO = -1,
} xnet_err_t;

// 协议
// ARP = 0x0806
// IP  = 0x0800
typedef enum _xnet_protocol_t {
    XNET_PROTOCOL_ARP = 0x0806,     // ARP协议
    XNET_PROTOCOL_IP  = 0x0800,      // IP协议
} xnet_protocol_t;


// ip 地址结构
typedef union _xiaddr_t {
    uint8_t     array[XNET_IPV4_ADDR_SIZE];
    uint32_t    addr;
} xipaddr_t;


typedef struct _xarp_entry_t {
    xipaddr_t ip_addr;                       // ip 地址
    uint8_t   mac_addr[XNET_MAC_ADDR_SIZE];  // mac 地址
    uint8_t   state;                         // 状态位
    uint16_t  tmo;                           // 当前剩余时间
    uint8_t   retry_cnt;                     // 当前重试次数
} _xarp_entry_t;




// 本地物理机器的 ip，使用该 ip 将数据包发出
extern const char* src_ip;
//
extern const char src_mac_addr[];
// 本软件虚拟网卡的 ip，后续使用这个 ip 通信
extern const xipaddr_t netif_ipaddr;
// mac 广播地址
extern const uint8_t ether_broadcast[];



#endif