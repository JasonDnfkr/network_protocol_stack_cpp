#ifndef __PACKET_H__
#define __PACKET_H__

#include <network/Config.h>

#include <cstdint>
#include <vector>


/**
 * @brief 用于从 pcap 驱动里收发网卡接收到的 Ether 数据包
 * 
 */
class Packet {
protected:
    typedef struct _xnet_packet_t {
        uint16_t size;
        uint8_t* data;
        uint8_t payload[XNET_CFG_PACKET_MAX_SIZE];
    } xnet_packet_t;

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
    
    // void alloc_rx_packet(uint16_t data_size);

    uint8_t* get_data();
    // uint8_t* set_data(uint16_t )

    void set_size(uint16_t size);
    uint16_t get_size();
};



#endif