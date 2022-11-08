#ifndef __ARPCONTROLLER_H__
#define __ARPCONTROLLER_H__

#include <network/ArpPacket.h>
#include <network/ArpTable.h>

// ARP 表项空闲
#define XARP_ENTRY_FREE         0

// ARP 表解析成功
#define XARP_ENTRY_OK           1

// ARP 表正在解析
#define XARP_ENTRY_RESOLVING    2

// ARP 表扫描周期
#define XARP_TIMER_PERIOD       1   // 单位：秒

// ARP 表项超时时间
#define XARP_CFG_ENTRY_TMO      5

// ARP表挂起时重试查询次数
#define XARP_CFG_MAX_RETRIES    4                   


class EtherController;

class ArpController {
private:
    EtherController* ether_controller;
    ArpTable* arp_table;

    void constructor_init();


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