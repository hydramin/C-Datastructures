# declare variables
CC = gcc
CFlags = -c -Wall
C_LIB = ar rcs


all: dlinkedlist	

dlinkedlist: main.o dlinkedlist.o
	$(CC) ./bin/main.o ./bin/dlinkedlist.o -o ./bin/dlinkedlist	

main.o: main.c
	$(CC) $(CFlags) main.c -o ./bin/main.o

dlinkedlist.o: dlinkedlist.c
	$(CC) $(CFlags) dlinkedlist.c -o ./bin/dlinkedlist.o
	#creates library of the doubly linked list from the compiled source
	$(C_LIB) ./bin/libmydll.a ./bin/dlinkedlist.o