
int testint();
struct node_t * initSLL();
void insertLast(struct node_t * node, char *value);
void insertFirst(struct node_t * node, char *value);
void prtList(struct node_t * node);
int count(struct node_t * list);
char * getByIndex(struct node_t * list, int index);
struct node_t * removeHead(struct node_t * head);

struct node_t {
    char * data;
    struct node_t * next;
};