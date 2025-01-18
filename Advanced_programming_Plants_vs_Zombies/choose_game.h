#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHOOSE_GAME_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHOOSE_GAME_H

#include "all_header_file.h"
#include "sence.h"

extern int level;
extern int money;

class choose_game:public sence{
private:
    IMAGE back_ground;

    int page = 1;

    button sunday_button;
    button sunwaterday_button;

    int begin = 0;
public:
    choose_game(): sunday_button(30,170,424,270,1,
        "tabBlock","to 0",
        {"../resourse/choose_game/sunday.png","../resourse/choose_game/sunday1.png"},
        {}),

        sunwaterday_button(10+450,169,417,263,1,
        "tabBlock","to 0",
        {"../resourse/choose_game/sunwaterday.png","../resourse/choose_game/sunwaterday1.png"},
        {})
        {

        mciSendString("open ../resourse/choose_game/gamingBgm4.mp3 alias choose_game_music", nullptr,0,nullptr);
        mciSendString("play choose_game_music repeat",nullptr,0,nullptr);
            //播放音乐
        mciSendString("open ../resourse/choose_game/tabBlock.mp3 alias tabBlock", nullptr,0,nullptr);
        loadimage(&back_ground,"../resourse/choose_game/background.png");//加载背景
    }

    ~choose_game() override{
        mciSendString("close choose_game_music",nullptr,0,nullptr);
    }

    void display(ExMessage &msg) override{
        BeginBatchDraw();
        cleardevice();

        putimage(0,0,&back_ground);
        sunday_button.display();
        sunwaterday_button.display();

        char str[20];
        setcolor(TRANSPARENT);
        sprintf(str, "level is %d",level);
        settextstyle(30, 0, "Arial");
        outtextxy(770, 480, str);
        sprintf(str, "money is %d",money);
        outtextxy(730, 520, str);

        FlushBatchDraw();
    }

    Status progress(ExMessage &msg) override{
        begin++;
        if(begin<=100){
            return ing;
        }

        if(msg.message == WM_LBUTTONDOWN && sunday_button.can_touch(msg.x,msg.y)){
            return change_to_sunday_game;
        }else if(msg.message == WM_LBUTTONDOWN && sunwaterday_button.can_touch(msg.x,msg.y)){
            if(level < 2){
                return ing;
            }
            return change_to_sunwaterday_game;
        }

        if(sunday_button.can_touch(msg.x,msg.y)){
            sunday_button.progress(is_in_touch);
        }else if(sunwaterday_button.can_touch(msg.x,msg.y)){
            sunwaterday_button.progress(is_in_touch);
        }

        else{
            sunday_button.progress(ing);
            sunwaterday_button.progress(ing);
        }
        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHOOSE_GAME_H
