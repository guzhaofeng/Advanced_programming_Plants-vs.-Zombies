#include "all_header_file.h"
#include "zombie.h"
#include "plant.h"
#include "timer.h"
#include "sunshine.h"
#include "Pea_bullets.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SINGLE_PATH_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SINGLE_PATH_H


class single_path {
public:
    list<zombie*> zombie_list;
    vector<plant*> plant_queue;
    list<sunshine*> sunshine_list;
    list<Pea_bullets*> bullets_list;

    int path_num;
    bool is_day_not_night;
    bool is_land;

    Timer timer;
    int sunshine_make_time = 300 + rand()%600;
    int now_shine_time = 100;
public:
    single_path(int path_num,bool is_day_not_night,bool is_land):path_num(path_num),is_day_not_night(is_day_not_night),is_land(is_land),timer(std::chrono::microseconds(time_num)){
        for (int i = 0; i < 10; ++i) {
            plant_queue.push_back(nullptr);
        }

        mciSendString("open ../resourse/game/cardLift.mp3 alias cardLift", nullptr,0,nullptr);
    }

    ~single_path(){
        for (auto temp : zombie_list) {
            if(!temp){
                continue;
            }
            delete temp;
            temp = nullptr;
        }
        for (auto temp : plant_queue) {
            if(!temp){
                continue;
            }
            delete temp;
            temp = nullptr;
        }
        for (auto temp : sunshine_list) {
            if(!temp){
                continue;
            }
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

        for(auto temp : sunshine_list){
            if(temp){
                temp->display(path_num);
            }
        }

        auto it1 = bullets_list.begin();
        while(it1 != bullets_list.end()){
            auto temp = *it1;

            if(temp->x_position>=1000){//对越界的子弹进行处理
                bullets_list.erase(it1);
                delete temp;
                break;
            }

            if(temp){
                zombie* temp_zombie = nullptr;
                for(auto temp1 :zombie_list){
                    if(temp1->zombieAnimationStatus == zombie::wALK || temp1->zombieAnimationStatus == zombie::eAT){
                        temp_zombie = temp1;
                        break;
                    }
                }

                if((temp_zombie && temp_zombie->get_position()<temp->x_position-70) || temp->die_time < 5){
                    temp->display_explode();
                    if(temp->die_time <= 0){
                        bullets_list.erase(it1);
                        delete temp;
                        break;
                    }else if(temp->die_time == 5){
                        temp_zombie->set_health(25);
                        temp->die_time--;
                    }
                }else{
                    temp->display_normal();
                }
            }

            it1++;
        }

        ///////////////////////////
    }

    [[nodiscard]] inline int can_touch(int x,int y) const{
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
        timer.get_delay();
        if(timer.can_change_content()){
            now_shine_time++;
        }
        if(now_shine_time > sunshine_make_time){
            now_shine_time=0;
            sunshine_list.push_back(new sunshine(rand()%4,rand()%5-2));
            sunshine_make_time = 300+rand()%600;
        }

        auto it = zombie_list.begin();
        while(it != zombie_list.end()){
            if((*it)->zombieAnimationStatus == zombie::oVER){
                zombie* temp1 = (*it);
                auto temp2 = it;
                it++;
                delete temp1;
                zombie_list.erase(temp2);
                cout << "zombie is deleted" << endl;
                continue;
            }

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

                zombie* temp_zombie = nullptr;
                for(auto temp :zombie_list){
                    if(temp && (temp->zombieAnimationStatus == zombie::wALK || temp->zombieAnimationStatus == zombie::eAT)){
                        temp_zombie = temp;
                        break;
                    }
                }

                if(temp_zombie && temp_zombie->get_position() >= i*81-100){
                    result = plant_queue[i]->progress(can_attack);
                }else{
                    result = plant_queue[i]->progress(can_not_attack);
                }

                if(result==make_a_sunshine){
                    sunshine* new_sunshine = new sunshine(i,path_num);
                    sunshine_list.push_back(new_sunshine);
                }else if(result==make_a_peashooter_attack){
                    bullets_list.push_back(new Pea_bullets(i,path_num));
                    cout << "make a bullet" << endl;
                }else if(result==pepper_attack){
                    for(zombie* temp1 : zombie_list){
                        if(temp1){
                            temp1->zombieAnimationStatus = zombie::aSHES;
                        }
                    }
                }else if(result==pepper_delete){
                    delete plant_queue[i];
                    plant_queue[i]= nullptr;
                }
            }
        }

        return ing;
    }

    int get_sunshine(int x,int y){
        auto it = sunshine_list.begin();
        while(it != sunshine_list.end()){
            auto temp = *it;
            int result = temp->touch_sunshine(x,y);
            if(result!=0){
                sunshine_list.erase(it);
                delete temp;
                return result;
            }
            it++;
        }

        return 0;
    }

    Status progress(int idx,plant* new_plant){//种植物
        mciSendString("seek cardLift to 0", nullptr,0,nullptr);
        mciSendString("play cardLift", nullptr,0,nullptr);

        plant_queue[idx] = new_plant;

        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SINGLE_PATH_H
