#include <stdio.h>

int main(void){
    int input;

    printf("원하는 값을 입력해 주세요.");
    scanf("%d",&input); // 메모리에 scanf에서 받은 값을 넣는거니까 포인터가 와야
    printf("입력값 : %d\n",input);

    return 0;
}
