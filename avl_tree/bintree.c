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

struct tnode * inorderSuccessor(struct tnode * root) {    
    struct tnode * successor = root->rchild;
    if(successor == NULL)
    {
        printf("||||||||||||||||||||||||| INORDER SUCCESSOR LEAF ---> (%d <-> %s) \n", root->key, root->value);
        return NULL;
    }
    while(successor->lchild != NULL) {
        successor = successor->lchild;
    }
    return successor;
}

struct tnode * inorderPredecessor(struct tnode * root) {    
    struct tnode * predecessor = root->lchild;
    if(predecessor == NULL) return NULL;
    while(predecessor->rchild != NULL) {
        predecessor = predecessor->rchild;
    }
    return predecessor;
}

bool deleteTNode(struct tnode * root, int key) {
    if(root == NULL) return false;
    if(root->key == key) {
        if (isLeaf(root))
        {
            struct tnode * parentp = root->parent;
            if (parentp == NULL) // root leaf
            {
                printf("||||||||||||||||||||||||| ROOT LEAF DELETED ---> (%d <-> %s) \n", root->key, root->value);
                root->value = NULL;
                free(root);
            } else // non root leaf
            {
                printf("||||||||||||||||||||||||| REGULAR LEAF DELETED ---> (%d <-> %s) \n", root->key, root->value);
                if(parentp->lchild == root) {root->value = NULL; free(root); parentp->lchild = NULL;}
                if(parentp->rchild == root) {root->value = NULL; free(root); parentp->rchild = NULL;}
                
            }
        } else
        {
            // find inorder predessor or inorder successor
            struct tnode * successor = inorderSuccessor(root);
            struct tnode * predecessor = inorderPredecessor(root);
            bool snext = root->rchild != successor;
            // printf("33333333333333asdf333333333333 %ld %ld\n",root->rchild, successor);
            bool pnext = root->lchild != predecessor;
            if (predecessor != NULL)
            {
                
                printf("|||| INNER TNODE DELETED ---> (%d <-> %s) SUCC => %s PRED => %s \n", root->key, root->value, successor, predecessor->lchild);
                // printf("|||| INNER TNODE DELETED ---> (%d <-> %s) SUCC => %d PRED => %d \n", root->key, root->value, successor->key, predecessor->key);
                // printf("p > %d pp > %d pl > %s pr > %s\n", predecessor->key, predecessor->parent->key, predecessor->lchild, predecessor->rchild);
                // printf("r > %d rp > %d rl > %d rr > %d\n", root->key, (root->parent == NULL)?666:root->parent->key, root->lchild->key, root->rchild->key);



                // exchange root and predecessor
                struct tnode deleted = *root; // 15
                *root = *predecessor; // r = 14
                *predecessor = deleted; // p = 15
                // printf("p > %d pp > %d pl > %d pr > %d\n", predecessor->key, (predecessor->parent == NULL)?666:predecessor->parent->key, predecessor->lchild->key, predecessor->rchild->key);
                // printf("r > %d rp > %d rl > %s rr > %s\n", root->key, root->parent->key, root->lchild, root->rchild);
                // reestablish pointers for the new root from the predecessor
                struct tnode * predecessorParent = root->parent;
                root->parent = predecessor->parent;
                root->rchild = predecessor->rchild;
                if(predecessor->rchild != root) { 
                    root->lchild = predecessor->lchild;
                    predecessorParent->rchild = NULL; 
                    }
                // printf("kkkkkkkkkkkkkkkkkkkkkkkkkk r >> %d, rp >> %d, rr >> %d, rl >> %d\n", root->key, (root->parent == NULL)?666:root->parent->key, root->rchild->key, root->lchild->key);
                // printf("p > %d pp > %d pl > %d pr > %d\n", predecessor->key, predecessor->parent->key, predecessor->lchild, root->rchild->key);
                // printf("r > %d rp > %d rl > %d rr > %d\n", root->key, root->parent->key, predecessor->lchild, root->rchild->key);
                // // free the predecessor
                predecessor->value = NULL;
                free(predecessor);
            } else if (successor != NULL)
            {
                printf("|||| INNER TNODE DELETED ---> (%d <-> %s) SUCC => %d PRED => %d \n", root->key, root->value, successor->key, predecessor->key);
                // printf("p > %d pp > %d pl > %s pr > %d\n", successor->key, successor->parent->key, successor->lchild, successor->rchild->key);
                // printf("r > %d rp > %d rl > %d rr > %d\n", root->key, root->parent->key, root->lchild->key, root->rchild->key);

                // exchange root and predecessor
                struct tnode deleted = *root; // 15
                *root = *successor; // r = 14
                *successor = deleted; // p = 15
                // printf("p > %d pp > %d pl > %d pr > %d\n", successor->key, successor->parent->key, successor->lchild->key, successor->rchild->key);
                // printf("r > %d rp > %d rl > %s rr > %d\n", root->key, root->parent->key, root->lchild, root->rchild->key);
                // reestablish pointers for the new root from the successor
                struct tnode * successorParent = root->parent; // root new
                root->parent = successor->parent;
                if(snext) {
                    root->rchild = successor->rchild;
                    successorParent->lchild = NULL;
                    // printf("333333333333444433333333333333 %ld %ld\n",successor->rchild->key, root->rchild->key);
                }
                root->lchild = successor->lchild;
                // printf("kkkkkkkkkkkkkkkkkkkkkkkkkk r >> %d, rp >> %d, rr >> %d, rl >> %d\n", root->key, root->parent->key, root->rchild->key, root->lchild->key);
                // printf("p > %d pp > %d pl > %d pr > %d\n", predecessor->key, predecessor->parent->key, predecessor->lchild, root->rchild->key);
                // printf("r > %d rp > %d rl > %d rr > %d\n", root->key, root->parent->key, predecessor->lchild, root->rchild->key);
                // // free the predecessor
                successor->value = NULL;
                free(successor);
                preorderTnodes(root);
                
            } else {
                return false;
            }
            
            
        }
        return true;
    }
    bool temp;
    if (root->key > key) // left
    {
        temp = deleteTNode(root->lchild, key);
        printf("ppppppppppppppppppppppppppp %d\n", root->key);
        setHeight(root);   
    }
    if(root->key < key) // right
    {
        temp = deleteTNode(root->rchild, key);
        setHeight(root);
    }
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    balance(root);
    return temp;
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

