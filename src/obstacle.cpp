//
// Created by tosiek on 29.12.2021.
//

#include "../headers/obstacle.h"


//beach-ass constructor
Obstacle::Obstacle()= default;

//set texture and _position
void Obstacle::create_obstacle(std::string texture_path, sf::Vector2f new_scale, sf::Vector2f pos){
    //setting texture
    this->_look.loadFromFile(texture_path);
    this->_face.setTexture(this->_look);
    this->_face.setScale(new_scale);

    //adjust _position
    this->_position=pos;
    this->_face.setPosition(this->_position);
}

//draw sprite
void Obstacle::draw(sf::RenderWindow &W){
    W.draw(this->_face);
}
