#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct point
{
    int x;
    int y;
};

int getX(struct point *pt) {
    return pt->x;
}

int getY(struct point *pt) {
    return pt->y;
}

struct point * newPt(int x, int y) {
    struct point *pt;
    pt = malloc(sizeof(struct point));  
    pt->x = 5;
    pt->y = 8;
    return pt;
}

int main(int argc, char const *argv[])
{
    // struct point p1 = {2,3}, *pp;
    // pp = &p1;
    // struct point *p2 = newPt(2,3);
    // printf("%d, %d\n", getX(p2), getY(p2));

    struct node_t *node;
    node = init();
    char *names[5] = {"Amin", "Afu", "Nadia", "Genet", "Milky", "Mahmoud" };

    for (int i = 0; i < 5; i++)
    {
        char * temp = *(names+i);        
        insert(node, temp);
    }    

    prtList(node);

    return 0;
}
