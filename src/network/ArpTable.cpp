#include <network/ArpTable.h>
#include <network/ArpController.h>
#include <cstring>
#include <ctime>

void ArpTable::constructor_init() {
}


ArpTable::ArpTable() {
    constructor_init();
}


ArpTable::~ArpTable() {
}



xnet_time_t ArpTable::sys_get_time() {
    return clock() / CLOCKS_PER_SEC;
}



void ArpTable::arp_table_poll() {
    
}