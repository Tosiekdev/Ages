//
// Created by tosiek on 04.12.2021.
//

#include "../../headers/ui/label.h"

Label::Label(std::string path, int pos_x, int posy, std::string cap, int sized){
    create(path, static_cast<float>(pos_x), static_cast<float>(posy), cap, sized);
}

//Creating label
void Label::create(const std::string& path,float posx,float posy,const std::string& cap,int sized){
    //loading font
    label_font.loadFromFile(path);

    //setting _position
    label_position.x=posx;
    label_position.y=posy;

    //setting size and caption
    label_caption=cap;
    label_height=sized;

    //setting inscription
    labelText_.setFont(label_font);
    labelText_.setString(label_caption);
    labelText_.setCharacterSize(label_height);
    labelText_.setFillColor(sf::Color::Black);

    //positioning
    labelText_.setPosition(label_position);
}

//Drawing
void Label::show(sf::RenderWindow &W){
    W.draw(labelText_);
}

//New Caption
void Label::setCaption(std::string new_caption){
    label_caption=new_caption;
    labelText_.setString(label_caption);
}

//New size
void Label::setSize(int new_size){
    label_height=new_size;
    labelText_.setCharacterSize(label_height);
}

//new _position
void Label::setPosition(sf::Vector2f new_position){
    label_position=new_position;
    labelText_.setPosition(label_position);
}

//new font
void Label::setFont(std::string path){
    label_font.loadFromFile(path);
    labelText_.setFont(label_font);
}

void Label::setColor(sf::Color new_color){
    labelText_.setFillColor(new_color);
}

float Label::getWidth(){
    return labelText_.getGlobalBounds().width;
}

void Label::center(){
    float x= labelText_.getGlobalBounds().width / 2;
    float y= labelText_.getGlobalBounds().height / 2;
    labelText_.setOrigin(x, y);
}

