/*
    Exemplo de fonte de comandos para o robô seguindo protocolo simples
    Apenas para testar o socket, a origem poderá ser de qualquer tipo
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

#include "communicator.h"

int main(int argc, char**argv)
{
   int sockfd,n;
   struct sockaddr_in servaddr,cliaddr;
   char *sendline=TST_DATA;

   sockfd=socket(AF_INET,SOCK_DGRAM,0);

   bzero(&servaddr,sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=inet_addr(SOCKET_IP);
   servaddr.sin_port=htons(SOCKET_PORT);

   for(;;)
   {
      sendto(sockfd,sendline,strlen(sendline),0,
             (struct sockaddr *)&servaddr,sizeof(servaddr));
   }
}
