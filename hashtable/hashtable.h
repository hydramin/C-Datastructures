#include "../doubly_linkedlist/dlinkedlist.h"

#define MAX_TABLE_SIZE 1019

// int hashFunc(char * input);
struct hashtable * initHashtable();
void insert(struct hashtable *, char *);
void prtHashTable(struct hashtable * );

struct hashtable {
    // char * data[10];
    struct listNodes * data[MAX_TABLE_SIZE];
    int size;    
};