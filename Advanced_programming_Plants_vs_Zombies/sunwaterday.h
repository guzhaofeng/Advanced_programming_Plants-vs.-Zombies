#include "all_header_file.h"
#include "game.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNWATERDAY_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNWATERDAY_H


class sunwaterday : public game{
public:
    sunwaterday():game("../resourse/game/map0.jpg",5,{true,true,true,true,true},true){
        zombie_appear_time = 170;
        zombie_min_appear_time = 20;

        map[rand()%5].zombie_list.push_back(new zombie(750));
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNWATERDAY_H
