//
// Created by tosiek on 29.12.2021.
//

#ifndef AGES1_OBSTACLE_H
#define AGES1_OBSTACLE_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Obstacle{
public:
    Obstacle();
    void create_obstacle(std::string texture_path, Vector2f new_scale, Vector2f pos);
    void draw(RenderWindow &W);
private:
    Texture look;
    Sprite face;
    Vector2f position;
};


#endif //AGES1_OBSTACLE_H
