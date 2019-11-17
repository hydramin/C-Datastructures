#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(int argc, char const *argv[])
{
    struct hashtable * hashtbl = initHashtable();

    insert(hashtbl, "qwer");
    insert(hashtbl, "asdf");
    insert(hashtbl, "qqqq");
    insert(hashtbl, "dddd");
    insert(hashtbl, "1111");
    insert(hashtbl, "222");
    insert(hashtbl, "33333");
    insert(hashtbl, "3456");
    insert(hashtbl, "sdfgsdf");
    insert(hashtbl, "bv");
    insert(hashtbl, "bbbb");

    printf("-> %d\n", hashtbl->size);
    prtHashTable(hashtbl);

    return 0;
}
