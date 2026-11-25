#include <stdio.h>

int main(void){
    int count = 5;

    for(int i = 1; i <= count; i++){
        printf("카운트 입니다. %d\n",i);
        if(count == 3){
            printf("3이면 멈춥니다.");
            break;
        }
    }

    int i = 1;
    while(i <= count){
        printf("while 카운트 입니다. %d\n",i++);
    }

    i = 1;
    do{
        printf("do-while 카운트 입니다. %d\n",i++);
    }while(i <= count);

    return 0;
}
