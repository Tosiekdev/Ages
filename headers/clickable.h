//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_CLICKABLE_H
#define AGES1_CLICKABLE_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Clickable
{
private:
    sf::Texture look;
    sf::Sprite view;
    sf::Vector2f position;

public:
    void create_element(std::string path, sf::Vector2f pos);
    bool onFocus(int mposx, int mposy);
    bool onClick(int mposx, int mposy);
    void draw_it(sf::RenderWindow &W);
};


#endif //AGES1_CLICKABLE_H
