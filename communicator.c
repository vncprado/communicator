/*
    Programa que lê um socket, converte a mensagem de acordo com o protocolo e envia por serial
*/

#include <stdio.h>

#include "communicator.h"
#include "protocol.h"
#include "input.h"
#include "output.h"

int main () {
    char *socket_msg;
    int *splitted;
    int to_serial;

    for (;;) {
        // Recebe uma mensagem por socket ex: 1;f#
        socket_msg=get_command();
        // Corta a parte interessante da mensagem em um vetor: [id_robô, comando]
        splitted=split(socket_msg);
        // Transforma o vetor em um valor decimal/char para ser enviado ao robô
        to_serial=cmd2dec(splitted);
        // Envia por serial e verificando se ocorreu erro
        if (send_command(to_serial)<0) {
            return -1;
        }
    }
}

