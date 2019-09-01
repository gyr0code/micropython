#include "udpsend.h"
/************************************************************
 * UDP SEND PAYLOAD
 * Send a payload to port 9000 through UDP
************************************************************/

void mp_init_udp(udp_send_obj_t *UDP){

    UDP->pcb = udp_new();
    
    UDP->port = 9000;
    
    IP4_ADDR(&UDP->destip,192,168,4,16);

}


void mp_send_udp(struct udp_pcb *udppcb ,const u8_t *payload, ip_addr_t *dest_ip, u16_t port, const int payloadsize){

    struct pbuf *p;

    p = pbuf_alloc(PBUF_TRANSPORT, payloadsize, PBUF_RAM);

    pbuf_take(p, (char*)payload , payloadsize);

    udp_sendto(udppcb, p, dest_ip, port);

    pbuf_free(p);

}