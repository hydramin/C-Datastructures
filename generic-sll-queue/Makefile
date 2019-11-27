#declare variables to reuse
CC=gcc
CFlags=-c -Wall
C_LIB = ar rcs

# this target is done first by default
all: gsllqueue
	
gsllqueue: main.o gsllqueue.o
	$(CC) ./bin/main.o ./bin/gsllqueue.o -L ../generic_linkedlist/bin -lgsll -o ./bin/gsllqueue.exe 
main.o: main.c
	$(CC) $(CFlags) main.c -o ./bin/main.o
gsllqueue.o: gsllqueue.c 
	$(CC) $(CFlags) gsllqueue.c -o ./bin/gsllqueue.o
	$(C_LIB) ./bin/libgsllqueue.a ./bin/gsllqueue.o
