#include "bintree.h"

struct tnode * initTree() {
    struct tnode * root = malloc(sizeof(struct tnode));
    if(root == NULL) {
        printf("tnode is not initialized!\n");
    }
    return root;
}

// true for left false for right insertion
bool isLeft(int rootkey, int newkey) {
    if (rootkey < newkey)
    {
        return false;
    }
    return true;
}

int getTnodeHeight(struct tnode * tnode) {
    return (tnode == NULL)? -1: tnode->height;
}

void leftLeftRotation(struct tnode * root) {
    printf("**LEFT LEFT** at (%d, %s)\n", root->key, root->value);
    root->lchild->parent = root->parent; 
    root->parent->lchild = root->lchild;
    root->parent = root->lchild;
    root->lchild->rchild = root;
    root->lchild = NULL;
}

void rightRightRotation(struct tnode * root) {
    printf("**RIGHT RIGHT** at (%d, %s)\n", root->key, root->value);
    root->parent->rchild = root->rchild;
    root->rchild->parent = root->parent;
    root->rchild->lchild = root;
    root->parent = root->rchild;
    root->rchild = NULL;
}

void balance(struct tnode * root ) {
    
    int lch = root->lc_height, rch = root->rc_height;


    if (abs(lch - rch) > 1)
    {
        if(lch > rch) {
            if(root->lchild->lc_height > root->lchild->rc_height) { // left left case
                leftLeftRotation(root);               
            } else if (root->lchild->lc_height < root->lchild->rc_height) { // left right case            
                printf("**LEFT RIGHT** at (%d, %s)\n", root->key, root->value);
                // Do the adjustment rotation first
                root->lchild->rchild->parent = root;
                root->lchild->rchild->lchild = root->lchild;
                root->lchild->parent = root->lchild->rchild;
                root->lchild = root->lchild->rchild;
                root->lchild->lchild = NULL;
                leftLeftRotation(root);
            }
            
        } else if (lch < rch) {
            if(root->rchild->lc_height > root->rchild->rc_height) { // right left case
                printf("**RIGHT LEFT** at (%d, %s)\n", root->key, root->value);
                root->rchild->lchild->rchild = root->rchild;
                root->rchild->parent = root->rchild->lchild;
                root->rchild->lchild->parent = root;
                root->rchild = root->rchild->lchild;
                root->rchild->rchild = NULL;                
                rightRightRotation(root);

            } else if (root->rchild->lc_height < root->rchild->rc_height) {// right right case            
                rightRightRotation(root);
            }
        }
    }    
}

void insertTree(struct tnode * root, int key, char * value) {
    
    if (root->value == NULL ) {
        // Insert first element into root
        root->key = key;
        root->value = value;        
        printf("this -> (%d - %s) parent --> %s\n", root->key, root->value, (root->parent)? root->parent->value:"NULL");
    } else {        
        // Do a comparison and add to left (<) or right(>=)
        if(isLeft(root->key, key)) { // true for left false for right
            if (root->lchild == NULL)
            {
                root->lchild = initTree();
                root->lchild->parent = root;            
            }                    
            printf("(%d <-> %s) <---left\n",  root->key, root->value);
            insertTree(root->lchild, key, value);            
        } else {
            if (root->rchild == NULL)
            {
                root->rchild = initTree();
                root->rchild->parent = root;            
            }
            printf("(%d <-> %s) right ---> \n", root->key, root->value);
            insertTree(root->rchild, key, value);
        }
    }
    root->lc_height = getTnodeHeight(root->lchild);
    root->rc_height = getTnodeHeight(root->rchild);
    root->height = 1 + MAX(root->lc_height, root->rc_height);
    printf("(%d <-> %s) <--- **, height = %d\n\n", root->key, root->value, root->height);
    // determine balancing factor
    balance(root);
}

void inorderTnodes(struct tnode * root) {    
    if(root->lchild != NULL) inorderTnodes(root->lchild);
    printf("(%d <-> %s) ", root->key, root->value);
    if(root->rchild != NULL) inorderTnodes(root->rchild);    
}

void postorderTnodes(struct tnode * root) {    
    if(root->lchild != NULL) postorderTnodes(root->lchild);
    if(root->rchild != NULL) postorderTnodes(root->rchild);    
    printf("(%d <-> %s) ", root->key, root->value);
}

void preorderTnodes(struct tnode * root) {    
    printf("(%d <-> %s) ", root->key, root->value);
    if(root->lchild != NULL) preorderTnodes(root->lchild);
    if(root->rchild != NULL) preorderTnodes(root->rchild);    
}

void freeTree(struct tnode * root) {
    if(root->lchild != NULL) freeTree(root->lchild);
    if(root->rchild != NULL) freeTree(root->rchild);    
    free(root->parent);
    free(root->lchild);
    free(root->rchild);    
    root->value = NULL;
    free(root);
}

