// algorithm test : quick sort
// Ref: data structure fundamental p.403 - p.405
#include<iostream>
#include"stdlib.h"
using namespace std;
void cswap(int* a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int * array, int front, int end){
    if(end>front){                             //    終止條件: 上一次的 pivot == 邊界時
        int i = front;
        int pivot = array[end];
        for (int j = front; j < end; j++){
            if (array[j] < pivot){             //     將比pivot小的數字囤積在子數列的前面 最後再把pivot插到中間
                swap(array[i], array[j]);
                i++;
            }
        }
        cswap(&array[i], &array[end]);
        quick_sort(array, front, i - 1);
        quick_sort(array, i+1, end);
    }
}

int main(){
    int data[] = {5,9,3,7,8,6,4,2,1,10};
    int len = sizeof(data) / sizeof(*data);
    for (int i = 0; i<len ;i++){
        cout << data[i];
        if(i!=len-1){
            cout << " ";
        }
    }
    cout << endl;
    quick_sort(data, 0, len-1);
    for (int i = 0; i<len ;i++){
        cout << data[i];
        if(i!=len-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}