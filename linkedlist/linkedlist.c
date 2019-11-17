#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

struct node_t *getLastNode(struct node_t *node) {
    struct node_t * node_i = node;
    for ( node_i ; node_i->next != NULL; node_i = node_i->next);
    return node_i;    
}

struct node_t * init() {

    struct node_t *node;
    node = malloc(sizeof(struct node_t));
    if (node == NULL)
    {
        printf("node is not initiallized!\n");
    }    
    node->data = NULL;
    node->next = NULL;
    return node;
}

void insert(struct node_t * node, char *value) {
    struct node_t * last = getLastNode(node);
    
    if (last->data == NULL)
    {
        //its the first uninitialized node
        last->data = value;
    } else
    {
        last->next = init();
        last->next->data = value;
    }    
}


void prtList(struct node_t * node) {
    for ( struct node_t * node_i = node; node_i != NULL; node_i = node_i->next){
        printf("%s ", node_i->data);
    }
    printf("\n");
}
