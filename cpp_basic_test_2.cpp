// big letter&little letter Exchange 
#include<iostream>

using namespace std;

int main()
{
    char t_c_s = 'string';
    char t_s_s [] = "string";

    char ascii_word1 = 65;
    char letter_case_exchange = 32;
    char exchanged_word = ascii_word1 ^ letter_case_exchange;
    char exchanged_word2 = exchanged_word ^ letter_case_exchange;
    char ending_word = '\0';

    cout << "print char array by ascii" << endl;
    for (int i = 0;i< sizeof(t_s_s); i++){
        printf("%d ,", t_s_s[i]);
    }
    printf("\n");

    cout << "C char array Test: "
         << "t_c_s = " << t_c_s << "\n\n"
         << "t_s_s = " << t_s_s << endl;
    printf("Show the invisible character: t_s_s[6]=%d Ending word =%d \n", t_s_s[6], ending_word);
    printf("sizeofTest: char=%d byte   array of char=%d byte \n",sizeof(t_c_s),sizeof(t_s_s) );
    printf("C Char & ASCII Test: 65=%c 97=%c cc=%c ccc=%c",ascii_word1,ascii_word1+32,exchanged_word,exchanged_word2);

    return 0; 
}