#include "all_header_file.h"
#include "plant.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNFLOWER_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNFLOWER_H



class sunflower : public plant{
private:
    int num_of_sunshine = 25;

public:
    sunflower(int idx): plant("../resourse/character/plants/sunflower/card.png",{
            "../resourse/character/plants/sunflower/living/1.png",
            "../resourse/character/plants/sunflower/living/2.png",
            "../resourse/character/plants/sunflower/living/3.png",
            "../resourse/character/plants/sunflower/living/4.png",
            "../resourse/character/plants/sunflower/living/5.png",
            "../resourse/character/plants/sunflower/living/6.png",
            "../resourse/character/plants/sunflower/living/7.png",
            "../resourse/character/plants/sunflower/living/8.png",
            "../resourse/character/plants/sunflower/living/9.png",
            "../resourse/character/plants/sunflower/living/10.png",
            "../resourse/character/plants/sunflower/living/11.png",
            "../resourse/character/plants/sunflower/living/12.png",
            "../resourse/character/plants/sunflower/living/13.png",
            "../resourse/character/plants/sunflower/living/14.png",
            "../resourse/character/plants/sunflower/living/15.png",
            "../resourse/character/plants/sunflower/living/16.png",
            "../resourse/character/plants/sunflower/living/17.png",
            "../resourse/character/plants/sunflower/living/18.png"},
            idx
    ){}


};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SUNFLOWER_H
