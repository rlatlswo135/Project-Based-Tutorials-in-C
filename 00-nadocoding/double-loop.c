#include <stdio.h>

int main(void){
    int max;
    printf("층수를 입력해 주세요.\n");
    scanf("%d",&max);

    int star = 1;
    int space = max - 1;

    for(int i = 1; i<= max; i++){
        for(int j=1; j<= space; j++){
            printf(" ");
        }
        for(int z=1; z<=star; z++){
            printf("*");
        }
        printf("\n");
        space--;
        star+=2;
    }
    return 0;
}
