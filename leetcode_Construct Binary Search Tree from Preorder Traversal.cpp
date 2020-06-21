// Leetcode: Construct Binary Search Tree from Preorder Traversal
#ifndef STDIO_H
#define STDIO_H
#include"treeC.h"

int main(){
    int data[] = {8, 5, 1, 7, 10, 12};
    int preordersize = sizeof(data) / sizeof(*data);
    TreeNode* root = TreeCreat();
    TreeInsert(&testTree->root, 1, 1);
    TreeInsert(&testTree->root, 2, 2);
    TreeInsert(&testTree->root, 3, 3);
    TreeInsert(&testTree->root, 4, 4);
    TreeInsert(&testTree->root, 5, 5);
    int maxDepth = maxiumDepth(testTree->root);
    printf("Tree depth = %d", maxDepth);

    return 0;
}
#endif