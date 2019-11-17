#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
// #include "../doubly_linkedlist/dlinkedlist.h"

int hashFunc(char * str) {
    char c = *str;
    int i = 1, sum = 0;
    
    while (c != '\0')
    {
        sum += c;
        // printf("%d\n", c);
        c = *(str+i);
        i++;       
    }    
    // printf("%d\n", sum);
    return sum % 10;
}

struct hashtable * initHashtable() {
    struct hashtable * table = malloc(sizeof(struct hashtable));
    if (table == NULL)
    {
        printf("Hashtable not allocated\n");
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        table->data[i] = initDLL();
    }
    table->size = 0;   
    
    return table;
}

void insert(struct hashtable * table, char * str) {
    int index = hashFunc(str);
    // printf("index -> %d\n", index);
    insertLast( ((table->data)[index]), str);
    table->size += 1; 
}

void prtHashTable(struct hashtable * table) {
    for (int i = 0; i < 10; i++)
    {
        if(table->data[i]->size) {
            // printf("index -> %d , count -> %d\n", i, table->data[i]->size);
            prtList(table->data[i]);
        }
    }
    
}