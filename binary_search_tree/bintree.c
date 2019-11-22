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
            printf("%s <---left\n", root->value);
            insertTree(root->lchild, key, value);            
        } else {
            if (root->rchild == NULL)
            {
                root->rchild = initTree();
                root->rchild->parent = root;            
            }
            printf("right ---> %s \n", root->value);
            insertTree(root->rchild, key, value);
        }
    }
    root->height = 1 + MAX(getTnodeHeight(root->lchild), getTnodeHeight(root->rchild));
    printf("%s <--- **, height = %d\n", root->value, root->height);
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

