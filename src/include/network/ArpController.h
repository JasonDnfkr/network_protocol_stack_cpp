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

    // 生成一个 arp 请求包 (request)
    // 参数：发送方的 ip 地址
    // 返回值：返回一个 ArpPacket* arp 报文
    ArpPacket* arp_make_request(const xipaddr_t* ipaddr);
    
};



#endif