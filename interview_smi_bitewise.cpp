// c bitwise operation: bit3 set and erase
#include"stdio.h"
#include"stdint.h"
void setAndEraseBit3(uint32_t *val, bool set){
    if(set){
        *val = *val | 0x00000004;
    }else{
        *val = *val & 0xfffffffb;
    }
}
void printBinaryCode(uint32_t val){
    uint32_t window = 0x80000000;
    printf("binary code: ");
    for (int i = 0; i < 32; i++){
        if(val & window){
            printf("1");
        }
        else{
            printf("0");
        }
       
        window = window >> 1;
    }
    printf("\n");
}

int main(){
    uint32_t test[] = {0x12345678,0xffffffff,0x00000000};
    printf("Before set test[0]\n");
    printBinaryCode(test[0]);
    printf("After set test[0]\n");
    setAndEraseBit3(test, true);
    printBinaryCode(test[0]);
    printf("After erase test[0]\n");
    setAndEraseBit3(test, false);
    printBinaryCode(test[0]);
    
    printf("Before set test[1]\n");
    printBinaryCode(test[1]);
    printf("After set test[1]\n");
    setAndEraseBit3(test+1, true);
    printBinaryCode(test[1]);
    printf("After erase test[1]\n");
    setAndEraseBit3(test+1, false);
    printBinaryCode(test[1]);

    printf("Before set test[2]\n");
    printBinaryCode(test[2]);
    printf("After set test[2]\n");
    setAndEraseBit3(test+2, true);
    printBinaryCode(test[2]);
    printf("After erase test[2]\n");
    setAndEraseBit3(test+2, false);
    printBinaryCode(test[2]);
    return 0;
}