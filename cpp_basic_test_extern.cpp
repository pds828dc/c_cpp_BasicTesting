//  extern test
#include "stdio.h"
// #include "cpp_basic_test_extern_module1.h"
void greeting() {
    extern int a;
    a = -2;
    printf("In greeting, a = %d\n", a);
}
int main() {
    printf("---test2 extern variable-------\n");
    extern int a;                          //  透過extern取得在 module1 的宣告參考  而不是複製一份 
    // extern void greeting();
    greeting();
    a = 1;
    printf("In main, a = %d\n", a);
    a = 0;
    printf("In main, a = %d\n", a);
    // extern void greeting();
    greeting();

    printf("---test2 local variable-------\n");
    int i = 10;
    for (int i = 0; i<5; i++){
        printf("i=%d\n", i);
    }                                     // i = 0 1 2 3 4
    printf("After loop i = %d", i);       // i == 10

    return 0;
}