#include "all_header_file.h"

#ifndef ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BUTTON_H
#define ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BUTTON_H

class button {
private:
    vector<IMAGE> image_list;
    int is_in_loop;

    int x,y;
    int width,height;
public:
    button(int x,int y,int width,int height,int num_of_be_touch_list,const vector<const TCHAR*>& address_list):x(x),y(y),width(width),height(height){

        for (int i = 0; i <= num_of_be_touch_list; ++i) {
            IMAGE image;
            loadimage(&image,address_list[i]);
            image_list.push_back(image);
        }
        //初始化静态的按钮和按钮的动态动画

        is_in_loop = 0;

    }

    void display(){
        if(is_in_loop){
            putimage(x,y,&image_list[is_in_loop]);
            is_in_loop--;
        }else{
            putimage(x,y,&image_list[0]);
        }
    }

    void progress(){
        is_in_loop = (int)image_list.size()-1;
    }

    bool can_touch(int a,int b) const{
        if(x<=a && a<y+width && y<=b && b<y+height){
            return true;
        }
        return false;
    }
};


#endif //ADVANCED_PROGRAMMING_PLANTS_VS_ZOMBIES_BUTTON_H
