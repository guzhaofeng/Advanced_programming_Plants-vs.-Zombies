#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ALL_HEADER_FILE_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ALL_HEADER_FILE_H

#include <iostream>
#include "graphics.h"
#include <algorithm>
#include <conio.h>
#include <vector>
#include <string>
#include <stack>
#include <windows.h>
#include <unistd.h>
#include <chrono>
#include <queue>
#include <list>

using namespace std;

enum Status{

    over,
    ing,

    is_in_touch,

    change_to_choose_game,
    change_to_sunwaterday_game,
    change_to_sunday_game,
    change_to_game_over,

    touch_a_card,
    game_over,

    can_attack,
    can_not_attack,

    make_a_peashooter_attack,
    make_a_sunshine,

    name_sunflower,
    name_peashooter
};

void putimagewithTransparent(int x,int y,IMAGE* temp,IMAGE* back_ground){
    putimage(x,y,back_ground,SRCAND);
    putimage(x,y,temp,SRCPAINT);
}

void putimagewithTransparent(int x,int y,IMAGE* temp){

    IMAGE img = *temp;
    IMAGE img1;
    DWORD *d1;
    img1=img;
    d1=GetImageBuffer(&img1);
    float h,s,l;
    for(int i=0;i<img1.getheight()*img1.getwidth();i++){
        RGBtoHSL(BGR(d1[i]),&h,&s,&l);
        if(l<0.002){
            d1[i]=BGR(WHITE);
        }
        if(d1[i]!=BGR(WHITE)){
            d1[i]=0;
        }
    }
    putimage(x,y,&img1,SRCAND);
    putimage(x,y,&img,SRCPAINT);
}





#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ALL_HEADER_FILE_H
