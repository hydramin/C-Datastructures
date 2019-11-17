# declare variables
CC = gcc
CFlags = -c -Wall

all: dlinkedlist	

dlinkedlist: main.o dlinkedlist.o
	$(CC) ./bin/main.o ./bin/dlinkedlist.o -o ./bin/dlinkedlist

main.o: main.c
	$(CC) $(CFlags) main.c -o ./bin/main.o

dlinkedlist.o: dlinkedlist.c
	$(CC) $(CFlags) dlinkedlist.c -o ./bin/dlinkedlist.o