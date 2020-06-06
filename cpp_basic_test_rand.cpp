#include<iostream>
#include"time.h"

using namespace std;

int main(){ 
    srand(time(NULL));
    int dice = rand()%8;
    for(int i = 0; i<3; i++)
    {
        (dice%2)?printf("1"):printf("0");
        dice = dice / 2;
    }
    return 0;
}