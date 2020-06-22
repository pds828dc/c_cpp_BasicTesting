#include<stdio.h>
#include<stdlib.h>

void absf(double *x) {
    int a = 0x1;
    char little_end = *((char *) &a);
    
    printf("little_end = %x\n", little_end);
    printf("((int *) x)= %p\n", ((int *) x));
    printf("* x= %x\n", *(int *)x ) ;
    printf("((int *) x) =%d\n",((int *) x));

    printf("(((int *) x) + little_end) = %p\n", (((int *) x) + little_end));
    printf("0x7fffffff %x\n", 0x7fffffff);
    printf("*(((int *) x) + little_end) &= 0x7fffffff = %x\n", *(((int *) x) + little_end) &= 0x7fffffff);
    *(((int *) x) + little_end) &= 0x7fffffff; // a&=b ==> a = a&b

}