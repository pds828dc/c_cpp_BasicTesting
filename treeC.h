// tree in C
//REF: https://www.cprogramming.com/tutorial/c/lesson18.html

#define dRight 1
#define dLeft 0
#ifndef STD_H

#define STD_H
#include"stdio.h"
#include"stdlib.h"
#include"stdint.h"

#endif
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
struct Tree{
    struct TreeNode* root;
};
typedef struct queueUnitTree{
    TreeNode *node;
    queueUnitTree *next;
}qtUnit;
typedef struct queue{
    qtUnit *front;
    qtUnit *end;
    uint32_t size;
}queue;
queue* queueCreate(){
    queue* que = (queue *)malloc(1 * sizeof(queue));
    que->size = 0;
    que->front = NULL;
    que->end = NULL;
    return que;
}
bool queueEmpty(queue*que){
    if(que->size){
        return false;
    }
    return true;
}
void queuePush(queue* que, TreeNode* node){
    qtUnit *qUnit = (qtUnit *)malloc(sizeof(qtUnit));
    qUnit->node = node;
    qUnit->next = NULL;
    que->size++;
    if(NULL==que->front){
        que->front = qUnit;
        que->end = qUnit;
    }
    else{
        que->end->next = qUnit;
        que->end = qUnit;
    }
}
void queuePop(queue* que){
    if(queueEmpty(que) ){
        printf("There is nothing to pop !!!");
    }
    else{
        que->size--;
        free(que->front);
        que->front = que->front->next;
        if(que->size == 1){
            que->end = NULL;
        }
    }
}
void NodeCreate(TreeNode** node, int value){
    *node = (struct TreeNode *)malloc(sizeof(TreeNode));
    (*node)->val = value;
    (*node)->left = NULL;
    (*node)->right = NULL;
}
Tree* TreeCreat(){
    Tree* tree = (struct Tree *)malloc(sizeof(struct Tree));
    tree->root = (struct TreeNode *)malloc(sizeof(TreeNode));
    tree->root->val = NULL;
    tree->root->left = NULL;
    tree->root->right = NULL;
    return tree;
}
bool checkNodeValid(TreeNode* root, int index){
    if(NULL==root){
        printf("tree node at index%d hasn't been built",index);
        return false;
    }
    else{
        return true;
    }
}
int treeSearchIndex(TreeNode* root, int index){
    int track = 1;
    if(index <2){
        if( !checkNodeValid(root, index) ){
            return -1;
        }
        else{
            return root->val;
        }
    }
    else{
        while(index>1){
            if(index%2){
                track = track * 2 + 1;
            }
            else{
                track = track * 2 ;
            }
            index = index / 2;
        }
    }
    while(track>0){
            if( !checkNodeValid(root, index)){
                return -1;
            }
            else if(track%2){                        //  LSB =1 則左走
                root = root->left;
            }
            else{
                root = root->right;                  //  LSB =0 則右走
            }
            track = track / 2;
        }
        return root->val;
}
// void buildBinarySearchTree(TreeNode* root, int* preorder, int* index){
//     NodeCreate(&root, preorder[*index]);
//     if(preorder[*index+1]<root->val){
//         *index = *index +1 ;
//         buildBinarySearchTree(root->left, preorder, index );
//     }
//     else{

//     }
    
// }
// TreeNode* ConstructBinarySearchTreefromPreorderTraversal(int* preorder, int preorderSize){
//     TreeNode *root;
//     int index = 0;
//     buildBinarySearchTree(root, preorder, &index);
//     return root;
// }
struct TreeNode* ConstructBinarySearchTreefromPreorderRecursionV3(int* preorder, int end, int max, int* pos){
    if(*pos == end){
        return NULL;
    }
    if(preorder[*pos] > max){
        return NULL;
    }
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = preorder[*pos];
    *pos+=1;
    root->left = ConstructBinarySearchTreefromPreorderRecursionV3(preorder, end, root->val, pos);
    root->right = ConstructBinarySearchTreefromPreorderRecursionV3(preorder, end, max, pos);
    return root;
}
struct TreeNode* ConstructBinarySearchTreefromPreorderRecursionV2(int* preorder, int start, int end, int max, int* pos){
    if(start == end){
        return NULL;
    }
    if(preorder[start] > max){
        return NULL;
    }
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = preorder[start];
    *pos+=1;
    root->left = ConstructBinarySearchTreefromPreorderRecursionV2(preorder, start + 1, end, root->val, pos);
    root->right = ConstructBinarySearchTreefromPreorderRecursionV2(preorder, *pos, end, max, pos);
    return root;
}
struct TreeNode* ConstructBinarySearchTreefromPreorderRecursion(int* preorder, int start, int end){
    if(start == end){
        return NULL;
    }
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = preorder[start];
    int i = start + 1;
    while(i<end && preorder[i]<preorder[start]){              ///  不想掃 i 浪費時間 改 V2
        i++;                                                  ///
    }
    root->left = ConstructBinarySearchTreefromPreorderRecursion(preorder, start + 1, i);
    root->right = ConstructBinarySearchTreefromPreorderRecursion(preorder, i, end);
    return root;
}
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    int pos = 0;
    int max = preorder[preorderSize - 1];
    // return ConstructBinarySearchTreefromPreorderRecursion(preorder, 0, preorderSize);
    return ConstructBinarySearchTreefromPreorderRecursionV2(preorder, 0, preorderSize, max, &pos);
}
void TreeInsert(TreeNode** root, int value, int index){
    int track = 1;
    if(value == NULL){
        return;
    }
    if(index <2){
        (*root)->val = value;
    }
    else{
        while(index>1){
            if(index%2){
                track = track * 2 + 1;
            }
            else{
                track = track * 2 ;
            }
            index = index / 2;
        }
        TreeNode **ptrNode = root;
        while(track>0){
            if(*ptrNode == NULL){
                NodeCreate(ptrNode, value);
                //printf("node%d has to be created", track);
            }
            else if(track%2){                      //  LSB =1 則左走
                ptrNode = &(*ptrNode)->right;
            }
            else{
                ptrNode = &(*ptrNode)->left;       //  LSB =0 則右走
            }
            track = track / 2;
        }
    }
} 
int maxiumDepth(struct TreeNode* root){
    if(root== NULL){
        return 0;
    }
    int right = maxiumDepth(root->right);
    int left = maxiumDepth(root->left);
    if(right > left ){
        return right+1;
    }
    else{
        return left+1;
    }
}
void TreeInsertInLevelOrder(TreeNode** root, queue* que, int value){
    TreeNode **neoNode;
    NodeCreate(neoNode, value);
    if(NULL == (*root)->val){
        root = neoNode;
        queuePush(que, *root);
    }
    if(NULL==que->front->node->left){
        que->front->node->left = *neoNode;
    }
    else{
        que->front->node->right = *neoNode;
        queuePop(que);
    }
    queuePush(que, *neoNode);
}
queue* TreeBuildInLevelOrderBuild(TreeNode** root, int* arr, int arrSize){
    queue* que = queueCreate();
    for (int i = 0; i < arrSize; i++){
        TreeInsertInLevelOrder(root, que, arr[i]);
    }
    return que;
}
