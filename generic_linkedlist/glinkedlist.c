#include "glinkedlist.h"

struct node_t *getLastNode(struct node_t *node) {
    struct node_t * node_i = node;
    for ( node_i ; node_i->next != NULL; node_i = node_i->next);
    return node_i;    
}

struct node_t * initSLL() {

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

void insertLast(struct node_t * node, char *value) {
    struct node_t * last = getLastNode(node);
    
    if (last->data == NULL)
    {
        //its the first uninitialized node
        last->data = value;
    } else
    {
        last->next = initSLL();
        last->next->data = value;
    }    
}

void insertFirst(struct node_t * node, char *value) {
    
    if (node->data == NULL)
    {
        //its the first uninitialized node
        node->data = value;
    } else
    {
        struct node_t * front = initSLL();
        *front = *node;
        node->data = value;
        node->next = front;
    }    
}

struct node_t * removeHead(struct node_t * head) {
    
    struct node_t * second;
    struct node_t tempFirst;
    int size = count(head);
    if (size == 1)
    {        
        head->data = NULL;
        head->next = NULL;
        return head;
    } else if (size > 1)
    {
        tempFirst = *head;  
        second = head->next;      
        *head = *(second);    
        *second = tempFirst;  
        second->next = NULL;          
        return second;
    } else {
        perror("List has no elements");
        return NULL;
    }
}

int count(struct node_t * list) {
    int count = 0;
    for ( list ; list != NULL; list = list->next){
        if(list->data != NULL)
            count++;
    }
    return count;
}

void * getByIndex(struct node_t * list, int index) {
    int size = count(list);
    
    if(index >= 0 && index <= size-1 && size != 0) {
        int i = 0;
        while (i < index)
        {
            list = list->next;
            i++;
        }
        return list->data;        
    }
    return NULL;
}


void prtList(struct node_t * node, void (*prtCallback)(void *)) {
    for ( struct node_t * node_i = node; node_i != NULL; node_i = node_i->next){
        (*prtCallback)(node_i->data);
    }
    printf("\n");
}
