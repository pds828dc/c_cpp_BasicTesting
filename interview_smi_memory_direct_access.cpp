// address access
#include"stdio.h"
#include"stdlib.h"

int main(){
    int* ptr = (int*)malloc(sizeof(int));
    printf("%p\n",ptr);
    int *ptr_test = ptr + 1;
    *ptr_test = 100;                                                         //   get address by a valid pointer 但此種存取依然有不可預期的後果
    printf("ptr+1:%p *(ptr+1)=%d\n", ptr_test, *ptr_test);
    int * const ptr_test_valid = (int * const)0x00000000007E15F0;            // 需要強迫轉型int為int* 但是一般未知實際記憶體配置狀況時 都會遇上segmentation fault
    *ptr_test_valid = 111;
    printf("ptr_valid:%p *(ptr_valid)=%d", ptr_test_valid, *ptr_test_valid);
    return 0;
}