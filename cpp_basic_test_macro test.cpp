// macro test
#include"stdio.h"
#include"stdint.h"
#include <assert.h>
#include <stdbool.h>

// The GCC way. 只能用在GCC
#define COMPARE(a, b) ({ \
        int flag = 0; \
        if (a > b) { \
            flag = 1; \
        } else if (a < b) { \
            flag = -1; \
        } else { \
            flag = 0; \
        } \
        flag; \
    })

#define ADD( a,b )  (a)+(b)            //  <---  problem: the parameters should be wrapped in backets()  

int32_t multiple(int a, int b, int c, int d) { // a = 1  b = 2  c = 3  d = 4 
                                // should be following
    a = ADD(a,b);               // a = 1 + 2 = 3
    printf("a= %d\n", a);
    b = ADD(c,d);               // b = 3 + 4 = 7 
    printf("b= %d\n", b);       
    printf("ADD(a,b)= %d\n", ADD(a,b));
    printf("ADD(c,d)= %d\n", ADD(c,d));
    printf("ADD(a,b) * ADD(c,d)= %d", ADD(a,b) * ADD(c,d));   // this equals  a+b*c+d = 3 + 7 * 3 + 4 = 28
    
    return ADD(a,b) * ADD(c,d); // (3+7) * (3+4) = 70  however answer equals 28 WHY ???
}

int main(){
    int32_t a = 1, b = 2, c = 3, d = 4;
    int32_t ans = multiple(a,b,c,d);

    assert(COMPARE(5, 3) > 0);
    
    return 0;
}