#include "all_header_file.h"
#include "timer.h"

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
    int speed = 1;

    Timer timer;
public:
    int attack = 5;

    void display(int path_idx) override{

        if(zombieAnimationStatus == wALK){
            putimagewithTransparent(position,332+path_idx*100,&walk[walk_loop]);

            timer.get_delay();
            if(timer.can_change_content()){
                walk_loop++;

                if(4<=walk_loop && walk_loop<=14){
                    position -= speed;
                }
                else if(17<=walk_loop && walk_loop<=21){
                    position -= speed;
                }
                else if(1==walk_loop || walk_loop==2){
                    position -= speed;
                }

                if(18==walk_loop || walk_loop==19 || walk_loop==21){
                    position -= speed;
                }
                else if(walk_loop == 5){
                    position -= speed;
                }

            }

            if(walk_loop == walk.size()-1){
                walk_loop = 0;
            }


        }else if(zombieAnimationStatus == eAT){
            putimagewithTransparent(position,332+path_idx*100,&eat[eat_loop]);

            timer.get_delay();
            if(timer.can_change_content()){
                eat_loop++;
            }
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

        if(status == can_attack){
            zombieAnimationStatus = eAT;
        }else if(status == can_not_attack){
            zombieAnimationStatus = wALK;
        }
        if(position <= -20){
            return game_over;
        }

        return ing;
    }

    [[nodiscard]] int get_position() const{
        return position;
    }

    explicit zombie(int postion): character(270), timer(std::chrono::microseconds(time_num)){

        zombieAnimationStatus = wALK;

        IMAGE image;
        position = postion;

        loadimage(&image,"../resourse/character/zombie/zm_eat/1.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/2.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/3.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/4.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/5.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/6.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/7.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/8.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/9.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/10.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/11.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/12.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/13.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/14.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/15.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/16.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/17.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/18.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/19.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/20.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/21.png");
        eat.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_eat/22.png");
        eat.push_back(image);


        loadimage(&image,"../resourse/character/zombie/zm_walk/1.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/2.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/3.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/4.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/5.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/6.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/7.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/8.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/9.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/10.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/11.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/12.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/13.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/14.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/15.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/16.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/17.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/18.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/19.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/20.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/21.png");
        walk.push_back(image);
        loadimage(&image,"../resourse/character/zombie/zm_walk/22.png");
        walk.push_back(image);
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ZOMBIE_H
