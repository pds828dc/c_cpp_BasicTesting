#include <stdio.h>
#include <setjmp.h>

static jmp_buf buf;

void second(void) {
    printf("second\n");         // 
    longjmp(buf,1);             // 跳回setjmp的取用處 -> 使得setjmp return值為1
}

void first(void) {
    second();
    printf("first\n");          // 不可能執行到此行
}

int main() {   
    if ( ! setjmp(buf) ) {
        first();                // 進入此行前，setjmp return 0
    } else {                    // 當longjmp跳回，setjmp返回1，因此進入此行
        printf("main\n");       // 打印
    }
    return 0;
}