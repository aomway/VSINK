#ifndef UDP_UTIL_H
#define UDP_UTIL_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


int init_rx_port(int port, struct sockaddr_in *paddr);
int init_tx_port(int port, struct sockaddr_in *paddr);

#endif


