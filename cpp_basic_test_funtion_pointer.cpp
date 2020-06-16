// funtion pointer
#include"stdio.h"
#include"stdlib.h"

int func(int a) {
    return a;
}

int main(){
    int (*func_ptr)(int) = func;
    printf("%d\n", func_ptr(10)); // use function pointer
    return 0;
}