#declare variables to reuse
CC=gcc
CFlags=-c -Wall

# this target is done first by default
all: linkedlist
	
linkedlist: main.o linkedlist.o
	CC main.o linkedlist.o -o ./bin/linkedlist

main.o: main.c
	CC CFlags main.c
linkedlist.o: linkedlist.c
	CC CFlags linkedlist.c