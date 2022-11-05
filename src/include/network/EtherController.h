#ifndef __ETHERCONTROLLER_H__
#define __ETHERCONTROLLER_H__

#include <network/Config.h>
#include <network/ArpController.h>
#include <network/Packet.h>
#include <network/Ether.h>

class EtherController {
private:
    ArpController* arp_controller;


    // 构造函数初始化
    void init();
    

public:
    EtherController();
    ~EtherController();

    // 接收最底层的 Packet* 数据包
    void ethernet_in(Ether* ether_packet);

    // 发送
};



#endif