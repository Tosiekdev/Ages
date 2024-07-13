//
// Created by tosiek on 29.12.2021.
//

#include "../../headers/ui/obstacle.h"


//beach-ass constructor
Obstacle::Obstacle()= default;

//set texture_ and _position
void Obstacle::create_obstacle(std::string texture_path, sf::Vector2f new_scale, sf::Vector2f pos){
    //setting texture_
    _look.loadFromFile(texture_path);
    _face.setTexture(_look);
    _face.setScale(new_scale);

    //adjust _position
    _position=pos;
    _face.setPosition(_position);
}

//draw sprite
void Obstacle::draw(sf::RenderWindow &W){
    W.draw(_face);
}
