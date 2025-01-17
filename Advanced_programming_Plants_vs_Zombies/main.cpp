#include "all_header_file.h"

#include "button.h"
#include "sence.h"

#include "begin_sence.h"
#include "choose_game.h"

#include "game.h"
#include "toolbar.h"
#include "single_path.h"
#include "sunday_game.h"
#include "game_over_sence.h"

#include "character.h"
#include "zombie.h"
#include "plant.h"
#include "sunshine.h"
#include "Pea_bullets.h"

#include "sunflower.h"
#include "peashooter.h"

int main() {
    ios::sync_with_stdio(false); // 关闭同步
    cin.tie(nullptr);
    cout.tie(nullptr);

    Status status;
    sence* main_sence = new begin_sence;


    initgraph(900,600);//初始化窗口
    setbkcolor(RGB(234,234,172));


    bool running = true;
    while(running){

        //读取操作
        ExMessage msg;
        peekmessage(&msg);


        //处理数据
        status = main_sence->progress(msg);

        if(status == change_to_choose_game){
            sence* sence_will_be_delete = main_sence;
            main_sence = new choose_game;
            delete sence_will_be_delete;
        }else if(status == change_to_sunday_game){
            sence* sence_will_be_delete = main_sence;
            main_sence = new sunday_game;
            delete sence_will_be_delete;
        }else if(status == change_to_game_over){
            sence* sence_will_be_delete = main_sence;
            main_sence = new game_over_sence;
            delete sence_will_be_delete;
        }

        //绘制画面
        main_sence->display();
    }

    return 0;
}
