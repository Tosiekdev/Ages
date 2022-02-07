//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_CLICKABLE_H
#define AGES1_CLICKABLE_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class clickable
{
private:
    Texture look;
    Sprite view;
    Vector2f possition;
public:
    void create_element(string path, Vector2f pos);
    bool onFocus(int mposx, int mposy);
    bool onClick(int mposx, int mposy);
    void draw_it(RenderWindow &W);
};


#endif //AGES1_CLICKABLE_H
