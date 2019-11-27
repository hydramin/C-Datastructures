#include "glinkedlist.h"

int main(int argc, char const *argv[])
{   
    struct node_t * nodeL;//, * nodeF;
    nodeL = initSLL();
    // nodeF = initSLL();
    char *names[] = {"Amin", "Afu", "Nadia", "Genet", "Milky", "Mahmoud" };

    for (int i = 0; i < 6; i++)
    {
        char * temp = *(names+i);        
        insertLast(nodeL, temp);
        // insertFirst(nodeF, temp);
    }    

    // prtList(nodeL);
    
    // printf("count = %d\n", count(nodeL));
    // prtList(nodeF);
    // printf("count = %d\n", count(nodeF));
    // int index = 0;
    // removeHead(nodeF);
    // removeHead(nodeF);
    // removeHead(nodeF);
    // removeHead(nodeF);
    // removeHead(nodeF);
    // removeHead(nodeF);
    // removeHead(nodeF);
    // removeHead(nodeF);
    // printf("index %d, value %s\n", index, getByIndex(nodeF, index));

    return 0;
}
