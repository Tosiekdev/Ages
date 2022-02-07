//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_LABEL_H
#define AGES1_LABEL_H


#include <SFML/Graphics.hpp>
#include <string>

#include "constants.h"

using namespace sf;
using namespace std;

class Label
{
    Font label_font;
    Text label_text;
    Vector2f label_possition;
    String label_caption;
    int label_height;
public:
    explicit Label(string=DEFAULT_FONT,int=0,int=0,String="Programmer is a Jerk",int=20);
    void show(RenderWindow &W);
    void setCaption(string new_caption);
    void setSize(int new_size);
    void setPosition(Vector2f new_position);
    void setFont(string path);
    void setColor(Color new_color);
    float getWidth();
    void center();
    void create(const string& path,float posx,float posy,const String& cap,int sized);
};



#endif //AGES1_LABEL_H
