#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
// #include "../doubly_linkedlist/dlinkedlist.h"

long hashFunc(char * str) {
    char c = *str;
    int i = 1;
    long sum = 0;
    
    while (c != '\0')
    {
        sum += c;
        // printf("%d\n", c);
        c = *(str+i);
        i++;       
    }    
    sum = (sum*sum + 10067)*10037;
    // printf("%ld\n", sum);
    return sum % MAX_TABLE_SIZE;
}

struct hashtable * initHashtable() {
    struct hashtable * table = malloc(sizeof(struct hashtable));
    if (table == NULL)
    {
        printf("Hashtable not allocated\n");
        return;
    }

    for (int i = 0; i < MAX_TABLE_SIZE; i++)
    {
        table->data[i] = initDLL();
    }
    table->size = 0;   
    
    return table;
}

void insert(struct hashtable * table, char * key, char * value) {
    int index = hashFunc(key);
    printf("key => %s  index -> %d\n", key, index);
    insertLast( ((table->data)[index]), key, value);
    // table->size += 1; 
}

void prtHashTable(struct hashtable * table) {
    for (int i = 0; i < MAX_TABLE_SIZE; i++)
    {
        if(table->data[i]->size) {
            // printf("index -> %d , count -> %d\n", i, table->data[i]->size);
            prtList(table->data[i]);
        }
    }   
}

// void searchHashTable(struct hashtable * table, char * term)