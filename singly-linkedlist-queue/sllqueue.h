
#include <stdio.h>
#include <stdlib.h>
#include "../linkedlist/linkedlist.h"

typedef struct queue {
    struct node_t * queue;
    int count;
} Queue;

Queue * initQueue();
void enqueue(Queue * , char * );
char * dequeue(Queue * );
void prtQueue(Queue * );