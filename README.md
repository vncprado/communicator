communicator
============

Connection software socket/serial for the SIR_LAB Very Small Size robot soccer team. This software includes a simplified robot communication protocol.

Commands to robots are read from a socket and translate by a protocol and sends a ASCII character by serial. The main idea is send to robot only one ASCII that represents their ID and a command to execute. This version works with 3 robots.

Commands are received in the following format:

    id_robo;comando#
    
Ex:
    
    1;f#
    
basic commands is:

    f (foward), t (backward), e (left), d (rigth)

The following characters ASCII used starting with !

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

The software translate a string sent by socket (ex: 1;f#) to the ASCII character in the function cmd2dec in the file protocolo.c. In this function the value of multipling id*command (ex: 1*f(102)=102, 2*f(102)=204, ...) is used like a HASH table to define the valeu to be atributed. It is not as confusing as it sems lol.

In the project exists a file source.c witch emulates the source of data. It is compiled together. This software can be used as a base for source of data in communication tests.

Compile:

    $ chmod +x compila.sh
    $ ./compila.sh

Run:

    $ ./source
    $ ./communicator


Sincerly,
Vinícius Prado, vncprado@gmail.com



