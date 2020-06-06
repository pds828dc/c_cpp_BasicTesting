#include"stdio.h"
#include<iostream>
#include <typeinfo>

using namespace std;

int main(){
    int var = 50;
    int  *p;
    p = &var;
    cout << p << endl;
// Outputs 0x29fee8 (var's memory location)    iterator作法輸出二維矩陣
    int arrayTest[3][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for(auto &row:arrayTest){
        cout << typeid(row).name()<<endl;
        for(int col:row){
            printf("%d ", col);
        }
        printf("\n");
    }
}