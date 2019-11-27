#include "sllqueue.h"

Queue * initQueue();

Queue * initQueue() {
    Queue * q = malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Queue not initialized!\n");
        return;
    }
    
    q->queue = initSLL();
    q->count = 0;
    return q;
}

void enqueue(Queue * q, char * value) {
    insertLast(q->queue, value);
    q->count = count(q->queue);
}

char * dequeue(Queue * q) {
    if (q->count > 0)
    {
        return removeHead(q->queue)->data;
        q->count = count(q->queue);        
    }    
    return NULL;
}

void prtQueue(Queue * q) {
    prtList(q->queue);
}

