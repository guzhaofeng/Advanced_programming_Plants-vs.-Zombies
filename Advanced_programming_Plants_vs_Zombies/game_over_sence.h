#include "all_header_file.h"
#include "timer.h"
#include "sence.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_GAME_OVER_SENCE_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_GAME_OVER_SENCE_H


class game_over_sence : public sence{

private:
    IMAGE words;
    int x = 450;
    int y = 300;
    int size = 10;
    int speed = 10;
    int width = 498;
    int height = 439;



    double transform = 0.0;
public:
    game_over_sence(){
        mciSendString("open ../resourse/game_over/zombieLaugh.mp3 alias zombieLaugh", nullptr,0,nullptr);
        mciSendString("play zombieLaugh", nullptr,0,nullptr);
    }

    void display(ExMessage &msg){
        BeginBatchDraw();

        loadimage(&words,"../resourse/game_over/game_over.png",width* transform,height*transform);
        if(transform > 0){
            putimagewithTransparent(x-width/2*transform,y-height/2*transform,&words);
        }

        if(transform < 0.9){
            transform+=0.01;
        }else if(transform>=0.9 && transform <= 1.1){
            transform+=0.0001;
        }

        FlushBatchDraw();
    }

    Status progress(ExMessage &msg) override{
        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_GAME_OVER_SENCE_H
