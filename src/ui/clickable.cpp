//
// Created by tosiek on 04.12.2021.
//

#include "../../headers/ui/clickable.h"

using namespace sf;
using namespace std;

//Beautifull animation
bool Clickable::onFocus(int mposx, int mposy){
    if(this->view.getGlobalBounds().contains(mposx,mposy)){
        this->view.setScale(1.1, 1.1);
        return true;
    }else
        this->view.setScale(1,1);
    return false;
}

//check if object is clicked
bool Clickable::onClick(int mposx, int mposy){
    if(this->view.getGlobalBounds().contains(mposx,mposy))
        return true;
    else
        return false;
}

//create object
void Clickable::create_element(string path, Vector2f pos){
    this->look.loadFromFile(path);
    this->view.setTexture(this->look);
    this->view.setScale(1,1);
    this->position=pos;
    this->view.setPosition(this->position);
}

//Draw
void Clickable::draw_it(RenderWindow &W){
    W.draw(this->view);
}

