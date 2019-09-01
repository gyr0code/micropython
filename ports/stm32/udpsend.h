#include <stdio.h>
#include <string.h>
#include "lwip/timeouts.h"
#include "lwip/init.h"
#include "lwip/udp.h"

// STRUCT FOR STORING INFO
typedef struct _udp_send_obj_t {
        
    struct udp_pcb *pcb;
    
    err_t errorstate;
    
    ip_addr_t destip;
    
    u16_t port;

} udp_send_obj_t;

void mp_init_udp(udp_send_obj_t *UDP);

void mp_send_udp(struct udp_pcb *udppcb ,const u8_t *payload, ip_addr_t *dest_ip, u16_t port, const int payloadsize);