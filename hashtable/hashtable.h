#include "../doubly_linkedlist/dlinkedlist.h"

// int hashFunc(char * input);
struct hashtable * initHashtable();
void insert(struct hashtable *, char *);
void prtHashTable(struct hashtable * );

struct hashtable {
    // char * data[10];
    struct listNodes * data[10];
    int size;    
};