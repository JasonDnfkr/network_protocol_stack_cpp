#ifndef __ETHER_H__
#define __ETHER_H__

#include <network/Packet.h>

#include <cstdint>

class Ether : public Packet {
private:
    typedef struct _xether_hdr_t {
        uint8_t dest_mac[XNET_MAC_ADDR_SIZE];           // 目标mac地址
        uint8_t src_mac[XNET_MAC_ADDR_SIZE];            // 源mac地址
        uint16_t protocol;                              // 协议/长度
    } xether_hdr_t;

    xether_hdr_t* hdr;

protected:
    // 提取 header 的数据结构及内容至 hdr 中
    virtual void spawn_header();
    
    
public:
    Ether();
    Ether(const Ether* packet);
    Ether(const Ether* arp_packet, const uint8_t* dest_mac_addr, xnet_protocol_t protocol);
    ~Ether();

    // 更新 Ether 数据包
    void update_ether_header(const uint8_t* dest_mac, const uint8_t* src_mac, xnet_protocol_t protocol);

    uint16_t get_protocol();

};

#endif