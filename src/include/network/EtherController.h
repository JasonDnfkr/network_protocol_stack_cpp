#ifndef __ETHERCONTROLLER_H__
#define __ETHERCONTROLLER_H__

#include <network/Config.h>
#include <network/ArpController.h>
#include <network/ArpPacket.h>
#include <network/Packet.h>
#include <network/Ether.h>

class Driver;

class EtherController {
private:
    ArpController* arp_controller;


    // 构造函数初始化
    void init();
    

public:
    Driver* driver;

    EtherController();
    // EtherController(Driver* driver);
    ~EtherController();

    // 协议栈软件初始化
    void ethernet_init();

    // 接收最底层的 Packet* 数据包
    void ethernet_in(Ether* ether_packet);

    // 从上层接收数据包，封装 xether 报头，并发送
    void ethernet_out_to(const Ether* ether_packet, const uint8_t* mac_addr, xnet_protocol_t protocol);

    // 发送
};



#endif