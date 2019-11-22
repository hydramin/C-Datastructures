struct node_t {
    char * key;
    char * data;
    struct node_t * before;
    struct node_t * after;
};

struct listNodes
{
    struct node_t * head;
    struct node_t * tail;
    int size;
};

// Node * newNode();
extern struct listNodes * initDLL() ;
extern void insertLast(struct listNodes * , char *,  char * );
extern void insertFirst(struct listNodes *, char *, char * );
extern void prtList(struct listNodes * );
extern void freeMem(struct listNodes * );