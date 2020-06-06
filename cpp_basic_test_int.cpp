#include"stdio.h"

int main(){
    int TestForDataType1;
    short TestForDataType2;
    long TestForDataType3;
    long long TestForDataType4;
    float TestForDataType5;
    double TestForDataType6;
    int TestForIntArray[] = {1,2,3,4,5,6};

    // 1. USING A RANGE-BASED FOR LOOP
    int sum = 0;
    for (int x : TestForIntArray) {
        sum += x;
    }
    printf("sum=%d\n", sum);

    printf("the sizeof Int in this computer is %d byte address at %x\n\n",sizeof(TestForDataType1), &TestForDataType1);    // int == 4 byte == 32bits in  MinGW-w64 GNU 8.1.0
    printf("the sizeof short in this computer is %d byte address at %x\n\n",sizeof(TestForDataType2), &TestForDataType2);
    printf("the sizeof long in this computer is %d byte address at %x\n\n",sizeof(TestForDataType3), &TestForDataType3);
    printf("the sizeof long long in this computer is %d byte address at %x\n\n",sizeof(TestForDataType4), &TestForDataType4);

    printf("the sizeof float in this computer is %d byte address at %x\n\n",sizeof(TestForDataType5), &TestForDataType5);
    printf("the sizeof double in this computer is %d byte address at %x\n\n",sizeof(TestForDataType6), &TestForDataType6);

    printf("the sizeof Array of Int in this computer is %d byte address at %x\n\n", sizeof(TestForIntArray), &TestForIntArray) ;
    
}