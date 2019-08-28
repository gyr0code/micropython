#include <stdio.h>
#include <string.h>
#include "lwip/timeouts.h"
#include "lwip/init.h"
#include "lwip/udp.h"

// STRUCT FOR STORING INFO
typedef struct _udp_send_obj_t {
        
    struct udp_pcb *pcb;
    
    err_t errorstate;
    
    ip4_addr_t destip;
    
    u16_t port;

    char ipstring[];

} udp_send_obj_t;

void mp_init_udp(udp_send_obj_t *UDP);

err_t mp_send_udp(struct udp_pcb *udppcb ,const u16_t *payload, ip_addr_t *dest_ip, u16_t port, u16_t payloadsize);