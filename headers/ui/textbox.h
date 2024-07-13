//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_TEXTBOX_H
#define AGES1_TEXTBOX_H


#include <SFML/Graphics.hpp>
#include <string>

#include "../constants.h"

using namespace sf;

class textbox
{
private:
    Font look;
    Text view;
    std::string contains, output;
public:
    textbox(std::string font=DEFAULT_FONT,int SIZE=25,int posx=0,int posy=0);
    void show(RenderWindow &W);
    void set_position(int x,int y);
    void actualize(char sign);
    void erase();
    Text return_text();
    void hide();
    std::string return_caption();
};



#endif //AGES1_TEXTBOX_H
