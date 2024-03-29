//
// Created by tosiek on 04.12.2021.
//

#include "../../headers/ui/textbox.h"

using namespace sf;
using namespace std;

//you know what it is
textbox::textbox(string font, int SIZE, int posx, int posy){
    //font&text
    this->look.loadFromFile(font);
    this->view.setFont(this->look);
    this->view.setFillColor(Color::Black);
    this->view.setCharacterSize(SIZE);
    this->view.setPosition(Vector2f(posx,posy));

    //prepare what will be show
    this->contains="";
    this->output=contains+"_";
    this->view.setString(this->output);
}

//drawing textbox
void textbox::show(RenderWindow &W){
    W.draw(this->view);
}

//setting _position
void textbox::set_position(int x,int y){
    this->view.setPosition(x,y);
}

//adding next characters
void textbox::actualize(char sign){
    this->contains+=sign;
    this->output=this->contains+"_";
    this->view.setString(this->output);
}

//deleting last character
void textbox::erase(){
    this->contains=this->contains.substr(0, this->contains.length()-1);
    this->output=this->contains+"_";
    this->view.setString(this->output);
}

//give back text(all object), idk why this is here
Text textbox::return_text(){
    return this->view;
}

//fit text in prepared place (by deleting from view_ 1. char)
void textbox::hide(){
    this->output=this->output.substr(1,this->output.length()-1);
    this->view.setString(this->output);
}

//return whole text
string textbox::return_caption(){
    return this->contains;
}
