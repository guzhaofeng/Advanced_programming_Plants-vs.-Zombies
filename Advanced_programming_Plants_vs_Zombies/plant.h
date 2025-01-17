#include "all_header_file.h"
#include "character.h"
#include "timer.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PLANT_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PLANT_H

int time_num = 100000;

class plant :public character{
private:
    vector<IMAGE> living;
    int animation_loop=0;

    Timer timer;
    Timer timer2;

    IMAGE card;
    int card_x,card_y,card_width,card_height;
    int card_idx;
public:
    int sunshine_deplete;

    plant(const char* card_address,const vector<const char*>& living_address,int card_idx,int deplete) : character(300),card_idx(card_idx),timer(std::chrono::microseconds(time_num)),timer2(std::chrono::microseconds(time_num)),sunshine_deplete(deplete) { // 假设 300 是植物的生命值
        loadimage(&card, card_address);

        for(const char* address : living_address){
            IMAGE image;
            loadimage(&image,address);
            living.push_back(image);
        }

        card_x = 24+card_idx*66;
        card_y = 6;
        card_width = 64;
        card_height = 89;
    }

    plant(plant* plant1,int y) : character(plant1->health), timer(std::chrono::microseconds(time_num)),timer2(std::chrono::microseconds(time_num)),animation_loop(0){

        card_x = 24+card_idx*66;
        card_y = 6;
        card_width = 64;
        card_height = 89;
        card_idx = plant1->card_idx;

        for(auto& image : plant1->living){
            living.push_back(image);
        }

        position = y;
        cout << "you are in plant copy function" << endl;
    }


    void display(int path_idx) override{

        putimagewithTransparent(position,385+path_idx*100,&living[animation_loop]);

        timer.get_delay();
        if(timer.can_change_content()){
            animation_loop++;
        }

        if(animation_loop>=living.size()){
            animation_loop = 0;
        }
    }

    void display_in_puting_a_card(int x,int y){
        putimagewithTransparent(x - card_width/2,y - card_height/2,&living[0]);
    }

    void card_display(int idx){
        putimage(card_x,card_y,&card);
    }

    [[nodiscard]] inline int can_touch_card(int a,int b) const{
        if(card_x<=a && a<card_x+card_width && card_y<=b && b<card_y+card_height){
            cout << "a card is in touch" << endl;
            return card_idx;
        }
        return 0;
    }

    bool be_attacked(int attack){
        timer2.get_delay();
        if(timer2.can_change_content()){
            health -= attack;
        }
        if(health <= 0){
            return true;
        }
        return false;
    }

    void set_position(int idx){
        position = 115 + (idx-1)*81;
    }

    virtual Status progress(Status status) override = 0;

    virtual Status get_plant_name() = 0;
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PLANT_H
