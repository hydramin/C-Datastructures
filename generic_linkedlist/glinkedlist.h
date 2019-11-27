#include <stdio.h>
#include <stdlib.h>

struct node_t {
    void * data;
    struct node_t * next;
};

struct node_t * initSLL();
void insertLast(struct node_t * node, char *value);
void insertFirst(struct node_t * node, char *value);
void prtList(struct node_t * , void (*prtCallback)(void *));
int count(struct node_t * list);
void * getByIndex(struct node_t * list, int index);
struct node_t * removeHead(struct node_t * head);
