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
    sf::Texture look_;
    sf::Sprite view_;
    sf::Vector2f position_;

public:
    void create_element(const std::string& path, sf::Vector2f pos);
    sf::Vector2f get_position() const{ return position_; }
    void set_position(sf::Vector2f newPos) { position_=newPos; view_.setPosition(position_); }
    bool onFocus(int mPosX, int mPosY);
    bool onClick(int mPosX, int mPosY);
    void draw_it(sf::RenderWindow &W);
};


#endif //AGES1_CLICKABLE_H
