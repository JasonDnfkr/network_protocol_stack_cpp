#ifndef __PACKET_H__
#define __PACKET_H__

#include <network/Config.h>

#include <cstdint>

/**
 * @brief 用于从 pcap 驱动里收发网卡接收到的 Ether 数据包
 * 
 */
class Packet {
protected:
    // 数据包
    xnet_packet_t* net_packet;

    // bool 判断这个数据包是否无效
    bool aborted;

    // uint16_t 数据包的 header 字节数
    uint16_t header_size;

    // ------ 函数 -------

    // 设置数据包的状态，是否废弃
    void set_aborted(bool op);

    /* -- Header Operations --  */ 
    // 设置 header 的字节数
    void set_header_size(uint16_t header_size);

    // 提取 header 的数据结构及内容至 hdr 中
    virtual void spawn_header();

    // 用于构造函数初始化的函数
    // 功能：1. 复制网络数据包 (net_packet)
    //       2. 复制 aborted 状态
    void init_constructor(const Packet* packet, uint16_t xhdr_size);


public:
    Packet(/* args */);
    Packet(uint16_t data_size);
    Packet(uint16_t data_size, uint8_t flag);
    Packet(const Packet* packet);

    ~Packet();

    // xnet_alloc_for_read(uint16_t data_size)
    // static Packet* alloc_for_read(uint16_t data_size);

    // bool 返回该数据包是否无效
    bool is_aborted();

    // void alloc_packet(uint16_t data_size);
    
    // uint8_t* 返回数据包开头的指针 (包括 header)
    uint8_t* get_data();

    // 设置数据包的大小 (包括 header 的大小)
    void set_size(uint16_t size);

    // uint16_t 返回数据包的大小 (包括 header 的大小)
    uint16_t get_size();

    // 缩减数据包的大小：将 header 的字节数移除出数据包
    void remove_header();

    // 扩增数据包的大小：将 header 的字节数添加进数据包
    void add_header(uint16_t header_size);
    
    // 返回 header 的字节数
    uint16_t get_header_size();


    uint8_t* debug_get_payload_ptr() {
        return net_packet->payload;
    }
};



#endif