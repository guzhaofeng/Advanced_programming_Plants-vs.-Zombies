#include "all_header_file.h"

#include "button.h"
#include "sence.h"

#include "begin_sence.h"
#include "choose_game.h"

int main() {

    ExMessage msg;
    Status status;
    sence* main_sence = new begin_sence;

    initgraph(900,600);//初始化窗口
    setbkcolor(WHITE);


    bool running = true;
    while(running){

        //读取操作
        peekmessage(&msg);

        //处理数据
        status = main_sence->progress(msg);

        if(status == change_to_choose_game){
            sence* sence_will_be_delete = main_sence;
            main_sence = new choose_game;
            delete sence_will_be_delete;
        }

        //绘制画面
        BeginBatchDraw();
        cleardevice();
        main_sence->display();
        FlushBatchDraw();
    }

    return 0;
}
