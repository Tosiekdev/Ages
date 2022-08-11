//
// Created by tosiek on 04.12.2021.
//

#include "../headers/label.h"

using namespace sf;

Label::Label(std::string path,int posx,int posy,String cap,int sized){
    this->create(path,posx,posy,cap,sized);
}

//Creating label
void Label::create(const std::string& path,float posx,float posy,const String& cap,int sized){
    //loading font
    this->label_font.loadFromFile(path);

    //setting _position
    this->label_possition.x=posx;
    this->label_possition.y=posy;

    //setting size and caption
    this->label_caption=cap;
    this->label_height=sized;

    //setting inscription
    this->label_text.setFont(this->label_font);
    this->label_text.setString(this->label_caption);
    this->label_text.setCharacterSize(this->label_height);
    this->label_text.setFillColor(Color::Black);

    //positioning
    this->label_text.setPosition(this->label_possition);
}

//Drawing
void Label::show(RenderWindow &W){
    W.draw(this->label_text);
}

//New Caption
void Label::setCaption(std::string new_caption){
    this->label_caption=new_caption;
    this->label_text.setString(this->label_caption);
}

//New size
void Label::setSize(int new_size){
    this->label_height=new_size;
    this->label_text.setCharacterSize(this->label_height);
}

//new _position
void Label::setPosition(Vector2f new_position){
    this->label_possition=new_position;
    this->label_text.setPosition(this->label_possition);
}

//new font
void Label::setFont(std::string path){
    this->label_font.loadFromFile(path);
    this->label_text.setFont(this->label_font);
}

void Label::setColor(Color new_color){
    this->label_text.setFillColor(new_color);
}

float Label::getWidth(){
    return this->label_text.getGlobalBounds().width;
}

void Label::center(){
    float x=this->label_text.getGlobalBounds().width/2;
    float y=this->label_text.getGlobalBounds().height/2;
    this->label_text.setOrigin(x,y);
}

