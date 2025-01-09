#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SENCE_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SENCE_H

//这是一个虚类

class sence {
public:
    virtual void display() = 0;
    virtual Status progress(ExMessage& msg) = 0;
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_SENCE_H
