#include <network/ArpEntry.h>
#include <cstring>

ArpEntry::ArpEntry() {
    ip_addr.addr = 0;
    memset(mac_addr, 0, XNET_MAC_ADDR_SIZE);
    state = XARP_ENTRY_FREE;
    tmo = 0;
    retry_cnt = 0;
}

ArpEntry::~ArpEntry() {
}