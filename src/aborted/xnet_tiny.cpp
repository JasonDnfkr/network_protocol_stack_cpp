#include <network/xnet_tiny.h>

#include <cstring>
#include <cstdio>

static xnet_packet_t tx_packet;
static xnet_packet_t rx_packet;

#define min(a, b) ((a) > (b) ? (b) : (a))

static uint8_t netif_mac[XNET_MAC_ADDR_SIZE];                   // mac地址

#define swap_order16(v)   ((((v) & 0xFF) << 8) | (((v) >> 8) & 0xFF))

xnet_packet_t* xnet_alloc_for_send(uint16_t data_size) {
    tx_packet.data = tx_packet.payload + XNET_CFG_PACKET_MAX_SIZE - data_size;
    tx_packet.size = data_size;
    return &tx_packet;
}


xnet_packet_t* xnet_alloc_for_read(uint16_t data_size) {
    rx_packet.data = rx_packet.payload;
    rx_packet.size = data_size;
    return &rx_packet;
}


static void add_header(xnet_packet_t* packet, uint16_t header_size) {
    packet->data -= header_size;
    packet->size += header_size;
}


static void remove_header(xnet_packet_t* packet, uint16_t header_size) {
    packet->data += header_size;
    packet->size -= header_size;
}


static void truncate_packet(xnet_packet_t* packet, uint16_t size) {
    packet->size = min(packet->size, size);
}

/**
 * 以太网初始化
 * @return 初始化结果
 */
static xnet_err_t ethernet_init (void) {
    xnet_err_t err = xnet_driver_open(netif_mac);
    if (err < 0) return err;

    return XNET_ERR_OK;
}

/**
 * 发送一个以太网数据帧
 * @param protocol 上层数据协议，IP或ARP
 * @param mac_addr 目标网卡的mac地址
 * @param packet 待发送的数据包
 * @return 发送结果
 */
static xnet_err_t ethernet_out_to(xnet_protocol_t protocol, const uint8_t *mac_addr, xnet_packet_t * packet) {
    xether_hdr_t* ether_hdr;

    // 添加头部
    add_header(packet, sizeof(xether_hdr_t));
    ether_hdr = (xether_hdr_t*)packet->data;
    memcpy(ether_hdr->dest, mac_addr, XNET_MAC_ADDR_SIZE);
    memcpy(ether_hdr->src, netif_mac, XNET_MAC_ADDR_SIZE);
    ether_hdr->protocol = swap_order16(protocol);

    // 数据发送
    return xnet_driver_send(packet);
}


static void ethernet_in (xnet_packet_t * packet) {
    printf("ethernet in!\n");
    // 至少要比头部数据大
    if (packet->size <= sizeof(xether_hdr_t)) {
        return;
    }

    // 往上分解到各个协议处理
    xether_hdr_t* hdr = (xether_hdr_t*)packet->data;
    switch (swap_order16(hdr->protocol)) {
        case XNET_PROTOCOL_ARP:
            break;
        case XNET_PROTOCOL_IP: {
            break;
        }
    }
}

/**
 * 查询网络接口，看看是否有数据包，有则进行处理
 */
static void ethernet_poll (void) {
    xnet_packet_t * packet;

    if (xnet_driver_read(&packet) == XNET_ERR_OK) {
        // 正常情况下，在此打个断点，全速运行
        // 然后在对方端ping 192.168.254.2，会停在这里
        ethernet_in(packet);
    }
}

/**
 * 协议栈的初始化
 */
void xnet_init (void) {
    ethernet_init();
}

/**
 * 轮询处理数据包，并在协议栈中处理
 */
void xnet_poll(void) {
    ethernet_poll();
}
