#include <stdio.h>

int main(void){
    int one, two, three;

    printf("원하는 값 3개를 입력해 주세요");
    scanf("%d %d %d",&one,&two,&three); // 메모리에 scanf에서 받은 값을 넣는거니까 포인터가 와야
    printf("입력값 : %d,%d,%d\n",one,two,three);

    char str[256];
    printf("원하는 문자열을 공백없이 입력해 주세요 : ");
    scanf("%s",&str);
    printf("입력된 문자열 : %s",str);

    return 0;
}
