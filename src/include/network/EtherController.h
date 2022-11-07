#ifndef __ETHERCONTROLLER_H__
#define __ETHERCONTROLLER_H__

// #include <network/ArpController.h>
#include <network/Ether.h>

class Driver;

class ArpController;

class EtherController {
private:
    ArpController* arp_controller;


    // 构造函数初始化
    void init();
    

public:
    Driver* driver;

    EtherController();
    EtherController(Driver* driver);
    ~EtherController();

    // 协议栈软件初始化
    void ethernet_init();

    // 接收最底层的 Packet* 数据包
    void ethernet_in(Ether* ether_packet);

    // 发送数据包
    void ethernet_out_to(Ether* ether_packet);

    // 发送
};



#endif