//Leetcode: Min Stack

#include"stdio.h" 
#include"stdlib.h"
typedef struct {
    int *data;
	int *top;
	int size;
    int capacity;
    int min;
	int min_num;
} MinStack;
MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj -> data = (int*)malloc(sizeof(int));
	obj -> top = obj -> data;
	obj -> size = 0;
    obj->capacity = 1;
    obj -> min = INT_MAX;                                                      // 初始設置為可能最大值 誰都會比他小
	obj -> min_num = 0;
    return obj;
}
int getminSatckMinByforloop(MinStack *obj){
    int min = INT_MAX;
    for (int i = 0; i< obj->size; i++){
        if(obj->data[i] < min){
            min = obj->data[i];
            obj -> min_num = 1;
        }
        else if(obj->data[i]==min){
            obj -> min_num ++;
        }
    }
    return min;
}
void doubleminStackCapacity(MinStack *obj){
    obj -> data = (int*)realloc(obj->data,sizeof(int)*obj->capacity*2);
    obj->capacity *= 2;
}
void minStackPush(MinStack* obj, int x){
    if(obj->size == obj->capacity){
        doubleminStackCapacity(obj);
    }
    obj->data[obj->size] = x;
    obj->size+=1;
    obj->top +=1; 
	if(x < obj -> min){
		obj -> min = x;
		obj -> min_num = 1;
	}else if(x == obj -> min){
		obj -> min_num += 1;
	}
}
void minStackPop(MinStack* obj) {
    obj->size--;
	if(obj->data[obj->size] > obj -> min){
	
    }
	else{
		if(obj -> min_num > 1){
			obj-> min_num --;
		}
        else{
            obj->min = getminSatckMinByforloop(obj);
		}
	}
}
int minStackTop(MinStack* obj) {
    return obj->data[obj->size-1];
}
int minStackGetMin(MinStack* obj) {
    return obj->min;
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
// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// [[],    [2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]
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

    // MinStack *minStack = minStackCreate();
    // int min = 0;
    // minStackPush(minStack,2147483646);
    // printStack(minStack);
    // minStackPush(minStack,2147483646);
    // printStack(minStack);
    // minStackPush(minStack,2147483647);
    // printStack(minStack);
    // printf("Top = %d\n",minStackTop(minStack));
    // minStackPop(minStack);
    // printStack(minStack);
    // printf("Min = %d\n",  minStackGetMin(minStack));
    // minStackPop(minStack);
    // printStack(minStack);
    // printf("Min = %d\n",  minStackGetMin(minStack));
    // minStackPop(minStack);
    // printStack(minStack);
    // minStackPush(minStack,2147483647);
    // printStack(minStack);
    // printf("Top = %d\n",minStackTop(minStack));
    // printf("Min = %d\n",  minStackGetMin(minStack));
    // minStackPush(minStack,-2147483648);
    // printStack(minStack);
    // printf("Top = %d\n",minStackTop(minStack));
    // printf("Min = %d\n",  minStackGetMin(minStack));
    return 0;
}