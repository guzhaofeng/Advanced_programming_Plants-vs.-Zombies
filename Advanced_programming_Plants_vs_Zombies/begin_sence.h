#include "all_header_file.h"
#include "sence.h"
#include "button.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BEGIN_SENCE_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BEGIN_SENCE_H

class begin_sence : public sence{
private:
    IMAGE back_ground;
    button begin_game;
public:
    begin_sence(): begin_game(450,300,0,0,1,{"../resourse/begin/menu1.png","../resourse/begin/menu2.png"}){
        loadimage(&back_ground,"../resourse/begin/menu.png");//加载背景
    }

    void display() override{
        putimage(0,0,&back_ground);
        begin_game.display();
    }

    Status progress(ExMessage &msg) override{
        if(msg.message == WM_LBUTTONDOWN && begin_game.can_touch(msg.x,msg.y)){
            return change_to_choose_game;
        }
        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BEGIN_SENCE_H
