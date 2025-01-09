#include "all_header_file.h"

#include "button.h"
#include "sence.h"

#include "begin_sence.h"

int main() {

    ExMessage msg;
    Status status;
    sence* main_sence = new begin_sence;

    initgraph(900,600);//初始化窗口
    setcolor(TRANSPARENT);

    bool running = true;
    while(running){

        //读取操作
        while(peekmessage(&msg)){

        }

        //处理数据
        status = main_sence->progress(msg);

        //绘制画面
        main_sence->display();
    }

    return 0;
}
