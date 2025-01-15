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
public:
    sunshine(): character(100),timer(std::chrono::microseconds(time_num)){
        IMAGE image;
        loadimage(&image,",,/resourse/character/sunshine/1.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/2.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/3.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/4.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/5.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/6.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/7.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/8.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/9.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/10.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/11.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/12.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/13.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/14.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/15.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/16.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/17.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/18.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/19.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/20.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/21.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/22.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/23.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/24.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/25.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/26.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/27.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/28.png");
        image_list.push_back(image);
        loadimage(&image,",,/resourse/character/sunshine/29.png");
        image_list.push_back(image);
    }
    void display(int idx) override{

        putimagewithTransparent(0,0,&image_list[image_loop]);

        timer.get_delay();
        if(timer.can_change_content()){
            image_loop++;
            if(image_loop == image_list.size()){
                image_loop = 0;
            }
        }
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNSHINE_H
