// operator Test (--、++)
#include<iostream>
using namespace std;

int main(){
    int a = 3;
    int b = 2;
    int c = -1;
    int d = -2;
    int data[] = {1, 2, 3, 4, 5};
    bool b1 = -1;

    cout << "a/2=" << a / 2 << endl;
    cout << "b/2=" << b / 2 << endl;
    cout << "c/2=" << c / 2 << endl;
    cout << "d/2=" << d / 2 << endl;

    b=a++;
    cout <<  ++b     << "\n"; //   a=3 b=2; b=a a=a+1; b=b+1 cout<< b
    cout << (++b)++  <<"\n";
    cout << --(--b) << endl;

    cout << "---- i++ & ++i show in for loop----" << endl;
    for (int i = 0; i < 5; i++){
        cout << data[i];
    }
    cout << endl;
    for (int i = 0; i < 5; ++i){
        cout << data[i];
    }
    cout << "---- folloeing is tests for types ----" << endl;
    cout << b1 << endl;
    return 0; 
}