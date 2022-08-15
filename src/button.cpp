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
    this->button_position.x=posx;
    this->button_position.y=posy;
    this->button_caption=caption;

    //view_
    this->button_texture.loadFromFile("Textures/button.png");
    this->button_sprite.setTexture(this->button_texture);

    auto scale_x=static_cast<float>(button_width)/100.f;
    auto scale_y=static_cast<float>(button_height)/40.f;
    this->button_sprite.setScale(scale_x,scale_y);

    this->button_sprite.setPosition(this->button_position);

    //caption
    this->button_font.loadFromFile(DEFAULT_FONT);
    this->button_text.setFont(this->button_font);
    this->button_text.setPosition(this->button_position - sf::Vector2f(100, 100));
    this->button_text.setFillColor(sf::Color::Black);
    this->button_text.setCharacterSize(18*this->button_height/40);
    this->button_text.setString(this->button_caption);

    float origin_x=button_text.getGlobalBounds().width/2;
    float origin_y=button_text.getGlobalBounds().height;
    this->button_text.setOrigin(origin_x,origin_y);

    center();
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
        auto scale_x=static_cast<float>(button_width)/100.f+0.2f;
        auto scale_y=static_cast<float>(button_height)/40.f+0.2f;
        this->button_sprite.setScale(scale_x,scale_y);

        float more_x=static_cast<float>(button_width)*0.6f;
        float more_y=static_cast<float>(button_height)*0.6f;
        auto text_pos=button_position+sf::Vector2f(more_x,more_y);
        this->button_text.setPosition(text_pos);

        return true;
    }else{
        auto scale_x=static_cast<float>(button_width)/100.f;
        auto scale_y=static_cast<float>(button_height)/40.f;
        this->button_sprite.setScale(scale_x,scale_y);

        center();

        return false;
    }
}

//this makes button Clickable
void Button::setActive(bool activity){
    this->active=activity;
}

void Button::set_position(sf::Vector2f new_position){
    this->button_position=new_position;
    this->button_sprite.setPosition(this->button_position);
    center();
}

void Button::center(){
    float more_x=static_cast<float>(button_width)/2;
    float more_y=static_cast<float>(button_height)/2;
    this->button_text.setPosition(this->button_position+sf::Vector2f(more_x,more_y));
}
