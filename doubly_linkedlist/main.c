#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

int main(int argc, char const *argv[])
{
    struct listNodes * list;
    list = initDLL();
    
    // printf("Amin Adam 2\n");
    // printf("%s\n", list->head->data);
    // char *names[6] = {"Amin", "Afu", "Nadia", "Genet", "Milky", "Mahmoud" };

    // for (int i = 0; i < 6; i++){
    //     // insertLast(list, *(names+i));
    //     insertFirst(list, *(names+i));
    // }
    // printf("%s %s %d main\n", list->head->data, list->tail->data, list->size);
    char *ints[] = {"0","1","2","3","4","5","6","7","8","9","10",};

    for (int i = 0; i <= 10; i++){
        if(i % 2) {
            // printf("%s\n", *(ints+i));
            insertFirst(list, *(ints+i));
            
        } else {
            // printf("%s\n", *(ints+i));            
            insertLast(list, *(ints+i));
        }
    }

    prtList(list);
    freeMem(list);

    // printf("-%s- -%s- -%d- main\n", list->head->data, list->tail->data, list->size);    

    return 0;
}
