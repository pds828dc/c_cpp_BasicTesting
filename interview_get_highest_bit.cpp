// interview_get_highest_bit
#include"stdio.h"
bool isPow2(unsigned int data){
    return (data==0)?false:!(data & (data - 1));
}
int countBit1(unsigned data){
    int count = 0;
    while(data>0){
        data = data & (data - 1);  // 消除最低位元
        count++;
    }
    return count;
}

int getLowb(unsigned int data){        // 取得最低位元遮罩 
    int tmp = data & (-data);         
    return tmp;
}
int getHighWindow(unsigned int data){  // 取得最高位元遮罩 
    while( (data&(data-1)) !=0 ){
        data &= (data - 1);
    }
    return data;
}
int getHighb(unsigned int data){
    int n = 31;
    if(data==0) return -1;
    if( (data>>16)==0 ){data=data<<16; n = n-16;}
    if( (data>>24)==0 ){data=data<< 8; n = n-8;}
    if( (data>>28)==0 ){data=data<< 4; n = n-4;}
    if( (data>>30)==0 ){data=data<< 2; n = n-2;}
    if( (data>>31)==0 ){data=data<< 1; n = n-1;}
    return n;
}
int main(){
    int data = 0x070f0a04;       //  high:26  low:2  bits:10
    int highb = getHighb(data);
    unsigned int t = 0;
    printf("(unsigned)0-1=%u\n", t -1);
    printf("The highest bit of data at %dth position\n",highb);
    int lowb = getLowb(data);
    printf("The lowest bit of data at %dth position\n",lowb);
    int bits = countBit1(data);
    printf("Number of '1' of data =%d\n", bits);
    int testp = 0;
    if(isPow2(testp)){
        printf("yes!!");
    }else{
        printf("Nope!%d";
    }

    return 0;
}