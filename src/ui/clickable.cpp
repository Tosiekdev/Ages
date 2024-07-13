//
// Created by tosiek on 04.12.2021.
//

#include "../../headers/ui/clickable.h"

using namespace sf;

//Beautiful animation
bool Clickable::onFocus(int mPosX, int mPosY){
    if(view_.getGlobalBounds().contains((float)mPosX, (float )mPosY)){
        view_.setScale(1.1, 1.1);
        return true;
    }else
        view_.setScale(1, 1);
    return false;
}

//check if object is clicked
bool Clickable::onClick(int mPosX, int mPosY){
    return view_.getGlobalBounds().contains((float)mPosX,(float)mPosY);
}

//create object
void Clickable::create_element(const std::string& path, Vector2f pos){
    look_.loadFromFile(path);
    view_.setTexture(this->look_);
    view_.setScale(1, 1);
    position_=pos;
    view_.setPosition(this->position_);
}

//Draw
void Clickable::draw_it(RenderWindow &W){
    W.draw(this->view_);
}

