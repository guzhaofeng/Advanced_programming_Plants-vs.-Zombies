#include "all_header_file.h"
#include "timer.h"
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

    int speed = 1;

    Timer timer;
public:
    int attack = 5;
    Zombie_animation_status zombieAnimationStatus = wALK;

    void set_health(int attack1){
        health -= attack1;
        if(health<=0){
            if(zombieAnimationStatus == wALK) {
                zombieAnimationStatus = dEATH_walking;
            }else if(zombieAnimationStatus == eAT){
                zombieAnimationStatus = dEATH_standing;
            }

            cout << "zombie die" << endl;
        }
    }

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
            if(death_standing_loop < death_standing.size()){
                putimagewithTransparent(position-20,332+path_idx*100,&death_standing[death_standing_loop]);
            }
            if(head_loop < head.size()){
                putimagewithTransparent(position+50,332+path_idx*100,&head[head_loop]);
            }

            timer.get_delay();
            if(timer.can_change_content()){
                death_standing_loop++;
                head_loop++;
            }

            if(death_standing_loop >= death_standing.size()){
                zombieAnimationStatus = oVER;
            }

        }else if(zombieAnimationStatus == dEATH_walking){
            if(death_walking_loop < death_walking.size()){
                putimagewithTransparent(position,332+path_idx*100,&death_walking[death_walking_loop]);
            }
            if(head_loop < head.size()){
                putimagewithTransparent(position+50,332+path_idx*100,&head[head_loop]);
            }
            if(death_walking_loop >= death_walking.size() && death_standing_loop < death_standing.size()){
                putimagewithTransparent(position-20,332+path_idx*100,&death_standing[death_standing_loop]);
                timer.get_delay();
                if(timer.can_change_content()){
                    death_standing_loop++;
                }
                if(death_standing_loop >= death_standing.size()){
                    zombieAnimationStatus = oVER;
                }
            }else{
                timer.get_delay();
                if(timer.can_change_content()){
                    death_walking_loop++;
                    head_loop++;
                }
            }
        }else if(zombieAnimationStatus == aSHES){

            putimagewithTransparent(position,332+path_idx*100,&ashes[ashes_loop]);

            timer.get_delay();
            if(timer.can_change_content()){
                ashes_loop++;
            }

            if(ashes_loop >= ashes.size()){
                zombieAnimationStatus = oVER;
            }
        }
    }
    Status progress(Status status) override{

        if(status == can_attack && zombieAnimationStatus != eAT && zombieAnimationStatus != dEATH_standing && zombieAnimationStatus!=dEATH_walking && zombieAnimationStatus!=aSHES){
            zombieAnimationStatus = eAT;
        }else if(status != can_attack && zombieAnimationStatus != dEATH_standing && zombieAnimationStatus!=dEATH_walking && zombieAnimationStatus!=aSHES){
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

    explicit zombie(int postion): character(200), timer(std::chrono::microseconds(time_num)){

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

        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (1).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (2).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (3).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (4).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (5).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (6).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (7).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (8).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (9).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (10).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (11).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (12).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (13).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (14).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (15).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (16).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (17).png");
        death_walking.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieLostHead\\ZombieLostHead (18).png");
        death_walking.push_back(image);

        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(1).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(2).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(3).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(4).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(5).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(6).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(7).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(8).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(9).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(10).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(11).png");
        head.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieHead\\ZombieHead(12).png");
        head.push_back(image);


        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (1).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (2).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (3).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (4).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (5).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (6).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (7).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (8).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (9).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (10).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (11).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (12).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (13).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (14).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (15).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (16).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (17).png");
        death_standing.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDie\\ZombieDie (18).png");
        death_standing.push_back(image);

        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\1.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\2.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\3.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\4.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\5.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\6.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\7.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\8.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\9.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\10.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\11.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\12.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\13.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\14.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\15.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\16.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\17.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\18.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\19.png");
        ashes.push_back(image);
        loadimage(&image,"..\\resourse\\character\\zombie\\zm_dead\\ZombieDust\\20.png");
        ashes.push_back(image);

    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ZOMBIE_H
