#ifndef __ARPPACKET_H__
#define __ARPPACKET_H__

#include <network/Config.h>
#include <network/Ether.h>

#include <cstdint>

#define XARP_HW_ETHER       0x1

// ARP header - opcode: request(0x1)
#define XARP_REQUEST        0x1
// ARP header - opcode: reply(0x2)
#define XARP_REPLY          0x2

class ArpPacket : public Ether {
private:
    #pragma pack(1)
    typedef struct _xarp_hdr_t {
        uint16_t    hardware_type;
        uint16_t    protocol_type;
        uint8_t     hardware_length;
        uint8_t     protocol_length;
        uint16_t    opcode;
        uint8_t     sender_mac[XNET_MAC_ADDR_SIZE];
        uint8_t     sender_ip[XNET_IPV4_ADDR_SIZE];
        uint8_t     target_mac[XNET_MAC_ADDR_SIZE];
        uint8_t     target_ip[XNET_IPV4_ADDR_SIZE];
    } xarp_hdr_t;
    #pragma pack()

    xarp_hdr_t* hdr;

protected:
    // 提取 header 的数据结构及内容至 hdr 中
    void spawn_header();


public:
    ArpPacket();
    ArpPacket(const ArpPacket* ether_packet);
    ~ArpPacket();

    // 构建一个 arp 请求报文。
    // 参数：sender_ip
    // 包内构建，无返回值
    void spawn_request_packet(const xipaddr_t* ipaddr);

    uint16_t get_protocol();

    // 展示报文信息
    void print();
};



#endif