//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_LABEL_H
#define AGES1_LABEL_H


#include <SFML/Graphics.hpp>
#include <string>

#include "../constants.h"

class Label
{
    sf::Font label_font;
    sf::Text label_text;
    sf::Vector2f label_position;
    std::string label_caption;
    int label_height;

public:
    explicit Label(std::string=DEFAULT_FONT,int=0,int=0,std::string="Programmer is a Jerk",int=20);
    void show(sf::RenderWindow &W);

    void setCaption(std::string new_caption);
    void setSize(int new_size);
    void setPosition(sf::Vector2f new_position);
    void setFont(std::string path);
    void setColor(sf::Color new_color);

    float getWidth();
    void center(); //sets caption origin to the center (should be called after all text changes)
    void create(const std::string& path,float posx,float posy,const std::string& cap,int sized);
};



#endif //AGES1_LABEL_H
