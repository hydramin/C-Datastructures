#include "gsllqueue.h"

typedef struct point
{
    int x;
    int y;    
} Point;

typedef struct rect
{
    Point * p1;
    Point * p2;
} Rectangle;


void prtQueueCB(Point * pt) {
    printf("(%d, %d) --> ", pt->x, pt->y);
}

void prtRectQ_CB(Rectangle * r) {
    Point * p1 = r->p1;
    Point * p2 = r->p2;
    printf(" p1(%d, %d) -- p2(%d, %d) \n", p1->x, p1->y, p2->x, p2->y);
}

int main(int argc, char const *argv[])
{   
    Queue * pq = initQueue();
    Queue * pqr = initQueue();

    // points

    Point p1, p2, p3, p4, p5;    
    p1.x = 1; p1.y = 2;
    p2.x = 2; p2.y = 3;
    p3.x = 3; p3.y = 4;
    p4.x = 4; p4.y = 5;
    p5.x = 5; p5.y = 6;

    Rectangle r1, r2, r3;

    r1 = (Rectangle){&p1, &p2};    
    r2 = (Rectangle){&p2, &p4};
    r3 = (Rectangle){&p3, &p5};
    
    enqueue(pq, &p1);
    enqueue(pq, &p2);
    enqueue(pq, &p3);
    enqueue(pq, &p4);
    enqueue(pq, &p5);

    enqueue(pqr, &r1);
    enqueue(pqr, &r2);
    enqueue(pqr, &r3);



    printf("<><><><><><><><><><><><><><><><><><><><><><><><>\n");
    Point * pp1 = dequeue(pq);
    printf("%d %d\n", pp1->x, pp1->y);
    printf("<><><><><><><><><><><><><><><><><><><><><><><><>\n");
    prtQueue(pq, &prtQueueCB);
    printf("<><><><><><><><><><><><><><><><><><><><><><><><>\n");
    prtQueue(pqr, &prtRectQ_CB);
    

    // enqueue(q, "Amin");
    // prtQueue(q);
    // enqueue(q, "Afia");
    // prtQueue(q);
    // enqueue(q, "Nadia");
    // prtQueue(q);
    // enqueue(q, "Genet");
    // prtQueue(q);
    // enqueue(q, "Milky");
    // prtQueue(q);
    // enqueue(q, "Mahmoud");
    // prtQueue(q);

    // dequeue(q);
    // prtQueue(q);
    // dequeue(q);
    // prtQueue(q);
    // dequeue(q);
    // prtQueue(q);
    // dequeue(q);
    // prtQueue(q);
    // dequeue(q);
    // prtQueue(q);
    // dequeue(q);
    // prtQueue(q);


    return 0;
}
