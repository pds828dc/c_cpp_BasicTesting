// c: find the answer of the series
// 1+2+4+7+11+...+106 = ?
#include"stdio.h"

int main(){
    int ans = 0, tmp = 1;         // 這是一個具有等差數列性質的差級數
    for(int i = 0; i<15; i++){    // 而106剛好是這個級數的第15項
        tmp+=i;
        ans += tmp;
    }
        printf("Answer of the series=%d", ans);
    return 0;
}