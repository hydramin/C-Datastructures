#include "bintree.h"

//prototypes
struct tnode * getTNode(struct tnode *, int);
bool isLeaf(struct tnode * );
bool isRoot(struct tnode * );

// functions

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
    // printf(">>>>>>>>>>>>>>>>>>>>>>>>. this >> %d height >> %d || L >> %d || R >> %d\n", root->key, root->height, (root->lchild == NULL)?666:root->lchild->key, (root->rchild == NULL)?666:root->rchild->key);
    return root->height;
}

void leftLeftRotation(struct tnode * root) {
    printf("**LEFT LEFT** at (%d, %s)\n", root->key, root->value);
    // save pointers
    struct tnode * tnode2p = root->lchild;
    
    // exchange
    struct tnode tnode2 = *tnode2p;
    *tnode2p = *root;
    *root = tnode2;
    // correct pointers
    tnode2p->lchild = root->rchild;
    if(tnode2p->lchild != NULL)
        tnode2p->lchild->parent = tnode2p;
    root->parent = tnode2p->parent;
    if(root->lchild != NULL)
        root->lchild->parent = root;
    tnode2p->parent = root;
    root->rchild = tnode2p;
    setHeight(root);
}

void rightRightRotation(struct tnode * root) {
    printf("**RIGHT RIGHT** at (%d, %s)\n", root->key, root->value);
   
    //save the pointers
    struct tnode * tnode2p = root->rchild;
    // exchange root and tnode2
    struct tnode tnode2 = *tnode2p;
    *tnode2p = *root;
    *root = tnode2;
    // correct pointers
    tnode2p->rchild = root->lchild;
    if (tnode2p->rchild != NULL)
        tnode2p->rchild->parent = tnode2p;
    
    root->parent = tnode2p->parent;
    tnode2p->parent = root;
    root->lchild = tnode2p;
    if(root->rchild != NULL)
        root->rchild->parent = root;
    setHeight(root);
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
                
                //save pointers
                struct tnode * tnode2p = root->lchild;
                struct tnode * tnode3p = root->lchild->rchild;

                //exchange places
                struct tnode tnode2 = *tnode2p;
                *tnode2p = *tnode3p;
                *tnode3p = tnode2;

                // correct pointers
                tnode3p->rchild = tnode2p->lchild;
                if (tnode3p->rchild != NULL)
                    tnode3p->rchild->parent = tnode3p;
                tnode2p->parent = tnode3p->parent;
                tnode2p->lchild = tnode3p;
                tnode3p->parent = tnode2p;
                printf("ooooooooooooooooooooooooooooooooooooooooooooooo %d p> %d\n", root->lchild->lchild->parent->key, 888);
                leftLeftRotation(root);
            }
            
        } else if (lch < rch) {
            if(root->rchild->lc_height > root->rchild->rc_height) { // right left case
                printf("**RIGHT LEFT** at (%d, %s)\n", root->key, root->value);
                struct tnode * tnode2p = root->rchild;
                struct tnode * tnode3p = root->rchild->lchild;
                // exchange places
                struct tnode tnode2 = *tnode2p;
                *tnode2p = *tnode3p;
                *tnode3p = tnode2;
                // correct the pointers
                tnode3p->lchild = tnode2p->rchild;
                if(tnode2p->rchild != NULL)
                    tnode2p->rchild->parent = tnode3p;
                tnode2p->parent = tnode3p->parent;
                tnode3p->parent = tnode2p;
                tnode2p->rchild = tnode3p;
                     
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

struct tnode * getTNode(struct tnode * root, int key) {
    if(root == NULL) return NULL;
    if(root->key == key) return root;

    if(root->key > key) return getTNode(root->lchild, key);
    if(root->key < key) return getTNode(root->rchild, key);
}

bool isRoot(struct tnode * tnode) {
    return (tnode != NULL && tnode->parent == NULL);
}

bool deleteNode(struct tnode * root, int key) {
    struct tnode * node = getTNode(root, key);
    if (node != NULL)
    {
        if (isLeaf(node))
        {
            // simple deletion
            if(isRoot(node)) {
                free(node);
                node = NULL;
                printf("FREED ROOT LEAF \n");
            } else {
                struct tnode * nparent = node->parent;
                // find if the node is left or right child of the parent
                if(nparent->rchild == node) {
                    printf("RIGHT FREED REGULAR LEAF %ld %ld\n", nparent->rchild, node);
                    free(node);
                    nparent->rchild = NULL;
                } else if (nparent->lchild == node)
                {
                    free(node);
                    nparent->lchild = NULL;
                    printf("LEFT FREED REGULAR LEAF %ld %ld\n", nparent->lchild, node);                    
                }
                
                
            }
            
        }
        
        // printf("||||||||||||||||||||||||| DELETED ---> (%d <-> %s) \n", node->key, node->value);
        return true;
    } else 
    {
        printf("||||||||||||||||||||||||| DELETED ---> NOTHING \n");;
        return false;
    }
    
}

bool isLeaf(struct tnode * tnode) {
    return (tnode->height == 0);
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

