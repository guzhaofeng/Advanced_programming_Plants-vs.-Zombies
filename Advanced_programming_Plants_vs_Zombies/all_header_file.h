#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ALL_HEADER_FILE_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ALL_HEADER_FILE_H

#include <iostream>
#include "graphics.h"
#include <algorithm>
#include <conio.h>
#include <vector>
#include <string>
#include <stack>
#include <windows.h>
#include <unistd.h>

using namespace std;

enum Status{
    over,
    ing,
    change_to_choose_game,
    is_in_touch
};

void putimagewithTransparent(int x,int y,IMAGE* temp,IMAGE* back_ground){
    putimage(x,y,back_ground,SRCAND);
    putimage(x,y,temp,SRCPAINT);
}


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_ALL_HEADER_FILE_H
