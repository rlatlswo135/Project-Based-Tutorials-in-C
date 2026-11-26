#include <stdio.h>

enum Gender {
    MALE,
    FEMALE
};

struct Human {
    char* name;
    int age;
    enum Gender gender;
};

int main(void){
    char* name = "ABC";
    printf("%c\n",*name);

    struct Human human[2] = {{"휴먼1",15,MALE},{"휴먼2",30,FEMALE}};
    struct Human* p_human = human;
    struct Human new_human = {"new_휴먼2",40,MALE};

    *(p_human + 1) = new_human;
    (p_human + 1)->name = new_human.name; // 구조체 포인터필드 접근할땐 ->
    // 동일: p_human->age = (*p_human).age

    for(int i=0; i<2; i++){
        printf("휴먼 -> %s, %d, %d\n",human[i].name,human[i].age,human[i].gender);
    }
    return 0;
}
