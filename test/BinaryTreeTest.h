#include "../lib/BinaryTree.h"

void binaryTreeTest() {
    BTreeLink bTreeLink = BinaryTreeFactory(comparator);
    TreeData list[] = {12, 4312, 123, 5, 123, 4, 12, 431, 13, 51, 13, 43, 12, 521, 3, 97, 46};
    for (int i = 0; i < 28; ++i) {
        insertNodeToTree(bTreeLink, list[i]);
    }
    printf("===================\n");

    printf("inTraversal: ");
    inTraversal(bTreeLink->root);
    printf("\n");
    printf("preTraversal: ");
    preTraversal(bTreeLink->root);
    printf("\n");
    printf("postTraversal: ");
    postTraversal(bTreeLink->root);
}
