#include "all_header_file.h"

#include "button.h"
#include "sence.h"

#include "begin_sence.h"
#include "choose_game.h"

#include "game.h"
#include "toolbar.h"
#include "single_path.h"
#include "sunday_game.h"
#include "sunwaterday.h"
#include "game_over_sence.h"

#include "character.h"
#include "zombie.h"
#include "plant.h"
#include "sunshine.h"
#include "Pea_bullets.h"

#include "sunflower.h"
#include "peashooter.h"
#include "wallnut.h"
#include "pepper.h"

int money;
int level;

int main() {
    ios::sync_with_stdio(false); // 关闭同步
    cin.tie(nullptr);
    cout.tie(nullptr);

    Status status;
    Status last_status = ing;
    sence* main_sence = new begin_sence;


    initgraph(900,600);//初始化窗口
    setbkcolor(RGB(234,234,172));

    fstream file("../level.txt",ios::in|ios::out);
    if(!file){
        cout << "open file failed." << endl;
        exit(-1);
    }
    file >> level;
    file.close();

    fstream file1("../money.txt",ios::in|ios::out);
    if(!file1){
        cout << "open file failed." << endl;
        exit(-1);
    }
    file1 >> money;
    cout << "you have " << money << " money" << endl;
    file1.close();

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

            last_status = change_to_sunday_game;

            sence* sence_will_be_delete = main_sence;
            main_sence = new sunday_game;
            delete sence_will_be_delete;
        }else if(status == change_to_sunwaterday_game){

            last_status = change_to_sunwaterday_game;

            sence* sence_will_be_delete = main_sence;
            main_sence = new sunwaterday;
            delete sence_will_be_delete;
        }else if(status == change_to_game_over){
            sence* sence_will_be_delete = main_sence;
            main_sence = new game_over_sence;
            delete sence_will_be_delete;
        }else if(status == change_to_game_win){
            if(last_status == change_to_sunday_game && level == 1){
                level++;
            }else if(last_status == change_to_sunwaterday_game && level == 2){
                level++;
            }
            money += level*10;

            fstream file2("../money.txt",ios::in|ios::out);
            if(!file2){
                cout << "open file failed." << endl;
                exit(-1);
            }
            file2 << money;
            fstream file3("../level.txt",ios::in|ios::out);
            if(!file3){
                cout << "open file failed." << endl;
                exit(-1);
            }
            file3 << level;
            file2.close();
            file3.close();

            sence* sence_will_be_delete = main_sence;
            main_sence = new choose_game;
            delete sence_will_be_delete;
        }

        //绘制画面
        main_sence->display(msg);
    }

    return 0;
}
