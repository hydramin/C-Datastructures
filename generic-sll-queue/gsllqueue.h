#include "../generic_linkedlist/glinkedlist.h"

typedef struct queue {
    struct node_t * queue;
    int count;
} Queue;

Queue * initQueue();
void enqueue(Queue * , void * );
void * dequeue(Queue * );
void prtQueue(Queue * , void (*prtCallback)(void *));