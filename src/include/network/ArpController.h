#ifndef __ARPCONTROLLER_H__
#define __ARPCONTROLLER_H__

#include <network/ArpPacket.h>
#include <network/ArpEntry.h>
#include <network/ArpTable.h>

class EtherController;

class ArpController {
private:
    EtherController* ether_controller;
    ArpTable* arp_table;

    ArpPacket* arp_out();


public:
    ArpController();
    ArpController(EtherController* ether_controller);
    ~ArpController();

    // 接收 Ether* ether_packet
    void arp_in(ArpPacket* arp_packet);

    // 发送一个 ArpPacket* arp_packet
    void arp_out(ArpPacket* arp_packet);

    // 生成一个 ARP Announcement 报文
    // 返回值：返回一个 ARP 报文
    ArpPacket* arp_make_announcement();
    
    // 生成一个 ARP Response 报文
    // 参数：接收到的 request 报文
    // 返回值：返回一个 ARP 报文
    ArpPacket* arp_make_response(ArpPacket* arp_packet);
};



#endif