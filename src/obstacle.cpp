//
// Created by tosiek on 29.12.2021.
//

#include "../headers/obstacle.h"


//beach-ass constructor
Obstacle::Obstacle()= default;

//set texture and position
void Obstacle::create_obstacle(std::string texture_path, Vector2f new_scale, Vector2f pos){
    //setting texture
    this->look.loadFromFile(texture_path);
    this->face.setTexture(this->look);
    this->face.setScale(new_scale);

    //adjust possition
    this->position=pos;
    this->face.setPosition(this->position);
}

//draw sprite
void Obstacle::draw(RenderWindow &W){
    W.draw(this->face);
}
