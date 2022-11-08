#ifndef __ARPCONTROLLER_H__
#define __ARPCONTROLLER_H__

#include <network/ArpPacket.h>
#include <network/ArpTable.h>

// ARP 表项空闲
#define XARP_ENTRY_FREE            0

// ARP 表解析成功
#define XARP_ENTRY_OK              1

// ARP 表正在解析
#define XARP_ENTRY_RESOLVING       4

// ARP 表扫描周期
#define XARP_TIMER_PERIOD          1   // 单位：秒

// ARP 表项超时时间
#define XARP_CFG_ENTRY_TMO         8

// ARP表项挂起超时时间
#define XARP_CFG_ENTRY_PENDING_TMO 4         

// ARP表挂起时重试查询次数
#define XARP_CFG_MAX_RETRIES       4               


/**
 * 有些内容需要重新调整：
 * arp announcement：src_ip 和 dest_ip 相同，src_mac 是本机 mac，dest_mac 是 0。Ethernet 报文的 mac 是广播地址
 * 并不是每一个 arp 报文，最后都要在以太网层发送广播地址
 * 比如超时重传，就可以点对点地确认信息，如果没有回应则再发送广播地址
 * 
 */


class EtherController;

class ArpController {
private:
    typedef struct xarp_entry_t {
        xipaddr_t ip_addr;                       // ip 地址
        uint8_t   mac_addr[XNET_MAC_ADDR_SIZE];  // mac 地址
        uint8_t   state;                         // 状态位
        uint16_t  tmo;                           // 当前剩余时间
        uint8_t   retry_cnt;                     // 当前重试次数
        xnet_time_t arp_timer;                   // 计时器

        xarp_entry_t();

        xarp_entry_t(uint8_t* src_ip, uint8_t* mac_addr);

        // 判断 arp 计时器是否超时
        bool check_tmo(uint32_t sec);
        
    } xarp_entry_t;

    EtherController* ether_controller;
    // ArpTable* arp_table;

    // ARP 表项 vector
    std::vector<xarp_entry_t*> arp_entries;

    void constructor_init();

    // 更新 ARP 表
    void arp_entries_update(ArpPacket* arp_packet);


public:
    ArpController();
    ArpController(EtherController* ether_controller);
    
    ~ArpController();

    // 接收 Ether* ether_packet
    void arp_in(ArpPacket* arp_packet);

    // 发送一个 ArpPacket* arp_packet, 目的 mac 是该 arp_packet 的 mac 地址
    void arp_out(ArpPacket* arp_packet);

    // 发送一个 ArpPacket* arp_packet, 目的 mac 是第二个参数
    void arp_out(ArpPacket* arp_packet, const uint8_t* dest_mac_addr);

    // 生成一个 ARP Announcement 报文
    // 返回值：返回一个 ARP 报文
    ArpPacket* arp_make_announcement();
    
    // 生成一个 ARP Response 报文
    // 参数：接收到的 request 报文
    // 返回值：返回一个 ARP 报文
    ArpPacket* arp_make_response(ArpPacket* arp_packet);

    // 生成一个 ARP Request 报文，
    // 请求指定 IP 的主机，返回一个 ARP 响应报文
    // 参数：所需请求的 IP 地址
    // 返回值：返回一个 ARP 报文
    ArpPacket* arp_make_request(const xipaddr_t* ipaddr);

    // ARP poll
    void arp_entries_poll();
};



#endif