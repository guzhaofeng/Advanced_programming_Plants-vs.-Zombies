#include "all_header_file.h"
#include "plant.h"
#include "timer.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_WALLNUT_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_WALLNUT_H


class wallnut : public plant{
private:
    vector<IMAGE> living1;
    vector<IMAGE> living2;

    int animation_loop1 = 0;
    int animation_loop2 = 0;
public:
    wallnut(int idx): plant("..\\resourse\\character\\plants\\wallnut\\card.png",{
        "..\\resourse\\character\\plants\\wallnut\\full1.png",
        "..\\resourse\\character\\plants\\wallnut\\full2.png",
        "..\\resourse\\character\\plants\\wallnut\\full3.png",
        "..\\resourse\\character\\plants\\wallnut\\full4.png",
        "..\\resourse\\character\\plants\\wallnut\\full5.png",
        "..\\resourse\\character\\plants\\wallnut\\full6.png",
        "..\\resourse\\character\\plants\\wallnut\\full7.png",
        "..\\resourse\\character\\plants\\wallnut\\full8.png",
        "..\\resourse\\character\\plants\\wallnut\\full9.png",
        "..\\resourse\\character\\plants\\wallnut\\full10.png",
        "..\\resourse\\character\\plants\\wallnut\\full11.png",
        "..\\resourse\\character\\plants\\wallnut\\full12.png",
        "..\\resourse\\character\\plants\\wallnut\\full13.png",
        "..\\resourse\\character\\plants\\wallnut\\full14.png",
        "..\\resourse\\character\\plants\\wallnut\\full15.png",
        "..\\resourse\\character\\plants\\wallnut\\full16.png"
    },idx,50){
        health = 1200;

        IMAGE image;

        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break1.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break2.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break3.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break4.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break5.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break6.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break7.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break8.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break9.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break10.png");
        living1.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\break11.png");
        living1.push_back(image);

        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\1.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\2.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\3.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\4.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\5.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\6.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\7.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\8.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\9.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\10.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\11.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\12.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\13.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\14.png");
        living2.push_back(image);
        loadimage(&image,"..\\resourse\\character\\plants\\wallnut\\15.png");
        living2.push_back(image);

    }

    void display(int path_idx) override{

        if(health >= 600){
            putimagewithTransparent(position,386+path_idx*100,&living[animation_loop]);

            timer.get_delay();
            if(timer.can_change_content()){
                animation_loop++;
            }

            if(animation_loop>=living.size()){
                animation_loop = 0;
            }
        }else if(health<600 && health>=300){
            putimagewithTransparent(position,386+path_idx*100,&living1[animation_loop1]);

            timer.get_delay();
            if(timer.can_change_content()){
                animation_loop1++;
            }

            if(animation_loop1>=living1.size()){
                animation_loop1 = 0;
            }
        }else if(health<300){
            putimagewithTransparent(position,390+path_idx*100,&living2[animation_loop2]);

            timer.get_delay();
            if(timer.can_change_content()){
                animation_loop2++;
            }

            if(animation_loop2>=living2.size()){
                animation_loop2 = 0;
            }
        }
    }

    Status progress(Status status) override{
        return ing;
    }

    Status get_plant_name() override{
        return name_wallnut;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_WALLNUT_H
