#ifndef __ARPCONTROLLER_H__
#define __ARPCONTROLLER_H__

#include <network/Config.h>
#include <network/Ether.h>
#include <network/ArpPacket.h>
#include <network/ArpEntry.h>
#include <network/ArpTable.h>

class ArpController {
private:
    ArpTable* arp_table;

    ArpPacket* arp_out();


public:
    ArpController();
    ~ArpController();

    // 接收 Ether* ether_packet
    void arp_in(ArpPacket* arp_packet);

    // 发送 arp 包
    // 参数：ip 地址
    void arp_make_request(const xipaddr_t* ipaddr);
    
};



#endif