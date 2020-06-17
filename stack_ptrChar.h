// c stack char*
#include"stdio.h"
#include"stdlib.h"

typedef struct stack_ptrChar{
    char *top;
    int capacity;
    unsigned int size;
    char **container;
} stack_ptrChar;

stack_ptrChar* createStackPtrChar(){
    stack_ptrChar *stack = (stack_ptrChar *)malloc(1 * sizeof(stack_ptrChar));
    stack->top = NULL;
    stack->capacity = 2;
    stack->size = 0;
    stack->container = (char **)malloc(stack->capacity * sizeof(char *));
    return stack;
}
void stack_ptrCharDoubleCapacity(stack_ptrChar* stack){
    stack->capacity *= 2;
    stack->container = (char **)realloc(stack->container, stack->capacity);
}
void stack_ptrCharPush(stack_ptrChar* stack, char* ptr){
    if(stack->size==stack->capacity){
        stack_ptrCharDoubleCapacity(stack);
    }
    stack->container[stack->size] = ptr;
    stack->size++;
    stack->top = ptr;
}
void stack_ptrCharPop(stack_ptrChar* stack){
    if(stack->size==0){
        printf("Nothing can be poped");
        return;
    }
    stack->size--;
    stack->top = stack->container[stack->size - 1];
}
bool stack_ptrCharIsEmpty(stack_ptrChar* stack){
    if(stack->size){
        return true;
    }
    return false;
}