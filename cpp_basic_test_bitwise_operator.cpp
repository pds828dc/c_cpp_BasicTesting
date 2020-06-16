#include"stdio.h"

int main(){
    int flag = 25;
    printf("F>>1 == %d\n",flag>>1);
    printf("F<<1 == %d\n\n",flag<<1);
    printf("--------------------------test1----------------------------\n\n" );

    int res = (64 >> (2 + 1 - 2)) & (~(1 << 2));
    printf("res = %d in dec\n", res);
    printf("res = %x in hex\n", res);
    printf("--------------------------test2----------------------------\n\n" );
    unsigned short a = 0xffff;
    a=~a;
    printf("%x\n", a);
    return 0;
}