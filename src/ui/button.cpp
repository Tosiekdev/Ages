//
// Created by tosiek on 04.12.2021.
//

#include "../../headers/ui/button.h"

Button::Button(int h,int w,int posx,int posy,sf::String caption){
    create(h,w,posx,posy,caption);
    active=true;
}

//creating button
void Button::create(int h,int w,float posx,float posy,sf::String caption){
    //assigning variables
    button_height=h;
    button_width=w;
    button_position.x=posx;
    button_position.y=posy;
    button_caption=caption;

    //view_
    button_texture.loadFromFile("Textures/button.png");
    button_sprite.setTexture(button_texture);

    auto scale_x=static_cast<float>(button_width)/100.f;
    auto scale_y=static_cast<float>(button_height)/40.f;
    button_sprite.setScale(scale_x,scale_y);

    button_sprite.setPosition(button_position);

    //caption
    button_font.loadFromFile(DEFAULT_FONT);
    button_text.setFont(button_font);
    button_text.setPosition(button_position - sf::Vector2f(100, 100));
    button_text.setFillColor(sf::Color::Black);
    button_text.setCharacterSize(18*button_height/40);
    button_text.setString(button_caption);

    float origin_x=button_text.getGlobalBounds().width/2;
    float origin_y=button_text.getGlobalBounds().height;
    button_text.setOrigin(origin_x,origin_y);

    center();
}

//Checking if button is clicked
bool Button::onClick(int mposx,int mposy){
    if(button_sprite.getGlobalBounds().contains(mposx,mposy) && active) return true;
    else return false;
}

//Drawing button
void Button::show(sf::RenderWindow &W){
    W.draw(button_sprite);
    W.draw(button_text);
}

//Cool animation
bool Button::onFocus(int mposx,int mposy){
    auto cast=[](int z){return static_cast<float>(z);};
    if(button_sprite.getGlobalBounds().contains(cast(mposx),cast(mposy)) && active){
        auto scale_x=static_cast<float>(button_width)/100.f+0.2f;
        auto scale_y=static_cast<float>(button_height)/40.f+0.2f;
        button_sprite.setScale(scale_x,scale_y);

        float more_x=static_cast<float>(button_width)*0.6f;
        float more_y=static_cast<float>(button_height)*0.6f;
        auto text_pos=button_position+sf::Vector2f(more_x,more_y);
        button_text.setPosition(text_pos);

        return true;
    }else{
        auto scale_x=static_cast<float>(button_width)/100.f;
        auto scale_y=static_cast<float>(button_height)/40.f;
        button_sprite.setScale(scale_x,scale_y);

        center();

        return false;
    }
}

//this makes button Clickable
void Button::setActive(bool activity){
    active=activity;
}

void Button::set_position(sf::Vector2f new_position){
    button_position=new_position;
    button_sprite.setPosition(button_position);
    center();
}

void Button::center(){
    float more_x=static_cast<float>(button_width)/2;
    float more_y=static_cast<float>(button_height)/2;
    button_text.setPosition(button_position+sf::Vector2f(more_x,more_y));
}
