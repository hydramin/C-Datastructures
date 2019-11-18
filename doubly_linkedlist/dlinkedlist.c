#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

struct node_t * newNode() {
    struct node_t * node;
    node = (struct node_t *) malloc(sizeof(struct node_t));
    if(node == NULL) {
        printf("new node not created!\n");
        return;
    }
    node->data = "Nadia";
    node->after = NULL;
    node->before = NULL;
    return node;
}

struct listNodes * initDLL() {
    struct node_t * node = newNode();
    struct listNodes * list;    
    list = (struct listNodes *) malloc(sizeof(struct listNodes));    
    list->head = node;
    list->tail = node;
    printf("%s <<< Init\n", list->head->data);
    return list;        
}


void insertLast(struct listNodes * list, char * data) {
    // printf("%s <<< insertLast\n", list->head->data);
    // struct node_t * tail = list->tail;
    // struct node_t * head = list->head;

    struct node_t * node = newNode();
    if (list->head == list->tail && list->size == 0)
    {        
        // Add the first element
        list->tail->data = data;
        list->size += 1;
    } else {
        //add to the tail
        node->data = data;
        list->tail->after = node;
        node->before = list->tail;
        list->tail = node;
        list->size += 1;
    }
}

void insertFirst(struct listNodes * list, char * data) {
    // printf("%s <<< insertLast\n", list->head->data);
    // struct node_t * tail = list->tail;
    // struct node_t * head = list->head;

    struct node_t * node = newNode();
    if (list->head == list->tail && list->size == 0)
    {        
        // Add the first element
        list->head->data = data;
        list->size += 1;
    } else {
        //add to the tail
        node->data = data;
        list->head->before = node;
        node->after = list->head;
        list->head = node;
        list->size += 1;
    }
}

void prtList(struct listNodes * list) {
    struct node_t * node_i = list->head;
    for ( ; node_i != NULL; node_i = node_i->after)
    {
        printf("-> %s ", node_i->data);
    }    
    printf("\n");
}


void freeNodes(struct node_t * node) {
    if (node == NULL) {
        return;
    }
    freeNodes(node->after);
    // printf("free -> %s\n",node->data);
    free(node);    
}

void freeMem(struct listNodes * list) {
    freeNodes(list->head);
    list->size = 0;
    // printf("-%s- -%s- -%d- list top\n", list->head->data, list->tail->data, list->size);
    free(list->tail);
    free(list);
    // printf("-%s- -%s- -%d- list\n", list->head->data, list->tail->data, list->size);
}




