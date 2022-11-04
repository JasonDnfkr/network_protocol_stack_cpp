#include <network/Driver.h>

#include <cstring>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

Driver::Driver() {
    char tmp_ip[] = "192.168.254.1";
    ip_str = (char*)malloc(sizeof(tmp_ip));
    memcpy(ip_str, tmp_ip, sizeof(tmp_ip));
    
    // my_mac_addr = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66 };
    my_mac_addr = (char*)malloc(sizeof(uint8_t) * 6);
    my_mac_addr[0] = 0x11;
    my_mac_addr[1] = 0x22;
    my_mac_addr[2] = 0x33;
    my_mac_addr[3] = 0x44;
    my_mac_addr[4] = 0x55;
    my_mac_addr[5] = 0x66;

    printf("%s\n", tmp_ip);

    for (int i = 0; i < 6; i++) {
        printf("%x ", my_mac_addr[i]);
    }
}


Driver::~Driver() { }

void Driver::driver_open() {
    pcap = pcap_device_open(ip_str, (uint8_t*)my_mac_addr, 1);
    if (pcap == (pcap_t*) 0) {
        exit(-1);
    }
}


void Driver::driver_send(Packet* packet) {
    // pcap
    pcap_device_send(pcap, packet->get_data(), packet->get_size());
}


Packet* Driver::driver_read() {
    uint16_t size;
    Packet* packet = new Packet(XNET_CFG_PACKET_MAX_SIZE);
    // packet->alloc_packet(XNET_CFG_PACKET_MAX_SIZE);
    size = pcap_device_read(pcap, packet->get_data(), XNET_CFG_PACKET_MAX_SIZE);
    if (size) {
        packet->set_size(size);
        return packet;
    }
    return (Packet*) 0;
}


void Driver::ethernet_poll() {
    Packet* packet;

    packet = driver_read();
    if (packet) {
        ethernet_in(packet);
    }
}


void Driver::ethernet_in(Packet* packet) {
    printf("driver: ethernet in!\n");
    // if (packet->get_size() <= sizeo)
    
}