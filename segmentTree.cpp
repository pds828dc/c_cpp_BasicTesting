// segment tree
// Let us consider the following problem to understand Segment Trees.
// We have an array arr[0 . . . n-1]. We should be able to have teo behaviors
// 1. Find the sum of elements from index l to r where 0 <= l <= r <= n-1
// 2. Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.

#include"stdio.h"
#include"stdlib.h"
#include"math.h"
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
} Node;
Node *createNode(){

}
int getMid(int start, int end) { return start + (end - start) / 2; } // Function to return the middle index 

int querySumUtil(int* segmentTree, int start, int end, int qstart, int qend, int indexSegmentTree){
    if( qstart<=start && qend>=end ){
        return segmentTree[indexSegmentTree];
    }
    if( qstart> end || qend< start){
        return 0;
    }
    int mid = getMid(start, end);
    return querySumUtil(segmentTree, start, mid, qstart, qend, 2*indexSegmentTree+1)
           + querySumUtil(segmentTree, mid+1, end, qstart, qend, 2*indexSegmentTree+2);
}

int querySum(int* segmentTree, int sizeSegmentTree, int qstart, int qend){
    if(qstart<0 || qend>=sizeSegmentTree || qstart>qend){
        return -1;
    }
    return querySumUtil(segmentTree, 0, sizeSegmentTree - 1, qstart, qend, 0);
}

void updateSegmentTreeUtil(int* segmentTree,int start, int end, int indexArray, int diff, int indexSegmentTree){
    if(indexSegmentTree<start||indexSegmentTree>end){
        return;
    }
    segmentTree[indexSegmentTree] += diff;
    if(start!=end){
        int mid = getMid(start, end);
        updateSegmentTreeUtil(segmentTree, start, mid, indexArray, diff, indexSegmentTree * 2 + 1);
        updateSegmentTreeUtil(segmentTree, mid+1, end, indexArray, diff, indexSegmentTree * 2 + 2);
    }
}
/*Function to update the value in the original array and segment tree
Calls function updateSegmentTreeUtil() to update values in segment tree*/
void updateSegmentTree(int* segmentTree, int* array, int sizeArray, int indexArray, int value){
    if(indexArray<0||indexArray>=sizeArray){
        return;
    }
    int diff = value - array[indexArray];
    array[indexArray] = value;
    updateSegmentTreeUtil(segmentTree, 0, sizeArray - 1, indexArray, diff, 0);
}

/*A recursive funtion to construct a segment tree for [start, end]
Start is the starting index of the original array represented by the current node of segment tree
End is the ending index of the original array represented by the current node of segment tree*/
int constructSegmentTreeUtil(int* array, int* segmentTree, int start, int end, int indexSegmentTree){
    if(start==end){
        segmentTree[indexSegmentTree] = array[start];
        return array[start];
    }
    int mid = getMid(start, end);
    segmentTree[indexSegmentTree] = constructSegmentTreeUtil(array, segmentTree, start, mid, 2 * indexSegmentTree + 1) 
                                    + constructSegmentTreeUtil(array, segmentTree, mid + 1, end, 2 * indexSegmentTree + 2);
    return segmentTree[indexSegmentTree];
}

/* Function to construct a segment tree from given array. 
   This function allocates an array for segment tree and return the pointer of the array
   The funtion call calls constructSegmentTreeUtil() to fill the memory */
int* constructSegmentTree(int *array, int sizeArray){     //  array methed for case of often querying and seldom updating
    int n = (int)(ceil(log2(sizeArray))) + 1;             // get the height of segment tree n ; ( +1 ) the space of leaf for positions of original array  
    int sizeSegmentTree = pow(2, n)-1;
    int *segmentTree = (int *)calloc(sizeSegmentTree, sizeof(int));
    constructSegmentTreeUtil(array, segmentTree, 0, sizeArray - 1, 0);
    return segmentTree;
}
int main(){
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int size = sizeof(data) / sizeof(*data);
    int *segmentTree = constructSegmentTree(data, size);
    int sum_3_11 = querySum(segmentTree, size, 2, 10);
    printf("sum_3_11= %d\n", sum_3_11);
    updateSegmentTree(segmentTree, data, size, 6, 14);
    sum_3_11 = querySum(segmentTree, size, 2, 10);
    printf("After update index data[6]= 7->14\nsum_3_11=%d\n", sum_3_11);
    return 0;
}