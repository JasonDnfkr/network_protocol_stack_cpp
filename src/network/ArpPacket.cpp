#include <network/ArpPacket.h>


void ArpPacket::get_header() {
    hdr = (xarp_hdr_t*)get_data();
    if (get_size() <= get_header_size()) {
        set_aborted(true);
        return;
    }
}

ArpPacket::ArpPacket() {  }


ArpPacket::ArpPacket(const ArpPacket* packet) {
    
}