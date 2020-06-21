// inverse a string
#include"stack_ptrChar.h"
#include"string.h"
void inverse_ByWords(char* data){
    stack_ptrChar *stack = stack_ptrCharCreate();
    char *ptrdiv = strtok(data, " ");
    stack_ptrCharPush(stack, ptrdiv);
    while ( (ptrdiv = strtok(NULL, " ")) ){
        stack_ptrCharPush(stack, ptrdiv);
    }
    while(stack->size){
        printf("%s ", stack->top);
        stack_ptrCharPop(stack);
    }
}
void reverse_CharByChar(char * data){
    int len = strlen(data);
    for (int start = 0; start < len/2; start++){
        int end = len - 1 - start;
        data[start] = data[start] + data[end];
        data[end] = data[start] - data[end];
        data[start] = data[start] - data[end];
    }
}
void inverse_byword(char* data){
    char *p = NULL;
     while ((p = strrchr(data, ' ')) != NULL) 
    {
        printf ("%s ", (p + 1));
        *p = '\0';
        }
 
    printf ("%s\n", data);
}
int main(){
    char data[] = "how are you";
    // inverse_ByWords(data);
    // reverse_CharByChar(data);
    // printf("%s", data);
    int n = 3;
    printf("%d %d %d\n", ++n, n++, n*n); 
    printf("%d %d %d\n", ++n, n++, n*n); 

    return 0;
}