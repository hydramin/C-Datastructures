#include <stdio.h>
#include <stdlib.h>
#include "dllmap.h"

int main(int argc, char const *argv[])
{
    struct listNodes * list;
    list = initDLL();
    
    char * keys[] = {"gple","m4ki","q04e","0m4j","0n3c","qwer","ghjk","zxcv","ergb","poiu","mnbv"};
    char * values[] = {"Amin","Milky","Afuye","Nadoo","Riyad","John","Mother","Buster","Eater","Ford","Dood"};

    for (int i = 0; i <= 10; i++){        
        insertFirst(list, *(keys+i), *(values+i));
    }

    prtList(list);
    // freeMem(list);

    // printf("-%s- -%s- -%d- main\n", list->head->data, list->tail->data, list->size);    

    return 0;
}
