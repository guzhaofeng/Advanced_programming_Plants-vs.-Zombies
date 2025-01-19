#include "all_header_file.h"
#include "game.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_LEVEL4_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_LEVEL4_H


class level4 : public game{
public:
    level4():game("../resourse/choose_game/Background_1.jpg",5,{true,true,true,true,true},true){
        zombie_appear_time = 140;
        zombie_min_appear_time = 20;

        map[rand()%5].zombie_list.push_back(new zombie(750));
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_LEVEL4_H
