#include<stdio.h>
int main(void) {
  char *ptr = "Linux";
  printf("\n [%c] \n",*ptr++);
  printf("\n [%c] \n",*ptr);
  int a[] = {1, 2, 3, 4, 5, 6};
    int *p = a;
    *(p++) += 100;
    *(++p) += 100;

    for(int i=0; i<6; i++){
        printf("%d ", a[i]);
    }
  return 0;
}