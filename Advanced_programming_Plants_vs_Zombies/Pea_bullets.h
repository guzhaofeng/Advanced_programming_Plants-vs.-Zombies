#include "all_header_file.h"
#include "timer.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PEA_BULLETS_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PEA_BULLETS_H


class Pea_bullets {
private:
    IMAGE normal;
    IMAGE explode;

    Timer timer;

    int y_position;
public:
    int x_position;
    int die_time = 5;

    Pea_bullets(int x,int y):timer(std::chrono::microseconds(time_num)){
        x_position = x*81+115;
        y_position = y*100+390;
        loadimage(&normal,"../resourse/Pea_bullets/PeaNormal_0.png");
        loadimage(&explode,"../resourse/Pea_bullets/PeaNormalExplode_0.png");

        mciSendString("open ../resourse/Pea_bullets/hit.mp3 alias hit", nullptr,0,nullptr);
    }

    void display_normal(){
        putimagewithTransparent(x_position,y_position,&normal);
        timer.get_delay();
        if(timer.can_change_content()){
            x_position+=10;
        }
    }
    void display_explode(){
        if(die_time == 5){
            mciSendString("seed hit to 0", nullptr,0,nullptr);
            mciSendString("play hit", nullptr,0,nullptr);
            putimagewithTransparent(x_position,y_position,&explode);
        }else{
            timer.get_delay();
            if(timer.can_change_content()){
                die_time--;
            }
            putimagewithTransparent(x_position,y_position,&explode);
        }
    }

};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PEA_BULLETS_H
