#include <stdio.h>

int main(void){
    int count = 5;

    for(int i = 1; i <= count; i++){
        printf("카운트 입니다. %d\n",i);
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
