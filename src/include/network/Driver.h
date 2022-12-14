#ifndef __DRIVER_H__
#define __DRIVER_H__

#include <pcap_device.h>

#include <network/Config.h>
#include <network/Packet.h>

class EtherController;

class Driver {
private:
    const char* ip_str;
    const char* my_mac_addr;
    pcap_t* pcap;

    EtherController* ether_controller;
    

public:
    Driver(/* args */);
    ~Driver();

    // 驱动代码：打开 npcap 网卡
    void driver_open();

    // 初始化
    void driver_init();

        // 驱动代码：发送数据包
    void driver_send(Packet* packet);

    // 驱动代码：从 npcap 接收数据包
    Packet* driver_read();

    void poll();
};




#endif