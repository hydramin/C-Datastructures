#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(X, Y) (((X) >= (Y)) ? (X) : (Y))

struct tnode
{
    int key;
    char * value;

    struct tnode * parent;

    struct tnode * lchild;
    struct tnode * rchild;    

    int height;
    int lc_height;
    int rc_height;
};

struct tnode * initTree();
void insertTree(struct tnode *, int, char *);
void inorderTnodes(struct tnode * );
void postorderTnodes(struct tnode * );
void preorderTnodes(struct tnode * );
void freeTree(struct tnode * );
