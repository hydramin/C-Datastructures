#declare variables to reuse
CC=gcc
CFlags=-c -Wall
C_LIB = ar rcs

# this target is done first by default
all: glinkedlist
	
glinkedlist: main.o glinkedlist.o
	$(CC) ./bin/main.o ./bin/glinkedlist.o -o ./bin/glinkedlist.exe
main.o: main.c
	$(CC) $(CFlags) main.c -o ./bin/main.o
glinkedlist.o: glinkedlist.c 
	$(CC) $(CFlags) glinkedlist.c -o ./bin/glinkedlist.o
	$(C_LIB) ./bin/libgsll.a ./bin/glinkedlist.o
