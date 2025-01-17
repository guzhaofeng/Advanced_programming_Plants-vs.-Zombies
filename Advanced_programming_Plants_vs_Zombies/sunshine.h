#include "all_header_file.h"
#include "character.h"
#include "timer.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNSHINE_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNSHINE_H


class sunshine : character{
private:
    vector<IMAGE> image_list;
    int image_loop = 0;
    Timer timer;
    int x_idx;
    int y_idx;
    int random = rand()%100-50;

    int sunshine_value = 25;
public:

    int touch_sunshine(int x,int y){
        if(x_idx*81+34+random<=x && x<x_idx*81+114+random && 420+y_idx*100+random/2<=y && y<520+y_idx*100+random/2){
            return sunshine_value;
        }
        return 0;
    }

    void display(int temp) override{

        putimagewithTransparent(x_idx*81+34 + random,420+y_idx*100 + random/2,&image_list[image_loop]);

        timer.get_delay();
        if(timer.can_change_content()){
            image_loop++;
            if(image_loop == image_list.size()){
                image_loop = 0;
            }
        }
    }

    Status progress(Status status) override{
        return ing;
    }

    sunshine(int idx,int idx2): character(100),timer(std::chrono::microseconds(time_num)),x_idx(idx),y_idx(idx2){
        IMAGE image;
        loadimage(&image,"../resourse/character/sunshine/1.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/2.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/3.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/4.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/5.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/6.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/7.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/8.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/9.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/10.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/11.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/12.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/13.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/14.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/15.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/16.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/17.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/18.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/19.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/20.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/21.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/22.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/23.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/24.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/25.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/26.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/27.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/28.png");
        image_list.push_back(image);
        loadimage(&image,"../resourse/character/sunshine/29.png");
        image_list.push_back(image);
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNSHINE_H
