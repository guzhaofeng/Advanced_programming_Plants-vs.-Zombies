#include "all_header_file.h"
#include "plant.h"
#include "sunflower.h"
#include "peashooter.h"
#include "wallnut.h"
#include "pepper.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_TOOLBAR_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_TOOLBAR_H


class Toolbar {
protected:
    IMAGE toolbar_image;
    vector<plant*> plant_list;
    int is_in_touch_a_card = 0;
public:
    int get_sunshine_cost(){
        return plant_list[is_in_touch_a_card-1]->sunshine_deplete;
    }

    Toolbar(){
        loadimage(&toolbar_image,"../resourse/game/toolbar.png");
        plant_list.push_back(new sunflower(1));
        plant_list.push_back(new peashooter(2));
        plant_list.push_back(new wallnut(3));
        plant_list.push_back(new pepper(4));
    }

    ~Toolbar(){
        for (auto temp : plant_list) {
            if(temp){
                delete temp;
                temp = nullptr;
            }
        }
    }

    inline void display(){
        putimage(0,0,&toolbar_image);

        for (int i = 0; i < plant_list.size(); ++i) {
            plant_list[i]->card_display(i+1);
        }

    }
    inline void display(int mouse_x,int mouse_y){
        putimage(0,0,&toolbar_image);

        for (int i = 0; i < plant_list.size(); ++i) {
            plant_list[i]->card_display(i+1);
        }

        plant_list[is_in_touch_a_card - 1]->display_in_puting_a_card(mouse_x,mouse_y);
    }

    Status progress(ExMessage &msg){
        if(msg.message == WM_LBUTTONDOWN){//如果按到了卡

            int idx;
            for (auto temp : plant_list) {
                idx = temp->can_touch_card(msg.x,msg.y);
                if(idx!=0){
                    cout << "you have touched a card" << endl;
                    is_in_touch_a_card = idx;
                    return touch_a_card;
                }
            }
        }
        return ing;
    }

    plant* creat_new_plant(int idx){
        cout << "you are in creat_new_plant " << "idx = " << idx << " is_in_touch_num = "  << is_in_touch_a_card << endl;

        Status name = plant_list[is_in_touch_a_card-1]->get_plant_name();
        plant* result;

        if(name == name_sunflower){
            result = new sunflower(1);
        }else if(name == name_peashooter){
            result = new peashooter(0);
        }else if(name == name_wallnut){
            result = new wallnut(1);
        }else if(name == name_pepper){
            result = new pepper(1);
        }

        result->set_position(idx);
        return result;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_TOOLBAR_H
