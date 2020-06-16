#include"stdio.h"
#define ADD(a,b) a+b

int multiple(int a, int b, int c, int d) {
    a = ADD(a,b);
    b = ADD(c,d);
    printf("ADD(a,b)=%d\n", ADD(a, b));
    printf("ADD(c,d)=%d\n", ADD(c, d));

    return ADD(a,b) * ADD(c,d);
}
int main(){
    int a=1, b=2, c=3, d=4;
    int ans = multiple(a, b, c, d);
    printf("%d", ans);
    return 0;
}

