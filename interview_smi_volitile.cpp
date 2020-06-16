// c: volitile 
#include <stdio.h>
int square_false(volatile int *var)
{
    return *var **var;
}
int square(volatile int *var)
{
    int local = *var;
    return local *local;
}
int main(void)
{
    int var = 3;
    printf("result: %d\n", square(&var));
    return 0;
}