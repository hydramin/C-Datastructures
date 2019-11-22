CC = gcc
CFlags = -c -Wall

all: hashtable

hashtable: main.o hashtable.o
	$(CC) ./bin/main.o ./bin/hashtable.o -L ../doubly_linkedlist_map/bin -lmydllmap -o ./bin/hashtable.exe
	# source:  https://randu.org/tutorials/c/libraries.php , https://www.youtube.com/watch?v=JU-vwvSH_0g
main.o: main.c
	$(CC) $(CFlags) main.c -o ./bin/main.o
hashtable.o: hashtable.c
	$(CC) $(CFlags) hashtable.c -o ./bin/hashtable.o