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
    xnet_packet_t* net_packet;

    bool aborted;
    uint16_t header_size;


    void set_aborted(bool op);

    // Header Operations
    void add_header(uint16_t header_size);
    void remove_header();

    void set_header_size(uint16_t header_size);
    uint16_t get_header_size();

    void get_header();


public:
    Packet(/* args */);
    Packet(uint16_t data_size);
    ~Packet();

    bool is_aborted();

    void alloc_packet(uint16_t data_size);
    

    uint8_t* get_data();

    void set_size(uint16_t size);
    uint16_t get_size();
};



#endif