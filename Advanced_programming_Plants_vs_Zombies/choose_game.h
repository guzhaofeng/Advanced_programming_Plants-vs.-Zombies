#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHOOSE_GAME_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHOOSE_GAME_H

#include "all_header_file.h"
#include "sence.h"

class choose_game:public sence{
private:
    IMAGE back_ground;
    int page = 1;
    button sunday_button;
    button sunwaterday_button;
public:
    choose_game(): sunday_button(10,100,424,261,1,
        "","",
        {"../resourse/choose_game/sunday.png","../resourse/choose_game/sunday1.png"},
        {}),
        sunwaterday_button(10+450,100,417,263,1,
        "","",
        {"../resourse/choose_game/sunwaterday.png","../resourse/choose_game/sunwaterday1.png"},
        {})
        {

        loadimage(&back_ground,"../resourse/choose_game/background.png");//加载背景
    }

    ~choose_game() override{

    }

    void display() override{
        putimage(0,0,&back_ground);
    }

    Status progress(ExMessage &msg) override{


        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHOOSE_GAME_H
