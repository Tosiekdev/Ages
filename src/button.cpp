//
// Created by tosiek on 04.12.2021.
//

#include "../headers/button.h"

Button::Button(int h,int w,int posx,int posy,sf::String caption){
    this->create(h,w,posx,posy,caption);
    this->active=true;
}

//creating button
void Button::create(int h,int w,float posx,float posy,sf::String caption){
    //assigning variables
    this->button_height=h;
    this->button_width=w;
    this->button_possition.x=posx;
    this->button_possition.y=posy;
    this->button_caption=caption;

    //view
    this->button_texture.loadFromFile("Textures/button.png");
    this->button_sprite.setTexture(this->button_texture);
    this->button_sprite.setScale(this->button_width/100,this->button_height/40);
    this->button_sprite.setPosition(this->button_possition);

    //caption
    this->button_font.loadFromFile(DEFAULT_FONT);
    this->button_text.setFont(this->button_font);
    this->button_text.setPosition(this->button_possition-sf::Vector2f(100,100));
    this->button_text.setFillColor(sf::Color::Black);
    this->button_text.setCharacterSize(18*this->button_height/40);
    this->button_text.setString(this->button_caption);
    this->button_text.setOrigin(this->button_text.getGlobalBounds().width/2,this->button_text.getGlobalBounds().height);
    this->button_text.setPosition(this->button_possition+sf::Vector2f(this->button_width/2,this->button_height/2));
}

//Checking if button is clicked
bool Button::onClick(int mposx,int mposy){
    if(this->button_sprite.getGlobalBounds().contains(mposx,mposy) && this->active) return true;
    else return false;
}

//Drawing button
void Button::show(sf::RenderWindow &W){
    W.draw(this->button_sprite);
    W.draw(this->button_text);
}

//Cool animation
bool Button::onFocus(int mposx,int mposy){
    if(this->button_sprite.getGlobalBounds().contains(mposx,mposy) && this->active){
        this->button_sprite.setScale(this->button_width/100+0.2,this->button_height/40+0.2);
        this->button_text.setPosition(this->button_possition+sf::Vector2f(this->button_width*0.6f,this->button_height*0.6f));
        return true;
    }else{
        this->button_sprite.setScale(this->button_width/100,this->button_height/40);
        this->button_text.setPosition(this->button_possition+sf::Vector2f(this->button_width/2,this->button_height/2));
        return false;
    }
}

//this makes button clickable
void Button::setActive(bool activity){
    this->active=activity;
}

void Button::set_position(sf::Vector2f new_position){
    this->button_possition=new_position;
    this->button_sprite.setPosition(this->button_possition);
}

