#
#   Script para compilar o projeto
#

gcc source.c -o source -w
gcc -c protocol.c -w
gcc -c input.c -w
gcc -c output.c -w
gcc -c communicator.c -w
gcc -o communicator communicator.o input.o output.o protocol.o -w

