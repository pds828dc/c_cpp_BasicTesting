// interview_phison_no_use_of_ifswitch
#include"stdio.h"
void func1(){
    printf("This is func1\n");
}
void func2(){
    printf("This is func2\n");
}
void func3(){
    printf("This is func3\n");
}
void func4(){
    printf("This is func4\n");
}
void func5(){
    printf("This is func5\n");
}
int main(){
    void (*ptrfunc[])(void) = {func1,func2,func3,func4,func5};
    for (int i = 0; i < 5; i++){
        ptrfunc[i]();
    }
    int a[10] = {0, 1, 0, 1};
    int i = 8;
    if( (a[i]=10) && (i<4)){
    // if( (i<4) && (a[i]=10) ){
        printf("yes!!\n");
    }else{
        printf("nope%d",a[i]);
    }
        return 0;
}