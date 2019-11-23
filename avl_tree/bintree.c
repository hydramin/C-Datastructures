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

int setHeight(struct tnode * root) {
    if(root == NULL) return -1;
    root->height = 1 + MAX(setHeight(root->lchild), setHeight(root->rchild));
    root->lc_height = getTnodeHeight(root->lchild);
    root->rc_height = getTnodeHeight(root->rchild);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>. this >> %d height >> %d || L >> %d || R >> %d\n", root->key, root->height, (root->lchild == NULL)?666:root->lchild->key, (root->rchild == NULL)?666:root->rchild->key);
    return root->height;
}

void leftLeftRotation(struct tnode * root) {
    printf("**LEFT LEFT** at (%d, %s)\n", root->key, root->value);
    struct tnode * newRoot = root->lchild;
    struct tnode oldRoot = *root;
    *root = *newRoot;
    *newRoot = oldRoot;

    root->parent = newRoot->parent;
    root->rchild = newRoot;
    newRoot->parent = root;
    root->lchild->parent = root;
    newRoot->lchild = NULL;
    // preorderTnodes(root); printf("\n");
    setHeight(root);
    // preorderTnodes(root); printf("\n");
}

void rightRightRotation(struct tnode * root) {
    printf("**RIGHT RIGHT** at (%d, %s)\n", root->key, root->value);
   
    struct tnode oldRoot = *root; // 5
    struct tnode newRoot = *(root->rchild); // 6
    struct tnode * newRootP = root->rchild; // --> |6|
    *newRootP = oldRoot;
    *root = newRoot;
    root->lchild = newRootP;
    root->parent = newRootP->parent;
    newRootP->parent = root;
    root->rchild->parent = root;
    newRootP->rchild = NULL;
    // preorderTnodes(root); printf("\n");
    setHeight(root);
    // preorderTnodes(root); printf("\n");
    // printf("||||||||||||||||||||||||||||||||||||||||||||||||||| %d %s\n", root->key, root->value);
    // printf("||||||||||||||||||||||||||||||||||||||||||||||||||| %d s\n", root->lchild->key, root->lchild->value);
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
                struct tnode * rootL = root->lchild;
                rootL->rchild->lchild = rootL;
                rootL->parent = rootL->lchild;
                root->lchild = rootL->rchild;
                rootL->rchild->parent = root;
                rootL->rchild = NULL;
               
                printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> %d %d\n", root->key, root->lchild->key);
                leftLeftRotation(root);
            }
            
        } else if (lch < rch) {
            if(root->rchild->lc_height > root->rchild->rc_height) { // right left case
                printf("**RIGHT LEFT** at (%d, %s)\n", root->key, root->value);
                struct tnode * rootR = root->rchild;
                rootR->parent = root->lchild;
                rootR->lchild->rchild = rootR;
                rootR->lchild->parent = root;
                root->rchild = rootR->lchild;
                rootR->lchild = NULL;                
                rightRightRotation(root);
            } else if (root->rchild->lc_height < root->rchild->rc_height) {// right right case   
                        
                rightRightRotation(root);    
                preorderTnodes(root); printf("\n");            
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
    printf("(%d <-> %s) height >> %d | ", root->key, root->value, root->height);
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

