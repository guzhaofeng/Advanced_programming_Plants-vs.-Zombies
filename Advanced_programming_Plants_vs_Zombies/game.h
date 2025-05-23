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

    int sun_num = 150;
    vector<single_path> map;

    Timer timer;
    int all_game_time = 1*60*24;
    int now_time = 0;

    int zombie_appear_time = 240;
    int zombie_min_appear_time = 20;
public:
    game(const TCHAR* image_path,int path_num,const vector<bool>& is_land,bool is_day_not_night):toolbar(),is_day_not_night(is_day_not_night),timer(std::chrono::microseconds(time_num)){
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

    void display(ExMessage &msg) override{

        mouse_x = msg.x;
        mouse_y = msg.y;

        BeginBatchDraw();
        cleardevice();

        putimage(-140,0,&back_ground);

        if(is_in_puting_a_card){
            toolbar.display(mouse_x,mouse_y);
        }else{
            toolbar.display();
        }

        for(auto& single_path : map){
            single_path.display();
        }

        settextstyle(20, 0, "Arial");
        char str[20];
        sprintf(str, "%d", sun_num);
        setcolor(BLACK);
        outtextxy(32, 76, str);

        char str1[20];
        sprintf(str1, "%f", ((float)now_time)/((float)all_game_time));
        setcolor(BLACK);
        outtextxy(800, 570, str1);

        FlushBatchDraw();
    }

    Status progress(ExMessage &msg) override{
        timer.get_delay();
        if(timer.can_change_content()){

            now_time++;
            if(now_time%zombie_appear_time == 0){
                map[rand()%map.size()].zombie_list.push_back(new zombie(750));
                if(zombie_appear_time>=zombie_min_appear_time){
                    zombie_appear_time-=rand()%8+1;
                }
            }
        }


        if(now_time > all_game_time){
            return change_to_game_win;
        }

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
