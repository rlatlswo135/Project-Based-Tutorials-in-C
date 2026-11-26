#include <stdio.h>

int main(void){
    int a = 1;
    int b = 2;
    int c = 3;

    printf("a의 주소 = %p\n",&a);
    printf("b의 주소 = %p\n",&b);
    printf("c의 주소 = %p\n",&c);

    int* hidden = &a;
    printf("hidden, 누구꺼 훔쳤냐 = %d\n",*hidden);
    hidden = &b;
    printf("hidden, 누구꺼 훔쳤냐 = %d\n",*hidden);
    hidden = &c;
    printf("hidden, 누구꺼 훔쳤냐 = %d\n",*hidden);
    *hidden = 100;
    printf("hidden = %d, c = %d\n",*hidden,c);

    int arr[3] = {1,2,3};
    int* p_arr = arr;

    printf("%d\n",*(p_arr+2));
    printf("%d\n",arr[0]);

    return 0;
}
