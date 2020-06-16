//Leetcode: Min Stack
#include"stdio.h" 
#include"stdlib.h"
typedef struct {
    int *data;
    int size;
    int *mins;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    obj->data = NULL;
    obj->mins = NULL;
    obj->size = 0;
    return obj;
}

void minStackPush(MinStack* obj, int x){
    obj->data = (int *)realloc(obj->data, sizeof(int) * (obj->size + 1));
    obj->mins = (int *)realloc(obj->mins, sizeof(int) * (obj->size + 1));
    obj->data[obj->size] = x;
    if(obj->size == 0 || x < obj->mins[obj->size-1] ){
        obj->mins[obj->size] = x;   
    }
    else{
        obj->mins[obj->size] = obj->mins[obj->size-1];
    }
    obj->size++;
}

void minStackPop(MinStack* obj) {
    obj->size--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
    // int min = obj->data[0];
    // for (int i = 1; i< obj->size; i++){
    //     if(obj->data[i] < min){
    //         min = obj->data[i];
    //     }
    // }
    return obj->mins[obj->size-1];
}

void minStackFree(MinStack* obj) {
     free(obj->data);
     free(obj);
}
void printStack(MinStack *obj){
    printf("Stack : ");
    for (int i = 0; i< obj->size;i++){
        printf("%d ", obj->data[i]);
    }
    printf("\n");
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
int main(){
    MinStack *minStack = minStackCreate();
    int min = 0;
    minStackPush(minStack,-2);
    printStack(minStack);
    minStackPush(minStack,0);
    printStack(minStack);
    minStackPush(minStack,-3);
    printStack(minStack);

    min = minStackGetMin(minStack); // return -3
    printStack(minStack);
    printf("Min = %d\n", min);
    
    minStackPop(minStack);
    min = minStackTop(minStack);    // return 0
    printStack(minStack);
    printf("Top = %d\n", min);
    
    min = minStackGetMin(minStack); // return -2
    printStack(minStack);
    printf("Min = %d\n", min);
    
    minStackFree(minStack);
    return 0;
}