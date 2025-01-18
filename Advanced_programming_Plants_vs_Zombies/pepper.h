#include "all_header_file.h"
#include "plant.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PEPPER_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PEPPER_H


class pepper : public plant{
private:
    vector<IMAGE> living1;
public:
    int animation_loop1 = 0;

    pepper(int idx): plant("../resourse/character/plants/pepper/card.png",
                           {"../resourse/character/plants/pepper/1.png",
                            "../resourse/character/plants/pepper/2.png",
                            "../resourse/character/plants/pepper/3.png",
                            "../resourse/character/plants/pepper/4.png",
                            "../resourse/character/plants/pepper/5.png",
                            "../resourse/character/plants/pepper/6.png",
                            "../resourse/character/plants/pepper/7.png",
                            "../resourse/character/plants/pepper/8.png"
                            },idx,125){
        IMAGE image;

        loadimage(&image,"../resourse/character/plants/pepper/attack1.png");
        living1.push_back(image);
        loadimage(&image,"../resourse/character/plants/pepper/attack2.png");
        living1.push_back(image);
        loadimage(&image,"../resourse/character/plants/pepper/attack3.png");
        living1.push_back(image);
        loadimage(&image,"../resourse/character/plants/pepper/attack4.png");
        living1.push_back(image);
        loadimage(&image,"../resourse/character/plants/pepper/attack5.png");
        living1.push_back(image);
        loadimage(&image,"../resourse/character/plants/pepper/attack6.png");
        living1.push_back(image);
        loadimage(&image,"../resourse/character/plants/pepper/attack7.png");
        living1.push_back(image);
        loadimage(&image,"../resourse/character/plants/pepper/attack8.png");
        living1.push_back(image);

        health = 100000;
    }

    void display(int path_idx) override{
        if(animation_loop < living.size()){
            putimagewithTransparent(position,386+path_idx*100,&living[animation_loop]);
            timer.get_delay();
            if(timer.can_change_content()){
                animation_loop++;
            }
        }


        if(animation_loop>=living.size() && animation_loop1<living1.size()){

            putimagewithTransparent(104,425+path_idx*100,&living1[animation_loop1]);
            timer.get_delay();
            if(timer.can_change_content()){
                animation_loop1++;
            }

        }
    }

    Status progress(Status status) override{
        if(animation_loop1>=living1.size()){
            return pepper_delete;
        }else if(animation_loop >= living.size()){
            return pepper_attack;
        }
        return ing;
    }

    Status get_plant_name() override{
        return name_pepper;
    }

};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PEPPER_H
