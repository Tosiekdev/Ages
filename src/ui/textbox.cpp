//
// Created by tosiek on 04.12.2021.
//

#include "../../headers/ui/textbox.h"

using namespace sf;

//you know what it is
textbox::textbox(std::string font, int SIZE, int posx, int posy){
    //font&text
    look.loadFromFile(font);
    view.setFont(look);
    view.setFillColor(Color::Black);
    view.setCharacterSize(SIZE);
    view.setPosition(Vector2f(posx,posy));

    //prepare what will be show
    contains="";
    output=contains+"_";
    view.setString(output);
}

//drawing textbox
void textbox::show(RenderWindow &W){
    W.draw(view);
}

//setting _position
void textbox::set_position(int x,int y){
    view.setPosition(x,y);
}

//adding next characters
void textbox::actualize(char sign){
    contains+=sign;
    output=contains+"_";
    view.setString(output);
}

//deleting last character
void textbox::erase(){
    contains=contains.substr(0, contains.length()-1);
    output=contains+"_";
    view.setString(output);
}

//give back text(all object), idk why this is here
Text textbox::return_text(){
    return view;
}

//fit text in prepared place (by deleting from view_ 1. char)
void textbox::hide(){
    output=output.substr(1,output.length()-1);
    view.setString(output);
}

//return whole text
std::string textbox::return_caption(){
    return contains;
}
