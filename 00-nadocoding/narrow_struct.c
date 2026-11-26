#include <stdio.h>

struct GameInfo {
    char* name;
    int year;
    int price;
    char* company;

    struct GameInfo* friendGame;
};

typedef struct GameInfo GI;

typedef struct {
    char* name;
    int year;
    int price;
    char* company;

    struct GameInfo* friendGame;
} GameInfo2; // typedef + struct 축약형

void print(struct GameInfo game){
    printf("gameName = %s, company = %s\n",game.name,game.company);
}


int main(void){
    struct GameInfo game = {"Zelda",2026,99000,"Nintendo",NULL};
    struct GameInfo game2 = {"Mario",2025,80000,"GameFreak",&game};

    print(game);
    game.name = "Zelda2";
    game.company = "Nintendo2";
    print(game);
    game2.friendGame->name = "Zelda3";
    game2.friendGame->company = "Nintendo3";
    print(game);


    GI game3 = {"Naruto",2025,75000,"Toai",&game2};
    game3.friendGame->friendGame->name = "Zelda4"; // 중첩 struct. 결국 바라보는건 &game
    game3.friendGame->friendGame->company = "Nintendo4";

    GameInfo2 game4 = {"Metroid",2023,69000,"Unknown",NULL}; // typedef 축약형 가능

    print(game3);
    print(game);

    return 0;
}
