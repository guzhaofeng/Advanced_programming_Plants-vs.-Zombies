#include "all_header_file.h"
#include "sence.h"
#include "toolbar.h"
#include "timer.h"
#include "single_path.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_GAME_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_GAME_H

class game : public sence{
protected:
    IMAGE back_ground;

    Toolbar toolbar;
    bool is_in_puting_a_card = false;
    int mouse_x;
    int mouse_y;

    bool is_day_not_night;

    int sun_num = 100;
    vector<single_path> map;


public:
    game(const TCHAR* image_path,int path_num,const vector<bool>& is_land,bool is_day_not_night):toolbar(),is_day_not_night(is_day_not_night){
        loadimage(&back_ground,image_path);//加载背景

        mouse_y = 0;
        mouse_x = 0;

        for (int i = 0; i < path_num; ++i) {
            map.emplace_back(i-(path_num/2)-1,is_day_not_night,is_land[i]);
        }

        mciSendString("open ../resourse/game/collectSunshine.wav.mp3 alias collects_sunshine", nullptr,0,nullptr);
        mciSendString("open ../resourse/game/gamingBgm1.mp3 alias bgm1", nullptr,0,nullptr);
        mciSendString("play bgm1 repeat", nullptr,0,nullptr);
    }
    ~game() override{
        mciSendString("stop bgm1", nullptr,0,nullptr);
    }

    void display() override{

        BeginBatchDraw();
        cleardevice();

        putimage(-140,0,&back_ground);

        for(auto& single_path : map){
            single_path.display();
        }

        if(is_in_puting_a_card){
            toolbar.display(mouse_x,mouse_y);
        }else{
            toolbar.display();
        }

        char str[20];
        sprintf(str, "%d", sun_num);
        setcolor(BLACK);
        outtextxy(32, 76, str);


        FlushBatchDraw();
    }

    Status progress(ExMessage &msg) override{
        for (int i = 0; i < map.size(); ++i) {
            if(map[i].progress()==game_over){
                return change_to_game_over;
            }
        }

        mouse_x = msg.x;
        mouse_y = msg.y;

        if(toolbar.progress(msg) == touch_a_card){
            is_in_puting_a_card = true;
            return ing;
        }else if(msg.message == WM_LBUTTONDOWN && is_in_puting_a_card){
            int result = 0;
            for (auto& temp : map){
                result = temp.can_touch(msg.x,msg.y);
                if(result != 0){
                    is_in_puting_a_card = false;
                    int cost = toolbar.get_sunshine_cost();
                    if(sun_num-cost>=0){
                        sun_num-=cost;
                        cout << "you have plant a plant" << endl;
                        temp.progress(result,toolbar.creat_new_plant(result));
                    }

                    return ing;
                }
            }
        }else if(msg.message == WM_LBUTTONDOWN){
            for (int i = 0; i < map.size(); ++i) {
                int result = map[i].get_sunshine(mouse_x,mouse_y);
                if(result!=0){
                    sun_num+=result;
                    mciSendString("seek collects_sunshine to 0", nullptr,0,nullptr);
                    mciSendString("play collects_sunshine", nullptr,0,nullptr);
                    return ing;
                }
            }
        }else if(msg.message == WM_RBUTTONDOWN && is_in_puting_a_card){
            is_in_puting_a_card = false;
        }


        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_GAME_H
