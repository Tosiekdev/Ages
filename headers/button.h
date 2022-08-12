//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_BUTTON_H
#define AGES1_BUTTON_H


#include <SFML/Graphics.hpp>

#include "constants.h"

class Button
{
private:
    sf::Texture button_texture;
    sf::Sprite button_sprite;
    sf::Font button_font;
    sf::Text button_text;
    sf:: Vector2f button_position;
    int button_height, button_width;\
    bool active;
    sf::String button_caption;
public:
    explicit Button(int=40,int=100,int=0,int=0,sf::String="In_dev");
    void create(int h,int w,float posx,float posy,sf::String caption);
    void set_position(sf::Vector2f new_position);
    void setActive(bool activity);
    bool onClick(int mposx,int mposy);
    void show(sf::RenderWindow &W);
    bool onFocus(int mposx,int mposy);
};


#endif //AGES1_BUTTON_H
