#include "all_header_file.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHARACTER_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHARACTER_H


class character {
protected:
    int health;
    int position;
public:
    character(int health):health(health){}

    virtual Status progress(Status status) = 0;

    virtual void display(int idx) = 0;
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHARACTER_H
