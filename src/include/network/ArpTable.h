#ifndef __ARPTABLE_H__
#define __ARPTABLE_H__

#include <network/ArpPacket.h>
#include <vector>

#define X_ARP_TABLE_MAX_SIZE         5

class ArpTable {
private:
    typedef struct xarp_entry_t {
        xipaddr_t ip_addr;                       // ip 地址
        uint8_t   mac_addr[XNET_MAC_ADDR_SIZE];  // mac 地址
        uint8_t   state;                         // 状态位
        uint16_t  tmo;                           // 当前剩余时间
        uint8_t   retry_cnt;                     // 当前重试次数
        xnet_time_t arp_timer;                   // 计时器

        xarp_entry_t();

        xarp_entry_t(uint8_t* src_ip, uint8_t* mac_addr);

        // 判断 arp 计时器是否超时
        bool check_tmo(uint32_t sec);
        
    } xarp_entry_t;

    // ARP 表项 vector
    std::vector<xarp_entry_t*> arp_entries;

    // 获取系统时间戳
    xnet_time_t sys_get_time();

    void constructor_init();


public:
    ArpTable();
    ~ArpTable();

    // ARP Table poll
    void arp_table_poll();

    //
    void update(ArpPacket* arp_packet);

};



#endif