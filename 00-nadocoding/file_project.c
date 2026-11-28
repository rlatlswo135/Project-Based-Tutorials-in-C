#include <stdio.h>
#include <string.h>

#define MAX 10000

void sayHello(){
    printf("비밀일기에 오신결 환영합니다.\n");
    printf("비밀번호를 입력하세요 : ");
}

void successOpen(){
    printf("******** 비밀일기가 열렸습니다 ********\n");
    printf("오늘의 일기를 입력해 주세요.\n");
}

void writeDiary(FILE* diary){
    char contents[MAX];

    fgets(contents,MAX,stdin);
    fputs(contents,diary);
}

void readDiary(FILE* diary){
    char line[MAX];
    rewind(diary);
    while(fgets(line,MAX,diary) != NULL){
        printf("%s",line);
    }
}

int main(void){
    // fgets, fputs 활용
    char line[MAX]; // 파일에서 불러올 내용
    char contents[MAX]; // 입력할 내용
    char password[20]; // 비밀번호
    const int COUNT = 3;
    int passwordCount = 0;

    sayHello();

    while(1){
        scanf("%s",password);

        if(strcmp(password,"rlatlswo") == 0){
            break;
        }else{
            if(passwordCount == COUNT){
                printf("다음에 다시 시도해주세요.");
                return 1;
            }
            passwordCount++;
            printf("비밀번호가 틀렸습니다. 다시한번 입력해주세요. : \b");
        }
    }
    // 왜해야하는건지? stdin에 enter가 남아있어서 writeDiary때 fgets이 바로 끝나버리는거라던데
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }

    successOpen();

    FILE* diary = fopen("../diary.md","a+");
    writeDiary(diary);
    readDiary(diary);

    fclose(diary);

    return 0;
}
