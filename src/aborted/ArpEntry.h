#ifndef __ARPENTRY_H__
#define __ARPENTRY_H__

#include <network/Config.h>


/*

typedef struct _xarp_entry_t {
    xipaddr_t ip_addr;                       // ip 地址
    uint8_t   mac_addr[XNET_MAC_ADDR_SIZE];  // mac 地址
    uint8_t   state;                         // 状态位
    uint16_t  tmo;                           // 当前剩余时间
    uint8_t   retry_cnt;                     // 当前重试次数
} _xarp_entry_t;

*/

class ArpEntry {
private:
    xipaddr_t ip_addr;                       // ip 地址
    uint8_t   mac_addr[XNET_MAC_ADDR_SIZE];  // mac 地址
    uint8_t   state;                         // 状态位
    uint16_t  tmo;                           // 当前剩余时间
    uint8_t   retry_cnt;                     // 当前重试次数

public:
    ArpEntry();
    ~ArpEntry();

    void update(const uint8_t* ipaddr);
};



#endif