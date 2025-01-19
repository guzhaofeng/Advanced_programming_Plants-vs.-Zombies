#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHOOSE_GAME_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHOOSE_GAME_H

#include "all_header_file.h"
#include "sence.h"
#include "level3.h"

extern int level;
extern int money;

class choose_game:public sence{
private:
    IMAGE back_ground;

    int page = 1;

    button sunday_button;
    button sunwaterday_button;
    button level_3;
    button level_4;

    button card_wallnut;
    button card_pepper;
    button card_attack;

    int begin = 0;
public:
    choose_game(): sunday_button(30,170,424,270,1,
        "tabBlock","to 0",
        {"../resourse/choose_game/sunday.png","../resourse/choose_game/sunday1.png"},
        {}),

        sunwaterday_button(10+450,169,417,263,1,
        "tabBlock","to 0",
        {"../resourse/choose_game/sunwaterday.png","../resourse/choose_game/sunwaterday1.png"},
        {}),

        level_3(30,169,417,263,1,
        "tabBlock","to 0",
        {"../resourse/choose_game/button0.png","../resourse/choose_game/button1.png"},
        {}),
        level_4(10+450,169,417,263,1,
        "tabBlock","to 0",
        {"../resourse/choose_game/button0.png","../resourse/choose_game/button1.png"},
        {}),
        card_wallnut(50+400,100,288,400,1,
        "tabBlock","to 0",
        {"../resourse/choose_game/wallnut0.png","../resourse/choose_game/wallnut1.png"},
        {}),
        card_pepper(50,100,288,400,1,
        "tabBlock","to 0",
        {"../resourse/choose_game/pepper0.png","../resourse/choose_game/pepper1.png"},
        {}),
        card_attack(50,100,288,400,1,
        "tabBlock","to 0",
        {"../resourse/choose_game/attack0.png","../resourse/choose_game/attack1.png"},
        {})
        {

        mciSendString("open ../resourse/choose_game/gamingBgm4.mp3 alias choose_game_music", nullptr,0,nullptr);
        mciSendString("play choose_game_music repeat",nullptr,0,nullptr);
            //播放音乐
        mciSendString("open ../resourse/choose_game/tabBlock.mp3 alias tabBlock", nullptr,0,nullptr);
        loadimage(&back_ground,"../resourse/choose_game/background.png");//加载背景
    }

    ~choose_game() override{
        mciSendString("close choose_game_music",nullptr,0,nullptr);
    }

    void display(ExMessage &msg) override{
        BeginBatchDraw();
        cleardevice();

        putimage(0,0,&back_ground);
        if(page == 1){
            sunday_button.display();
            sunwaterday_button.display();
        }else if(page == 2){
            level_3.display();
            level_4.display();
        }else if(page==3){
            card_wallnut.display();
            card_pepper.display();
        }else if(page==4){
            card_attack.display();
        }

        char str[20];
        setcolor(TRANSPARENT);
        sprintf(str, "level is %d",level);
        settextstyle(30, 0, "Arial");
        outtextxy(770, 480, str);
        sprintf(str, "money is %d",money);
        outtextxy(730, 520, str);

        sprintf(str, "page is %d",page);
        outtextxy(765, 440, str);

        FlushBatchDraw();
    }

