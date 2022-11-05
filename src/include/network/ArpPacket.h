#ifndef __ARPPACKET_H__
#define __ARPPACKET_H__

#include <network/Config.h>
#include <network/Packet.h>

#include <cstdint>

class ArpPacket : public Packet {
private:
    typedef struct _xarp_hdr_t {
        uint16_t    hardware_type;
        uint16_t    protocol_type;
        uint16_t    opcode;
        uint8_t     sender_mac[XNET_MAC_ADDR_SIZE];
        uint8_t     sender_ip[XNET_IPV4_ADDR_SIZE];
        uint8_t     target_mac[XNET_MAC_ADDR_SIZE];
        uint8_t     target_ip[XNET_IPV4_ADDR_SIZE];
    } xarp_hdr_t;

    xarp_hdr_t* hdr;

protected:
    void get_header();


public:
    ArpPacket();
    ArpPacket(const ArpPacket* packet);
    ~ArpPacket();

    uint16_t get_protocol();
};



#endif