
int testint();
struct node_t * init();
void insert(struct node_t * node, char *value);
void prtList(struct node_t * node);

struct node_t {
    char * data;
    struct node_t * next;
};