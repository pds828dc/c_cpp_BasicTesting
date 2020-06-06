//  extern test
#include "stdio.h"
#include "cpp_basic_test_extern_module1.h"

int main() {
    extern int a;
    greeting();
    
    printf("In main, a = %d\n", a);
    a = 0;
    printf("In main, a = %d\n", a);
    return 0;
}