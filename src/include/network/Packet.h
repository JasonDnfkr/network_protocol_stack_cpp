#ifndef __PACKET_H__
#define __PACKET_H__

#include <cstdint>
#include <vector>

// Ether 包最大字节数：1516
#define XNET_CFG_PACKET_MAX_SIZE        1516
// MAC 地址长度
#define XNET_MAC_ADDR_SIZE              6



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

    // Ether ether;


public:
    Packet(/* args */);
    Packet(uint16_t data_size);
    ~Packet();

    void alloc_packet(uint16_t data_size);
    
    // void alloc_rx_packet(uint16_t data_size);

    uint8_t* get_data();

    void set_size(uint16_t size);
    uint16_t get_size();
};



#endif