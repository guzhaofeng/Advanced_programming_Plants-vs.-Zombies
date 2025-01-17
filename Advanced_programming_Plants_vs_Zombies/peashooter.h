#include "all_header_file.h"
#include "plant.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PEASHOOTER_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PEASHOOTER_H


class peashooter : public plant{
private:
    int attack = 20;
    Timer timer1;

    int attack_time = 25;
    int now_attack_time = 15;
public:
    peashooter(int idx): plant("../resourse/character/plants/Peashooter/card.png",{
                                      "../resourse/character/plants/Peashooter/living/1.png",
                                      "../resourse/character/plants/Peashooter/living/2.png",
                                      "../resourse/character/plants/Peashooter/living/3.png",
                                      "../resourse/character/plants/Peashooter/living/4.png",
                                      "../resourse/character/plants/Peashooter/living/5.png",
                                      "../resourse/character/plants/Peashooter/living/6.png",
                                      "../resourse/character/plants/Peashooter/living/7.png",
                                      "../resourse/character/plants/Peashooter/living/8.png",
                                      "../resourse/character/plants/Peashooter/living/9.png",
                                      "../resourse/character/plants/Peashooter/living/10.png",
                                      "../resourse/character/plants/Peashooter/living/11.png",
                                      "../resourse/character/plants/Peashooter/living/13.png"},
                              idx,100),timer1(std::chrono::microseconds(time_num)){}

    Status progress(Status status) override{
        if(status == can_attack){
            timer1.get_delay();
            if(timer1.can_change_content()){
                now_attack_time += 1;
            }
            if(now_attack_time >= attack_time){
                now_attack_time = 0;
                return make_a_peashooter_attack;
            }
        }
        return ing;
    }

    Status get_plant_name() override{
        return name_peashooter;
    }

};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_PEASHOOTER_H
