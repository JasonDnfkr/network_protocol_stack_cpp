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

    // 构建一个 arp announcement 报文
    // 包内构建，无返回值
    void spawn_announcement_packet();

    // 构建一个 arp 请求报文 (request)
    // 参数：请求的 ip 地址
    // 包内构建，无返回值
    void spawn_request_packet(const xipaddr_t* ipaddr);

    // 构建一个 arp 响应报文 (reply)
    // 参数：需要回应的 ARP 报文
    // 包内构建，无返回值
    void spawn_reply_packet(ArpPacket* dest_arp_packet);

    uint16_t get_protocol();

    // 报文自检，若检测到错误，则 aborted = true
    void check();

    // 展示报文信息
    void print();

    // 获取操作码 uint16_t
    inline uint16_t get_opcode() { return swap_order16(hdr->opcode); } 

    // 获取 sender_ip
    inline uint8_t* get_sender_ip() { return hdr->sender_ip; }

    // 获取 sender_mac
    inline uint8_t* get_sender_mac() { return hdr->sender_mac; }

    // 获取 target_ip
    inline uint8_t* get_target_ip() { return hdr->target_ip; }

    // 获取 target_mac
    inline uint8_t* get_target_mac() { return hdr->target_mac; }
};

#endif