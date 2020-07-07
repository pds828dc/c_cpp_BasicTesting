// c bitwise operation: bit3 set and erase
#include"stdio.h"
#include"stdint.h"
#define BIT_3 (0X1<<3)

void setAndEraseBit3_V2(uint32_t *val, bool set){
    if(set){
        *val |= BIT_3;
    }else{
        *val &= ~BIT_3;
    }
}
void setAndEraseBitn(uint32_t *val, int n, bool set){
    if(set){
        *val |= (1 << n);
    }else{
        *val &= ~(1 << n);
    }
} 
void setAndEraseBit3(uint32_t *val, bool set){
    if(set){
        *val = *val | 0x00000008;
    }else{
        *val = *val & 0xfffffff7;
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
    printf("BIT_3=%d\n", BIT_3);
    printf("Before set test[0]\n");
    printBinaryCode(test[0]);
    printf("After set test[0]\n");
    setAndEraseBit3_V2(test, true);
    setAndEraseBitn(test, 4,true);
    printBinaryCode(test[0]);
    printf("After erase test[0]\n");
    setAndEraseBit3_V2(test, false);
    setAndEraseBitn(test, 4,false);
    printBinaryCode(test[0]);
    
    printf("Before set test[1]\n");
    printBinaryCode(test[1]);
    printf("After set test[1]\n");
    setAndEraseBit3_V2(test+1, true);
    setAndEraseBitn(test+1, 4,true);
    printBinaryCode(test[1]);
    printf("After erase test[1]\n");
    setAndEraseBit3_V2(test+1, false);
    setAndEraseBitn(test+1, 4,false);
    printBinaryCode(test[1]);

    printf("Before set test[2]\n");
    printBinaryCode(test[2]);
    printf("After set test[2]\n");
    setAndEraseBit3_V2(test+2, true);
    setAndEraseBitn(test+2, 4,true);
    printBinaryCode(test[2]);
    printf("After erase test[2]\n");
    setAndEraseBit3_V2(test+2, false);
    setAndEraseBitn(test+2, 4,false);
    printBinaryCode(test[2]);
    return 0;
}