#ifndef __ARPTABLE_H__
#define __ARPTABLE_H__

#include <network/ArpPacket.h>
#include <vector>

#define X_ARP_TABLE_MAX_SIZE         5

class ArpTable {
private:
    

    

    // 获取系统时间戳
    xnet_time_t sys_get_time();

    void constructor_init();


public:
    ArpTable();
    ~ArpTable();

    // ARP Table poll
    void arp_table_poll();

    

};



#endif