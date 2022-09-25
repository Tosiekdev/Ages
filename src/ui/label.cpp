//
// Created by tosiek on 04.12.2021.
//

#include "../../headers/ui/label.h"

Label::Label(std::string path, int pos_x, int posy, std::string cap, int sized){
    this->create(path, static_cast<float>(pos_x), static_cast<float>(posy), cap, sized);
}

//Creating label
void Label::create(const std::string& path,float posx,float posy,const std::string& cap,int sized){
    //loading font
    this->label_font.loadFromFile(path);

    //setting _position
    this->label_position.x=posx;
    this->label_position.y=posy;

    //setting size and caption
    this->label_caption=cap;
    this->label_height=sized;

    //setting inscription
    this->labelText_.setFont(this->label_font);
    this->labelText_.setString(this->label_caption);
    this->labelText_.setCharacterSize(this->label_height);
    this->labelText_.setFillColor(sf::Color::Black);

    //positioning
    this->labelText_.setPosition(this->label_position);
}

//Drawing
void Label::show(sf::RenderWindow &W){
    W.draw(this->labelText_);
}

//New Caption
void Label::setCaption(std::string new_caption){
    this->label_caption=new_caption;
    this->labelText_.setString(this->label_caption);
}

//New size
void Label::setSize(int new_size){
    this->label_height=new_size;
    this->labelText_.setCharacterSize(this->label_height);
}

//new _position
void Label::setPosition(sf::Vector2f new_position){
    label_position=new_position;
    this->labelText_.setPosition(this->label_position);
}

//new font
void Label::setFont(std::string path){
    this->label_font.loadFromFile(path);
    this->labelText_.setFont(this->label_font);
}

void Label::setColor(sf::Color new_color){
    this->labelText_.setFillColor(new_color);
}

float Label::getWidth(){
    return this->labelText_.getGlobalBounds().width;
}

void Label::center(){
    float x= labelText_.getGlobalBounds().width / 2;
    float y= labelText_.getGlobalBounds().height / 2;
    this->labelText_.setOrigin(x, y);
}

