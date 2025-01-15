#include "all_header_file.h"
#include "zombie.h"
#include "plant.h"
#include "timer.h"
#include <list>

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SINGLE_PATH_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SINGLE_PATH_H


class single_path {
public:
    list<zombie*> zombie_list;
    vector<plant*> plant_queue;

    int path_num;
    bool is_day_not_night;
    bool is_land;

public:
    single_path(int path_num,bool is_day_not_night,bool is_land):path_num(path_num),is_day_not_night(is_day_not_night),is_land(is_land){
        for (int i = 0; i < 10; ++i) {
            plant_queue.push_back(nullptr);
        }

        mciSendString("open ../resourse/game/cardLift.mp3 alias cardLift", nullptr,0,nullptr);
    }

    ~single_path(){
        for (auto temp : zombie_list) {
            delete temp;
            temp = nullptr;
        }
        for (auto temp : plant_queue) {
            delete temp;
            temp = nullptr;
        }
    }

    void display(){

        for (auto temp : plant_queue) {
            if(temp){
                temp->display(path_num);
            }
        }

        auto it = zombie_list.begin();
        while(it != zombie_list.end()){
            (*it)->display(path_num);
            it++;
        }
    }

    [[nodiscard]] int can_touch(int x,int y) const{
        if(115<=x && x<849 && 381+path_num*108<=y && y<381+path_num*108+108){
            int result = (x-115)/81 + 1;
            if(plant_queue[result]){
                return 0;
            }
            return result;
        }
        return 0;
    }

    Status progress(){//僵尸和植物的动作

        auto it = zombie_list.begin();
        while(it != zombie_list.end()){
            int x = (*it)->get_position();
            int idx = (x-115)/81+2;

            if(plant_queue[idx]){
                Status result;
                if(*it){
                    result = (*it)->progress(can_attack);
                }else{
                    cout << "it is nullptr" << endl;
                }

                if(result == game_over){
                    return game_over;
                }

                if(plant_queue[idx]->be_attacked((*it)->attack)){
                    plant* will_be_delete = plant_queue[idx];
                    plant_queue[idx] = nullptr;
                    delete will_be_delete;
                }
            }else{
                if(*it){
                    (*it)->progress(can_not_attack);
                }else{
                    cout << "it is nullptr" << endl;
                }
            }
            it++;
        }

        for (int i = 1; i < 10; ++i) {
            if(plant_queue[i]){
                Status result = ing;
                if(!zombie_list.empty() && zombie_list.front()->get_position() >= i*81+115){
                    result = plant_queue[i]->progress(can_attack);
                }else{
                    result = plant_queue[i]->progress(can_not_attack);
                }

                if(result==make_a_sunshine){

                }else if(result==make_a_peashooter_attack){

                }
            }
        }

        return ing;
    }

    Status progress(int idx,plant* new_plant){//种植物
        mciSendString("seek cardLift to 0", nullptr,0,nullptr);
        mciSendString("play cardLift", nullptr,0,nullptr);

        plant_queue[idx] = new_plant;

        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SINGLE_PATH_H
