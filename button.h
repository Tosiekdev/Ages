//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_BUTTON_H
#define AGES1_BUTTON_H


#include <SFML/Graphics.hpp>

#include "constants.h"

using namespace sf;

class Button
{
private:
    Texture button_texture;
    Sprite button_sprite;
    Font button_font;
    Text button_text;
    Vector2f button_possition;
    int button_height, button_width;\
    bool active;
    String button_caption;
public:
    Button(int=40,int=100,int=0,int=0,String="In_dev");
    void create(int h,int w,int posx,int posy,String caption);
    void setActive(bool activity);
    bool onClick(int mposx,int mposy);
    void show(RenderWindow &W);
    void onFocus(int mposx,int mposy);
};


#endif //AGES1_BUTTON_H
