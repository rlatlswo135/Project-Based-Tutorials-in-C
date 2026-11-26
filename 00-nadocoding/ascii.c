#include <stdio.h>

int main(void){
    int asci = 128;

    for(int i=0; i < asci; i++){
        printf("아스키 코드 %d = %c\n",i,i);
    }
    return 0;
}
