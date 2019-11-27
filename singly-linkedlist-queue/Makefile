#declare variables to reuse
CC=gcc
CFlags=-c -Wall
C_LIB = ar rcs

# this target is done first by default
all: sllqueue
	
sllqueue: main.o sllqueue.o
	$(CC) ./bin/main.o ./bin/sllqueue.o -L ../linkedlist/bin -lmysll -o ./bin/sllqueue.exe 
main.o: main.c
	$(CC) $(CFlags) main.c -o ./bin/main.o
sllqueue.o: sllqueue.c 
	$(CC) $(CFlags) sllqueue.c -o ./bin/sllqueue.o
	$(C_LIB) ./bin/libsllqueue.a ./bin/sllqueue.o
