#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int make_rand(void){
    srand(time(NULL)); // 난수초기화
    return (rand() % 10) + 1;
}

int main(void){
    printf("숫자는 : %d",make_rand());
    return 0;
}
