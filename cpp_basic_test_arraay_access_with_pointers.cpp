// cpp test array access with pointer
#include"stdio.h"
#include"stdlib.h"
void foo(void){
    
}
int main(){
    static char *s[] ={"black","white","pink","violate","green"};
    char **ptr[] = {s+3,s+2,s+1,s}, ***p;
    p = ptr;
    ++p;
    printf("%s\n", *(*p+1) );    // violate
    printf("%s\n", **(p+1) );    // white
    printf("%s\n", **p+1 );      // ink
    printf("--------------------------test1----------------------------\n\n" );

    int arr[4][4][4][4] = {};
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                for (int l = 0; l < 4; l++){
                    arr[i][j][k][l] = (i << 6) + (j << 4) + (k << 2) + l;    //    +, - 優先度6    <<, >> 優先度7
                    printf("%3d ", arr[i][j][k][l]);
                }
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("array: %1d\n", arr[3][2][1][0]);
    printf("pointer: %d\n", **(*(*(arr + 3) + 2) + 1));
    printf("--------------------------test2----------------------------\n\n" ); 

    
    int x = 30, *y, *z;
    int *ptrx = &x;
    y = &x;
    z = y;
    *y++ = *z++;
    x++;
    printf("ptrz = %16p ptry = %16p\t ptrx = %16p\n", z, y, ptrx);
    printf("z = %19d y = %19d\t x = %19d\n", *z, *y, x);
    printf("--------------------------test3----------------------------\n\n" );

    unsigned int *ptrFree;
    ptrFree = (unsigned int *)malloc(1 * sizeof(unsigned int));
    *ptrFree = 21;
    printf("*ptrFree= %x\n", *ptrFree);
    printf("ptrFree= %p before free\n", ptrFree);
    free(ptrFree);
    printf("*ptrFree= %x\n", *ptrFree);
    printf("ptrFree= %p after free\n", ptrFree);

    printf("--------------------------test4----------------------------\n\n" );

    
    printf("--------------------------test5----------------------------\n\n" ); 

    return 0; // 若是使用stdio的printf輸出 可以在執行可執行檔時 在指令後方加入[空格]>[空格]文件.txt
              // 將螢幕輸出記錄到 文件.txt中 ex: .\cpp_basic_test_arraay_access_with_pointers.exe > result.txt
}