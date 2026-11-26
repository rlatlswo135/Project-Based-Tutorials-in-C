#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;

    *a = *b;
    *b = temp;
}

int main(void){
    int a = 1;
    int b = 10;

    printf("before: %d, %d\n",a,b);
    swap(&a,&b);
    printf("after: %d, %d\n",a,b);
    return 0;
}
