// interview_phison_phibonacci_series
#include"stdio.h"
int get_Phibonacci_Number_At_Order_N(int n){
    int a=11, b= 12;
    if(n==0){
        return a;
    }
    if(n==1){
        return b;
    }
    for(int i = 1; i<n ; i++){
        b = a + b;
        a = b - a;
    }
    return b;
}
int main(){
    printf("phi(2)=%d\n", get_Phibonacci_Number_At_Order_N(2));
    printf("phi(3)=%d\n", get_Phibonacci_Number_At_Order_N(3));
    printf("phi(4)=%d\n", get_Phibonacci_Number_At_Order_N(4));
    printf("phi(5)=%d\n", get_Phibonacci_Number_At_Order_N(5));
    printf("phi(9)=%d\n", get_Phibonacci_Number_At_Order_N(9));
    printf("phi(21)=%d\n", get_Phibonacci_Number_At_Order_N(21));

    unsigned int a,b;
    for(b = 2; b >= 0 ; b--){
        a++;
    }
    printf("a=%d\n", a);

    return 0;
}