#declare variables to reuse
CC=gcc
CFlags=-c -Wall
C_LIB = ar rcs

# this target is done first by default
all: linkedlist
	
linkedlist: main.o linkedlist.o
	$(CC) ./bin/main.o ./bin/linkedlist.o -o ./bin/linkedlist
main.o: main.c
	$(CC) $(CFlags) main.c -o ./bin/main.o
linkedlist.o: linkedlist.c 
	$(CC) $(CFlags) linkedlist.c -o ./bin/linkedlist.o
	$(C_LIB) ./bin/libmysll.a ./bin/linkedlist.o
