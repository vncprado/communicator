/*
    Fuções de protocolo.
    A ideia é passar para o robô um caractere ascii único que represente seu id e comando a executar

    Dessa forma usaremos a tabela ascii começando em !

    id|cmd|dec |cha
    1 | f | 33 | !
    1 | t | 34 | "
    1 | e | 35 | #
    1 | d | 36 | $

    2 | f | 37 | %
    2 | t | 38 | &
    2 | e | 39 | '
    2 | d | 40 | (

    3 | f | 41 | )
    3 | t | 42 | *
    3 | e | 43 | +
    3 | d | 44 | ,
*/

#include "protocol.h"

int cmd2dec(int *msg){
    /*
    Função que converte um vetor contendo [id_robo, comando]
    no valor ASCII do caracter seguindo a tabela:

    robo | comando | dec | ASCII | HASH
     1   |   f     | 33  |  !    | 102 
     1   |   t     | 34  |  "    | 116 
     1   |   e     | 35  |  #    | 101 
     1   |   d     | 36  |  $    | 100 
     
     2   |   f     | 37  |  %    | 204 
     2   |   t     | 38  |  &    | 232 
     2   |   e     | 39  |  '    | 202 
     2   |   d     | 40  |  (    | 200 

     3   |   f     | 41  |  )    | 306 
     3   |   t     | 42  |  *    | 348 
     3   |   e     | 43  |  +    | 303 
     3   |   d     | 44  |  ,    | 300 

    A última coluna funciona como o valor de uma tabela hash sendo apenas a multiplicação: id_robo*commando
    ex:

    1 * f(102) = 102
    2 * f(102) = 204
    3 * f(102) = 304

    Dessa forma a tradução é direta sem necessidade de busca em matriz.
    */
    
    switch ( msg[0]*msg[1] ) {
        case 102: return 33; 
        case 116: return 34; 
        case 101: return 35; 
        case 100: return 36; 

        case 204: return 37; 
        case 232: return 38; 
        case 202: return 39; 
        case 200: return 40; 

        case 306: return 41; 
        case 348: return 42; 
        case 303: return 43; 
        case 300: return 44; 
        
        case 000: return 00;
    }
}

int *split (char *msg){
    /*
    Função que recebe a string,
    separa id e comando em um vetor,
    verifica se termina com o caracter #
    caso negativo retorna [0, 0]
    */
    
    int data[2]={0, 0};

    if (msg[3]!='#'){
        return data;
    }
    data[0]=msg[0]-'0';
    data[1]=msg[2];

    return data;
}


