#include <stdio.h>

void func() {
	static int x = 0;    // 只有在第一次的函式呼叫初始化為0
	printf("%d\n", x);   
	x += 1;
}

int main(int argc, char * const argv[]) {
	for(int i =0 ; i<3 ; i++){
        func();
    }
    printf("argc=%d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    printf("\n");
    return 0;
}