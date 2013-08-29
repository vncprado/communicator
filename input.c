/*
    Funções de entrada de comandos.
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

#include "communicator.h"
#include "input.h"

char *get_command() {
    /* Recebe uma string (ex: 1;f#) via socket e a retorna. */
    
    int sockfd,n;
    char mesg[10];
    struct sockaddr_in servaddr,cliaddr;
    socklen_t len;

    sockfd=socket(AF_INET,SOCK_DGRAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(SOCKET_PORT);
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    len = sizeof(cliaddr);
    n = recvfrom(sockfd, mesg, 10, 0, (struct sockaddr *)&cliaddr, &len);
    mesg[n] = 0;
    close(sockfd);

    return mesg;
}

