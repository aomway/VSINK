#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>   //      gettimeofday
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>



int init_tx_port(int port, struct sockaddr_in *paddr)
{
    int socket_descriptor;
    bzero(paddr,sizeof(struct sockaddr_in));
    paddr->sin_family=AF_INET;
    paddr->sin_addr.s_addr=inet_addr("192.168.1.1");
    paddr->sin_port=htons(port);

    socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);//IPV4
    return socket_descriptor;
}

int init_rx_port(int port, struct sockaddr_in *paddr)
{
    int socket_descriptor;
    bzero(paddr,sizeof(struct sockaddr_in));
    paddr->sin_family=AF_INET;
    paddr->sin_addr.s_addr=htonl(INADDR_ANY);
    paddr->sin_port=htons(port);

    socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);//IPV4
    if (bind(socket_descriptor, (struct sockaddr *)paddr, sizeof(struct sockaddr)) < 0)
    {
        perror("bind failed...\r\n");
        exit(1);
    }
    return socket_descriptor;
}
