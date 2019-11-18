# declare variables
CC = gcc
CFlags = -c -Wall

all: bintree	

bintree: main.o bintree.o
	$(CC) ./bin/main.o ./bin/bintree.o -o ./bin/bintree.exe

main.o: main.c
	$(CC) $(CFlags) main.c -o ./bin/main.o

bintree.o: bintree.c
	$(CC) $(CFlags) bintree.c -o ./bin/bintree.o