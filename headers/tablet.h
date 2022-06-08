//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_TABLET_H
#define AGES1_TABLET_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "constants.h"

using namespace std;
using namespace sf;

class tablet
{
private:
    Texture plank;
    Sprite look;
    Vector2f pos, sting_pos;
    string name;
    bool focuss=false;
    Font font;
    Text text;
public:
    tablet();
    void create_tablet(string caption, Vector2f position);
    void draw(RenderWindow &W);
    bool TRIGGERED(int mposx, int mposy);
    void focussed();
    void notfocussed();
    string return_name();
    bool onClick(int mposx,int mposy);
};

#endif //AGES1_TABLET_H
