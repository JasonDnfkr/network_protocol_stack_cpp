#ifndef __DRIVER_H__
#define __DRIVER_H__

#include <network/Config.h>
#include <pcap_device.h>
#include <network/Packet.h>

class Driver {
private:
    char* ip_str;
    char* my_mac_addr;
    pcap_t* pcap;

    void ethernet_in(Packet* packet);
    

public:
    Driver(/* args */);
    ~Driver();

    void driver_open();
    void driver_send(Packet* packet);
    Packet* driver_read();

    void ethernet_poll();
    
};




#endif