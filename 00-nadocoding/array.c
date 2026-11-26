#include <stdio.h>

int main(void){
    char str[] = "bcd";
    char kor_str[] = "가나다라마";
    printf("sizeof : %zu\n",sizeof(str)); // 영어 1char = 1byte
    printf("sizeof-kor : %zu\n",sizeof(kor_str)); // 한글 1char = 2byte

    for(int i=0; i<sizeof(str); i++){
        // 마지막이 비어있는데 그게 null문자
        printf("char = %c\n",str[i]);
    }

    char name[5];
    printf("이름을 입력해주세요.\n");
    printf("이름 = %s\n",name);
    /*
     * scanf할때 사이즈지정안하면 할당된 메모리를 넘어서 저장되는 버퍼오버플로우 발생가능성이 있다.
     * window의 scanf_s는 3번째인자에 사이즈를 받을수있는데 없으니, scanf에 %3s 이렇게 지정해야함
     */

    return 0;
}
