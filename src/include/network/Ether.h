#ifndef __ETHER_H__
#define __ETHER_H__

// #include <network/Config.h>
#include <network/Packet.h>
// #include <network/ArpPacket.h>

#include <cstdint>

class Ether : public Packet {
private:
    typedef struct _xether_hdr_t {
        uint8_t dest_mac[XNET_MAC_ADDR_SIZE];           // 目标mac地址
        uint8_t src_mac[XNET_MAC_ADDR_SIZE];            // 源mac地址
        uint16_t protocol;                          // 协议/长度
    } xether_hdr_t;

    xether_hdr_t* hdr;

protected:
    // 提取 header 的数据结构及内容至 hdr 中
    virtual void spawn_header();
    
    
public:
    Ether();
    Ether(const Ether* packet);
    Ether(const Ether* arp_packet, const uint8_t* mac_addr, xnet_protocol_t protocol);
    ~Ether();

    uint16_t get_protocol();

};

#endif