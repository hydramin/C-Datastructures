#include "bintree.h"

int main(int argc, char const *argv[])
{
    struct tnode * root = initTree();

    char * names[] = { "Afiye", "Nadia", "Milky", "Genet", "Mahmoud", "Amin", "Masho", "Sada", "Cady", "Kamoo" };
    // int numsLL[] = {5, 8, 2, 1, 0}; // LEFT LEFT CASE
    // int numsLR[] = {7, 8, 6, 4, 5}; // LEFT LEFT CASE
    // int numsRR[] = {10, 2, 11, 12, 13}; // LEFT LEFT CASE
    // int numsRL[] = {10, 5, 12, 14, 13}; // LEFT LEFT CASE
    int nums[] = {23, 15, 35, 10, 13, 27, 30, 14, 16, 17}; // LEFT LEFT CASE
    // int numsf[] = {5, 6, 7};

    for (int i = 0; i < 10; i++)
    {
        // printf("--------------------\n");
        insertTree(root, nums[i], *(names+i));
    }
    printf("height = %d\n", root->height);
    // printf("---------IN ORDER TRAVERSAL-----------\n");
    // inorderTnodes(root);
    // printf("\n");
    // printf("---------POST ORDER TRAVERSAL-----------\n");
    // postorderTnodes(root);
    // printf("\n");
    printf("---------PRE ORDER TRAVERSAL-----------\n");
    preorderTnodes(root); printf("\n");
    deleteTNode(root, 15);
    preorderTnodes(root); printf("\n");
    deleteTNode(root, 35);
    preorderTnodes(root); printf("\n");
    deleteTNode(root, 23);
    preorderTnodes(root); printf("\n");
    deleteTNode(root, 27);
    preorderTnodes(root); printf("\n");
    // freeTree(root);
    
    // preorderTnodes(root);

    return 0;
}
