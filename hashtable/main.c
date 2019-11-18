#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(int argc, char const *argv[])
{
    struct hashtable * hashtbl = initHashtable();

    char *names[] = {"Amin", "Afiye", "Nadia", "Milky", "Mahmoud", "Genet", "Masho", "Sada", "Kamu", "Brook", "Dog"};

    int p = 11;

    for (int i = 0; i < p; i++)
    {        
        insert(hashtbl, *(names+i));    
    }
    

    // printf("-> %d\n", hashtbl->size);
    prtHashTable(hashtbl);

    return 0;
}
