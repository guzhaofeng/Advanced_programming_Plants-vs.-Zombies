#include "all_header_file.h"
#include "character.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ZOMBIE_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ZOMBIE_H


class zombie : public character{
public:
    enum Zombie_animation_status{
        eAT,
        wALK,

        dEATH_walking,
        dEATH_standing,
        aSHES,

        oVER
    };
private:
    vector<IMAGE> eat;
    int eat_loop = 0;

    vector<IMAGE> walk;
    int walk_loop = 0;





    vector<IMAGE> ashes;
    int ashes_loop = 0;





    vector<IMAGE> head;
    int head_loop = 0;

    vector<IMAGE> death_walking;
    int death_walking_loop = 0;

    vector<IMAGE> death_standing;
    int death_standing_loop = 0;



    Zombie_animation_status zombieAnimationStatus = wALK;
    int speed;
public:
    void display(int path_idx){
        if(zombieAnimationStatus == wALK){
            putimagewithTransparent(position,361+path_idx*108,&walk[walk_loop++]);
            if(walk_loop == walk.size()-1){
                walk_loop = 0;
            }
        }else if(zombieAnimationStatus == eAT){
            putimagewithTransparent(position,361+path_idx*108,&eat[eat_loop++]);
            if(eat_loop == eat.size()-1){
               eat_loop = 0;
            }
        }else if(zombieAnimationStatus == dEATH_standing){
            if(death_standing_loop != death_standing.size()-1){
                putimagewithTransparent(position,361+path_idx*108,&death_standing[death_standing_loop++]);
            }

            if(head_loop != head.size()-1){
                putimagewithTransparent(position,361+path_idx*108,&head[head_loop++]);
            }

            if(head_loop == head.size()-1 && death_standing_loop == death_standing.size()-1){
                zombieAnimationStatus = oVER;
            }
        }else if(zombieAnimationStatus == dEATH_walking){
            if(death_walking_loop != death_walking.size()-1){
                putimagewithTransparent(position,361+path_idx*108,&death_walking[death_walking_loop++]);
            }

            if(head_loop != head.size()-1){
                putimagewithTransparent(position,361+path_idx*108,&head[head_loop++]);
            }

            if(head_loop == head.size()-1 && death_walking_loop == death_walking.size()-1){
                if(death_standing_loop != death_standing.size()-1){
                    putimagewithTransparent(position,361+path_idx*108,&death_standing[death_standing_loop++]);
                }else{
                    zombieAnimationStatus = oVER;
                }
            }
        }
    }
    Status progress(Status status) override{

    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ZOMBIE_H
