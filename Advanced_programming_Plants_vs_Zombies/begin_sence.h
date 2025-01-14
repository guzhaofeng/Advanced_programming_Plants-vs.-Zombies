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
    begin_sence(): begin_game(470,80,331,147,1,
    "button_music","to 40",
    {"../resourse/begin/menu1.png","../resourse/begin/menu2.png"},
    {"../resourse/begin/menu1_background.png","../resourse/begin/menu2_background.png"})
    {
        loadimage(&back_ground,"../resourse/begin/menu.png");//加载背景

        mciSendString("open ../resourse/begin/startUIBgm.mp3 alias background_music", nullptr,0,nullptr);
        mciSendString("play background_music repeat",nullptr,0,nullptr);
        //播放音乐
        mciSendString("open ../resourse/begin/tab.mp3 alias button_music", nullptr,0,nullptr);
    }

    ~begin_sence() override{
        mciSendString("close background_music", nullptr, 0, nullptr);
    }

    void display() override{
        BeginBatchDraw();
        cleardevice();

        putimage(0,0,&back_ground);
        begin_game.display();

        FlushBatchDraw();
    }

    Status progress(ExMessage &msg) override{
        if(msg.message == WM_LBUTTONDOWN && begin_game.can_touch(msg.x,msg.y)){
            return change_to_choose_game;
        }else if(begin_game.can_touch(msg.x,msg.y)){
            begin_game.progress(is_in_touch);
        }else{
            begin_game.progress(ing);
        }

        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BEGIN_SENCE_H
