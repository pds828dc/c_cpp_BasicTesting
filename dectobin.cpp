// print dectobin
#define BV(n) 0x1<<(n)
#include"stdio.h"
void printDec2Bin(int val){
    int window = BV(1);
    bool buff[32] = {0};
    for (int i = 0 ; i<32 ;i++){
        buff[i] = val & window;
        window = window << 1;
    }
    for (int i = 31; i >= 0; i--)
    {
        if (27==i|| 23==i|| 19==i|| 15==i|| 11==i|| 7==i|| 3==i)
        {
            printf(" ");
        }
        printf("%d", buff[i]);
    }
}

int main(){
    int val = 0x12345678;
    printDec2Bin(val);
    return 0;
}