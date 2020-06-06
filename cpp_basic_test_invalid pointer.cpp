// cpp test
#include"stdio.h"
#include"stdlib.h"
bool nof2(int N){
    return  0 == (N & (N - 1));
}

int main(){
    int *p;
    p =(int*) malloc(200);
    void *ptr = (void *)0;
    printf("%u  ptr=%u \n", p,ptr==NULL);
    free(p);
    int ans = nof2(8);
    printf("%u ANS=%d", p, ans);
    return 0;
}