#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(int argc, char const *argv[])
{
    struct hashtable * hashtbl = initHashtable();

    char *names[] = {"Amin", "Afiye", "Nadia", "Milky", "Mahmoud", "Genet", 
                    "Masho", "Sada", "Kamu", "Brook", "Dog"};

    char *jobs[] = {"Programmer", "Dental Hyginist", "Baby", "Programmer", 
                    "Software Architect", "Nurse", "Grand Mother", "Journalist",
                    "Business woman", "Taxi Driver", "Guard"};

    int p = 11;

    for (int i = 0; i < p; i++)
    {        
        insert(hashtbl, *(names+i), *(jobs+i));    
    }
    

    // printf("-> %d\n", hashtbl->size);
    prtHashTable(hashtbl);

    return 0;
}
