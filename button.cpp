//
// Created by tosiek on 04.12.2021.
//

#include "button.h"

using namespace sf;

Button::Button(int h,int w,int posx,int posy,String caption){
    this->create(h,w,posx,posy,caption);
    this->active=true;
}

//creating button
void Button::create(int h,int w,int posx,int posy,String caption){
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
    this->button_text.setFillColor(Color::Black);
    this->button_text.setCharacterSize(18*this->button_height/40);
    this->button_text.setString(this->button_caption);
    this->button_text.setPosition(this->button_possition+Vector2f(9,5));
}

//Checking if button is clicked
bool Button::onClick(int mposx,int mposy){
    if(this->button_sprite.getGlobalBounds().contains(mposx,mposy) && this->active) return true;
    else return false;
}

//Drawing button
void Button::show(RenderWindow &W){
    W.draw(this->button_sprite);
    W.draw(this->button_text);
}

//Cool animation
void Button::onFocus(int mposx,int mposy){
    if(this->button_sprite.getGlobalBounds().contains(mposx,mposy) && this->active){
        this->button_sprite.setScale(this->button_width/100+0.2,this->button_height/40+0.2);
        this->button_text.setPosition(this->button_possition+Vector2f(5+this->button_width*0.1,5+this->button_height*0.1));
    }else{
        this->button_sprite.setScale(this->button_width/100,this->button_height/40);
        this->button_text.setPosition(this->button_possition+Vector2f(9,5));
    }
}

//this makes button clickable
void Button::setActive(bool activity){
    this->active=activity;
}

