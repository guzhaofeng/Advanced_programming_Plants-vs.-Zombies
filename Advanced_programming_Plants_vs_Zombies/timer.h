#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_TIMER_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_TIMER_H

#include "all_header_file.h"

class Timer {
private:
    std::chrono::high_resolution_clock::time_point last = chrono::high_resolution_clock::now();
    std::chrono::duration<double> standard_delay;
    std::chrono::duration<double> has_delay;
public:
    Timer(std::chrono::duration<double> delay):standard_delay(delay){}

    inline void get_delay(){
        auto now = chrono::high_resolution_clock::now();
        has_delay += now - last;
        last = now;
    }

    inline bool can_change_content(){
        if(has_delay >= standard_delay){
            has_delay = std::chrono::microseconds(0);
            return true;
        }
        return false;
    }


};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_TIMER_H
