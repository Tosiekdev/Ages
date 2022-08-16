//
// Created by tosiek on 21.02.2022.
//

#include "../headers/SwordsMen.h"

SwordsMen::SwordsMen(){
    //set stats
    this->hp=100;
    this->armor=50;
    this->attack=75;
    this->quantity=0;

    //set demands
    this->n_iron=5;
    this->n_people=1;
    this->n_money=10;
    this->upgrade_time_=5;

    //set _look
    this->texture_.loadFromFile("Textures/swordsman.png");
    this->view_.setTexture(this->texture_);

    //name and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT,0,0,"Swordsman: "+std::to_string(quantity),12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");
}

int SwordsMen::attack_calculator(Type which){
    int hit=this->attack;
    switch(which){
        case SWORD_MAN:
            return hit;
        case BOW_MAN:
            return (int)((double)hit*1.5);
        case SPEAR_MAN:
            return (int)((double)hit*1.1);
        case HEAVY_CAVALRY:
            return (int)((double)hit*0.75);
        case LIGHT_CAVALRY:
            return hit;
    }
}

void SwordsMen::update_counter(){
    std::string count=std::to_string(quantity);
    counter_.setCaption("Swordsman: "+count);
    counter_.center();
}
