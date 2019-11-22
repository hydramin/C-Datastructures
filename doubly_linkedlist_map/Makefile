# declare variables
CC = gcc
CFlags = -c -Wall
C_LIB = ar rcs


all: dllmap	

dllmap: main.o dllmap.o
	$(CC) ./bin/main.o ./bin/dllmap.o -o ./bin/dllmap.exe

main.o: main.c
	$(CC) $(CFlags) main.c -o ./bin/main.o

dllmap.o: dllmap.c
	$(CC) $(CFlags) dllmap.c -o ./bin/dllmap.o
	#creates library of the doubly linked list from the compiled source
	$(C_LIB) ./bin/libmydllmap.a ./bin/dllmap.o