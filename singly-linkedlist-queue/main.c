#include "sllqueue.h"

int main(int argc, char const *argv[])
{   
    Queue * q = initQueue();

    enqueue(q, "Amin");
    prtQueue(q);
    enqueue(q, "Afia");
    prtQueue(q);
    enqueue(q, "Nadia");
    prtQueue(q);
    enqueue(q, "Genet");
    prtQueue(q);
    enqueue(q, "Milky");
    prtQueue(q);
    enqueue(q, "Mahmoud");
    prtQueue(q);

    dequeue(q);
    prtQueue(q);
    dequeue(q);
    prtQueue(q);
    dequeue(q);
    prtQueue(q);
    dequeue(q);
    prtQueue(q);
    dequeue(q);
    prtQueue(q);
    dequeue(q);
    prtQueue(q);


    return 0;
}
