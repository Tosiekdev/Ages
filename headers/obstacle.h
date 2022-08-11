//
// Created by tosiek on 29.12.2021.
//

#ifndef AGES1_OBSTACLE_H
#define AGES1_OBSTACLE_H

#include <SFML/Graphics.hpp>
#include <string>

class Obstacle{
public:
    Obstacle();
    void create_obstacle(std::string texture_path, sf::Vector2f new_scale, sf::Vector2f pos);
    void draw(sf::RenderWindow &W);
private:
    sf::Texture _look;
    sf::Sprite _face;
    sf::Vector2f _position;
};


#endif //AGES1_OBSTACLE_H
