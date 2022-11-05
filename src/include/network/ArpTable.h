#ifndef __ARPTABLE_H__
#define __ARPTABLE_H__

#include <network/ArpEntry.h>
#include <vector>

#define X_ARP_TABLE_MAX_SIZE         5

class ArpTable {
private:
    std::vector<ArpEntry*> arp_table;

    void init();


public:
    ArpTable();
    ~ArpTable();


};



#endif