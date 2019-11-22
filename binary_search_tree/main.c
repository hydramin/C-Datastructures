#include "bintree.h"

int main(int argc, char const *argv[])
{
    struct tnode * root = initTree();

    char * names[] = { "Afiye", "Nadia", "Milky", "Genet", "Mahmoud", "Amin", "Masho", "Sada" };
    int nums[] = {5, 8, 2, 1, 9, 3, 7, 0};

    for (int i = 0; i < 8; i++)
    {
        printf("--------------------\n");
        insertTree(root, nums[i], *(names+i));
    }
    printf("height = %d\n", root->height);
    printf("---------IN ORDER TRAVERSAL-----------\n");
    inorderTnodes(root);
    printf("\n");
    printf("---------POST ORDER TRAVERSAL-----------\n");
    postorderTnodes(root);
    printf("\n");
    printf("---------PRE ORDER TRAVERSAL-----------\n");
    preorderTnodes(root);
    printf("\n");
    freeTree(root);
    
    // preorderTnodes(root);

    return 0;
}
