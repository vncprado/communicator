communicator
============

Software de conexão socket para serial para a equipe de futebol de robôs do SIR_LAB.
Inclui um protocolo de comunicação com os robôs simplificado.

Programa que lê comandos enviados por um socket e converte este segundo um protocolo e envia um caracter ASCII por serial.
A ideia é passar para os robôs um caractere ASCII único que represente seu id e comando a executar.
Funciona para 3 robôs (1, 2, 3).

O programa recebe comandos no formato:

    id_robo;comando#
    
Ex:
    
    1;f#
    
Os comandos utilizados foram:

    f (frente), t (trás), e (esquerda), d (direita)

Foram utilizados caracteres da tabela ASCII começando em !

    | id|cmd| dec|cha|
    |----------------|
    | 1 | f | 33 | ! |
    | 1 | t | 34 | " |
    | 1 | e | 35 | # |
    | 1 | d | 36 | $ |
    |----------------|
    | 2 | f | 37 | % |
    | 2 | t | 38 | & |
    | 2 | e | 39 | ' |
    | 2 | d | 40 | ( |
    |----------------|
    | 3 | f | 41 | ) |
    | 3 | t | 42 | * |
    | 3 | e | 43 | + |
    | 3 | d | 44 | , |

O software traduz a string enviada por socket (ex: 1;f#) para o referente caracter da tabela na função cmd2dec em protocolo.c
Nesta função o valor da multiplicação entre id*comando (ex: 1*f(102)=102, 2*f(102)=204, ...) é utilizado tal qual numa tabela HASH
para definir o valor a ser atribuído. Pode parecer confuso mas é mais simples do que parece rs.

No projeto ainda existe um arquivo source.c que emula a fonte de dados e é compilado conjuntamente.
Este programa pode ser utilizado como base para o desenvolvimento da origem dos dados reais ou para testes de comunicação.

Para compilar:

    $ chmod +x compila.sh
    $ ./compila.sh

Para rodar:

    $ ./source
    $ ./communicator


Att,
Vinícius Prado, vncprado@gmail.com



