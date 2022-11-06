#include <network/Driver.h>
#include <network/Ether.h>
#include <network/EtherController.h>

#include <cstring>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

Driver::Driver() {
    ip_str = src_ip;
    my_mac_addr = src_mac_addr;
    // memcpy(ip_str, src_ip, sizeof(src_ip));
    
    // my_mac_addr = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66 };
    // my_mac_addr = (char*)malloc(sizeof(uint8_t) * 6);
    // my_mac_addr[0] = 0x11;
    // my_mac_addr[1] = 0x22;
    // my_mac_addr[2] = 0x33;
    // my_mac_addr[3] = 0x44;
    // my_mac_addr[4] = 0x55;
    // my_mac_addr[5] = 0x66;

    printf("%s\n", ip_str);

    for (int i = 0; i < 6; i++) {
        printf("%x ", my_mac_addr[i]);
    }

    ether_controller = new EtherController();
    ether_controller->driver = this;
}


Driver::~Driver() { }

void Driver::driver_open() {
    pcap = pcap_device_open(ip_str, (uint8_t*)my_mac_addr, 1);
    if (pcap == (pcap_t*) 0) {
        exit(-1);
    }
}


// 初始化
void Driver::driver_init() {
    ether_controller->ethernet_init();
}


void Driver::driver_send(Packet* packet) {
    // pcap
    pcap_device_send(pcap, packet->get_data(), packet->get_size());
}


 // 从 npcap 驱动程序中读取数据包，
 // 数据从数组第 0 个字节开始正序存放
 // 
 // 返回：标准的 Packet* 类返回值
Packet* Driver::driver_read() {
    uint16_t size;
    Packet* packet = new Packet(XNET_CFG_PACKET_MAX_SIZE);
    // packet->alloc_packet(XNET_CFG_PACKET_MAX_SIZE);
    size = pcap_device_read(pcap, packet->get_data(), XNET_CFG_PACKET_MAX_SIZE);
    if (size) {
        packet->set_size(size);
        return packet;
    }
    
    delete packet;
    return (Packet*) 0;
}


// 从驱动代码中查询是否接收到了 packet，
// 有则接收，并转换为 Ether* 形式
// 然后传入 ether_controller 内，从 ether 控制器
// 进行协议的向上分发。
// ether_controller->ethernet_in(packet)
void Driver::poll() {
    Packet* packet;

    packet = driver_read();
    if (packet) {
        // ethernet_in(packet);
        Ether* ether_packet = new Ether((Ether*)packet);
        delete packet;
        ether_controller->ethernet_in(ether_packet);
    }
}