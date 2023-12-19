//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_TABLET_H
#define AGES1_TABLET_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "../constants.h"

class tablet
{
private:
    sf::Texture plank_;
    sf::Sprite look_;
    sf::Vector2f pos_, sting_pos_;
    std::string name_;
    bool focus_=false;
    sf::Font font_;
    sf::Text text_;
public:
    tablet();
    void create_tablet(std::string caption, sf::Vector2f position);
    void draw(sf::RenderWindow &W);
    bool TRIGGERED(int mposx, int mposy);
    void focussed();
    void unfocused();
    std::string return_name();
    bool onClick(int mposx,int mposy);
};

#endif //AGES1_TABLET_H