    Status progress(ExMessage &msg) override{
        begin++;
        if(begin<=100){
            return ing;
        }

        if(page == 1){
            if(msg.message == WM_LBUTTONDOWN && sunday_button.can_touch(msg.x,msg.y)){
                return change_to_sunday_game;
            }else if(msg.message == WM_LBUTTONDOWN && sunwaterday_button.can_touch(msg.x,msg.y)){
                if(level < 2){
                    return ing;
                }
                return change_to_sunwaterday_game;
            }else{
                if(msg.message == WM_RBUTTONDOWN){
                    page=2;
                    begin=0;
                }
            }

            if(sunday_button.can_touch(msg.x,msg.y)){
                sunday_button.progress(is_in_touch);
            }else if(sunwaterday_button.can_touch(msg.x,msg.y)){
                sunwaterday_button.progress(is_in_touch);
            }

            else{
                sunday_button.progress(ing);
                sunwaterday_button.progress(ing);
            }
        }else if(page == 2){
            if(msg.message == WM_LBUTTONDOWN && level_3.can_touch(msg.x,msg.y)){
                if(level < 3){
                    return ing;
                }
                return change_to_level3;
            }else if(msg.message == WM_LBUTTONDOWN && level_4.can_touch(msg.x,msg.y)){
                if(level < 4){
                    return ing;
                }
                return change_to_level4;
            }else{
                if(msg.message == WM_LBUTTONDOWN){
                    page=1;
                    begin=0;
                }else if(msg.message == WM_RBUTTONDOWN){
                    page=3;
                    begin=0;
                }
            }

            if(level_3.can_touch(msg.x,msg.y)){
                level_3.progress(is_in_touch);
            }else if(level_4.can_touch(msg.x,msg.y)){
                level_4.progress(is_in_touch);
            }

            else{
                level_3.progress(ing);
                level_4.progress(ing);
            }

        }else if(page == 3){
            if(msg.message == WM_LBUTTONDOWN && card_pepper.can_touch(msg.x,msg.y)){
                bool have_pepper;
                fstream file("../store/pepper.txt",ios::in|ios::out);
                if(!file){
                    cout << "open file failed." << endl;
                    exit(-1);
                }
                file.close();

                if(money >= 50 && !have_pepper){
                    money -= 50;

                    fstream file1("../store/pepper.txt",ios::in|ios::out);
                    have_pepper = true;
                    file1 << have_pepper;
                    file1.close();

                    fstream file100("../money.txt",ios::in|ios::out);
                    file100 << money;
                    file100.close();
                }else{
                    return ing;
                }

                return ing;

            }else if(msg.message == WM_LBUTTONDOWN && card_wallnut.can_touch(msg.x,msg.y)){
                bool have_wallnut;
                fstream file("../store/wallnut.txt",ios::in|ios::out);
                if(!file){
                    cout << "open file failed." << endl;
                    exit(-1);
                }
                file >> have_wallnut;
                file.close();

                if(money >= 50 && !have_wallnut){
                    money -= 50;

                    fstream file1("../store/wallnut.txt",ios::in|ios::out);
                    have_wallnut = true;
                    file1 << have_wallnut;
                    file1.close();

                    fstream file100("../money.txt",ios::in|ios::out);
                    file100 << money;
                    file100.close();
                }else if(money >= 50 && have_wallnut){
                    money -= 50;
                    begin=0;

                    int health;
                    ifstream file1("../store/wallnut_health.txt",ios::in);
                    file1 >> health;
                    file1.close();

                    health += 200;
                    ofstream file2("../store/wallnut_health.txt",ios::out);
                    file2 << health;
                    file2.close();

                    fstream file100("../money.txt",ios::in|ios::out);
                    file100 << money;
                    file100.close();

                }else{
                    return ing;
                }

                return ing;
            }else{
                if(msg.message == WM_LBUTTONDOWN){
                    page=2;
                    begin=0;
                }else if(msg.message == WM_RBUTTONDOWN){
                    page=4;
                    begin=0;
                }
            }

            if(card_pepper.can_touch(msg.x,msg.y)){
                card_pepper.progress(is_in_touch);
            }else if(card_wallnut.can_touch(msg.x,msg.y)){
                card_wallnut.progress(is_in_touch);
            }

            else{
                level_3.progress(ing);
                level_4.progress(ing);
            }

        }else if(page == 4){
            if(msg.message == WM_LBUTTONDOWN && card_attack.can_touch(msg.x,msg.y)){
                int attack;
                fstream file("../store/attack.txt",ios::in|ios::out);
                if(!file){
                    cout << "open file failed." << endl;
                    exit(-1);
                }
                file >> attack;

                if(money >= 50){
                    begin = 0;
                    attack+=5;
                    money -= 50;

                    ofstream file1("../store/attack.txt",ios::in|ios::out);
                    if(!file1){
                        cout << "open file failed." << endl;
                        exit(-1);
                    }
                    file1 << attack;

                    fstream file100("../money.txt",ios::in|ios::out);
                    file100 << money;
                    file100.close();
                }

                return ing;
            }else{
                if(msg.message == WM_LBUTTONDOWN){
                    page=3;
                    begin=0;
                }
            }

            if(card_attack.can_touch(msg.x,msg.y)){
                card_attack.progress(is_in_touch);
            }
        }


        return ing;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_CHOOSE_GAME_H
