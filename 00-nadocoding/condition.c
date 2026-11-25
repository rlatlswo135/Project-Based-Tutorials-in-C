#include <stdio.h>

int main(void){
    int age;
    printf("나이를 입력해 주세요 : ");
    scanf("%d",&age);

    if(age>=20)
        printf("성인 입니다.\n");
    else if(age >= 17)
        printf("고등학생 입니다.\n");
    else
        printf("출입이 제한됩니다.");

    return 0;
}
