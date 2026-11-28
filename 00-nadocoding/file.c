#include <stdio.h>

#define MAX 10000

int main(void){
    // 파일 입출력
    // 파일에 데이터 저장
    // 파일에 저장된 데이터 불러오기

    // fputs, fgets 쌍 => 주로 문자열 저장
    char line[MAX];
    FILE* file = fopen("../file-test.md","rwb");
    // fprintf, fscanf
    if(file == NULL){
        printf("파일 열기 실패");
        return 1;
    }

    fputs("fputs를 이용해서 글을 적어보기.\n",file);
    fputs("잘 적히는지 확인해 주세요.\n",file);

    while(fgets(line,MAX,file) != NULL){
        printf("%s",line);
    }

    fclose(file);

    // fprintf, fcanf 쌍 =>
    int num[6] = {0,0,0,0,0,0};
    int bonus = 0;
    char str1[MAX];
    char str2[MAX];
    FILE* file2 = fopen("../file-test2.md","wb");

    if(file == NULL){
        printf("파일 열기 실패2");
        return 1;
    }

    fprintf(file2, "%s %d %d %d %d %d %d\n","추첨번호:",1,2,3,4,5,6);
    fprintf(file2, "%s %d\n","보너스번호:",7);

    fscanf(file2, "%s %d %d %d %d %d %d",str1,&num[0],&num[1],&num[2],&num[3],&num[4],&num[5]);
    printf("%s %d %d %d %d %d %d\n",str1, num[0],num[1],num[2],num[3],num[4],num[5]);

    fscanf(file2, "%s %d",str2,&bonus);
    printf("%s %d",str2,bonus);

    fclose(file2);
    return 0;
}
