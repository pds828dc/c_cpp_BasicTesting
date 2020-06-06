//c code type memory declaration
#include"stdio.h"

int main(){
    short a = 10;
    int b = 11;
    long c = 12;
    long long d = 13;
    float e = 14.12;
    double f = 15.12;
    long double g = 16.12;
    char h = 't';
    char i[] = "Hello World!";            // 5 + (' ')1 + 5 + ('!')1 + ('\0')1
    char *ptrh = &h;
    char *ptri = i;
    printf("型態\t\t\t大小（bytes）\n");
    printf("short\t\t\t%llu\n", sizeof(a));
    printf("int\t\t\t%llu\n", sizeof(b));
    printf("long\t\t\t%llu\n", sizeof(c));
    printf("long long\t\t%llu\n", sizeof(d));
    printf("float\t\t\t%llu\te = %f\n", sizeof(e),e);
    printf("double\t\t\t%llu\tf = %lf\n", sizeof(f), f);
    printf("long double\t\t%llu\tg = %LG\n", sizeof(g), g);
    printf("char\t\t\t%llu\n", sizeof(h));
    printf("char array\t\t%llu\n", sizeof(i));
    printf("pointer of char\t\t%llu\n", sizeof(ptrh));
    printf("pointer of char array\t%llu\n", sizeof(ptri));
    printf("memory of char array head\t%llu\n", sizeof(*ptri));
    printf("pointer h=\t\t%llu\n", ptrh);
    printf("pointer i=\t\t%llu\n", ptri);
    printf("the difference of pointers\t%llu\n", ptrh-ptri);
    // exchange pointer i&h
    long long dif= (long long)ptrh - (long long)ptri;
    ptri = ptri + dif;
    ptrh = ptri - dif;
    printf("pointer h=\t\t%llu\n", ptrh);
    printf("pointer i=\t\t%llu\n", ptri);

    return 0;
}