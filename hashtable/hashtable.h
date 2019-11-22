#include "../doubly_linkedlist_map/dllmap.h"

#define MAX_TABLE_SIZE 100

// int hashFunc(char * input);
struct hashtable * initHashtable();
void insert(struct hashtable *, char *, char *);
void prtHashTable(struct hashtable * );

struct hashtable {
    // char * data[10];
    struct listNodes * data[MAX_TABLE_SIZE];
    int size;    
};