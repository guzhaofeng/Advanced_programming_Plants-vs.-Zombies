#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNDAY_GAME_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNDAY_GAME_H

#include "all_header_file.h"
#include "game.h"

class sunday_game :public game{
private:

public:
    sunday_game():game("../resourse/game/sunday_back_ground.jpg",3,{true,true,true},true){
        map[1].zombie_list.push_back(new zombie(450));
        map[0].zombie_list.push_back(new zombie(450));
        map[2].zombie_list.push_back(new zombie(450));
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNDAY_GAME_H
