#include "all_header_file.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BUTTON_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BUTTON_H

class button {
private:
    vector<IMAGE> image_list;
    vector<IMAGE> back_ground;
    int is_in_loop;

    int x,y;
    int width,height;

    bool can_play_button_music = true;
    char play_music[256] = {'p','l','a','y',' '};
    char seek_music[256] = {'s','e','e','k',' '};
public:
    button(int x,int y,int width,int height,
           int num_of_be_touch_list,

           const string& play_music,
           const string& seek_music,

           const vector<const TCHAR*>& address_list,
           const vector<const TCHAR*>& back_ground_address_list)


           :x(x),y(y),width(width),height(height){
        for (int i = 0; i <= num_of_be_touch_list; ++i) {
            IMAGE image;
            loadimage(&image,address_list[i]);
            image_list.push_back(image);
        }
        for (int i = 0; i <= num_of_be_touch_list; ++i) {
            IMAGE image;
            loadimage(&image,back_ground_address_list[i]);
            back_ground.push_back(image);
        }

        int i = 5;
        for (char c : play_music) {
            this->play_music[i++] = c;
        }
        i = 5;
        for (char c : play_music) {
            this->seek_music[i++] = c;
        }
        this->seek_music[i++] = ' ';

        for (char c : seek_music) {
            this->seek_music[i++] = c;
        }
        //初始化静态的按钮和按钮的动态动画

        is_in_loop = 0;

    }

    void display(){
        if(is_in_loop){
            if(back_ground.size()-1 >= is_in_loop){
                putimagewithTransparent(x,y,&image_list[is_in_loop],&back_ground[is_in_loop]);
            }else{
                putimage(x,y,&image_list[is_in_loop]);
            }

            is_in_loop--;
        }else{
            if(!back_ground.empty()){
                putimagewithTransparent(x,y,&image_list[is_in_loop],&back_ground[is_in_loop]);
            }else{
                putimage(x,y,&image_list[is_in_loop]);
            }
        }
    }

    void progress(Status stutas){
        if(stutas == is_in_touch){
            is_in_loop = (int)image_list.size()-1;

            if(can_play_button_music){
                mciSendString(seek_music,0,0,nullptr);
                mciSendString(play_music,nullptr,0,nullptr);
                can_play_button_music = false;
            }
        }else if(stutas == ing){

            if(!can_play_button_music){
                can_play_button_music = true;
                cout << "the music is ready" << endl;
            }
        }
    }

    bool can_touch(int a,int b) const{
        if(x<=a && a<x+width && y<=b && b<y+height){
            cout << "a button is in touch" << endl;
            return true;
        }
        return false;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BUTTON_H
