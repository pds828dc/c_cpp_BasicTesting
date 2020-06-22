// c: macro for function MIN(a, b)
#include"stdio.h"
#define MIN(a,b) ((a<b)?(a):(b))    //  巨集的本質是字詞替換而非真的創造一個函式
#define SQUARE(x) (x)*(x)           //  在涉及運算時為了確保邏輯正確 需要用括號把輸入項包起來
#define SQUARE_false(x) x*x         //  否則會出現以下錯誤
#define SECOND_YEAR (60*60*24*365+60*60*6)UL

int main(){
    int a=5, b=3, c=6, d=9;
    int e[] = {5, 6, 7};
    int *ptr = e;
    printf("a=%d\tb=%d\tc=%d\td=%d\n", a, b, c, d);
    printf("MIN(a,b)=%d\n", MIN(a, b));
    printf("MIN(c,d)=%d\n", MIN(c, d));
    printf("MIN(a+c,b+d)=%d\n\n", MIN(a+c, b+d));

    printf("SQUARE(a)=%d\n", SQUARE(a));
    printf("SQUARE(a+c)=%d\n\n", SQUARE(a+c));           //  SQUARE(5+6) = (5+6)*(5+6) = 121  正確

    printf("SQUARE_false(a)=%d\n", SQUARE_false(a));
    printf("SQUARE_false(a+c)=%d\n", SQUARE_false(a+c));   //  5+6*5+6 = 5+30+6 = 41  錯誤

    int least = MIN(*ptr++, e[2]);
    printf("MIN(*ptr++, b)=%d", least);
    return 0;
}