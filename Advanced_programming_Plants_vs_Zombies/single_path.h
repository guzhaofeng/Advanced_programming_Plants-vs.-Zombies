#include "all_header_file.h"
#include "zombie.h"
#include "plant.h"
#include "timer.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SINGLE_PATH_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SINGLE_PATH_H


class single_path {
private:
    list<zombie*> enemy_queue;
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

    void display(){

        for (auto temp : plant_queue) {
            if(temp){
                temp->display(path_num);
            }
        }

    }

    inline int can_touch(int x,int y) const{
        if(115<=x && x<849 && 381+path_num*108<=y && y<381+path_num*108+108){
            int result = (x-115)/81 + 1;
            if(plant_queue[result]){
                return 0;
            }
            return result;
        }
        return 0;
    }

    Status progress(int idx,plant* new_plant){//种植物
        mciSendString("seek cardLift to 0", nullptr,0,nullptr);
        mciSendString("play cardLift", nullptr,0,nullptr);

        plant_queue[idx] = new_plant;
        cout << idx << endl;

        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SINGLE_PATH_H
