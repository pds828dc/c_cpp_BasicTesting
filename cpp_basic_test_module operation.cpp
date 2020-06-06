// cpp test module operation
#include"stdio.h"
#include"stdlib.h"
// A%B = C  ==>  A = (A/B)*B + C
int main(){
    int PN = 5;
    int NN = -5;
    printf("PN % 3= %d\n", PN%3);
    printf("NN % 3= %d\n", NN%3);
    printf("PN/-3 = %d PN % -3= %d\n",PN/(-3), PN%(-3) );
    printf("NN % -3= %d\n",NN%(-3) );

    return 0;
}