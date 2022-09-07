//
// Created by tosiek on 29.08.22.
//

#include "../../headers/units/crossbowman.h"

Crossbowman::Crossbowman(){
    //set stats
    hp_=83;
    armor_=28;
    attack_=66;
    quantity_=0;

    //set demands
    nIron_=3;
    nPeople_=1;
    nMoney_=6;
    upgradeTime_=3;

    //set _look
    texture_.loadFromFile("Textures/Units/crossbowman.png");
    view_.setTexture(this->texture_);

    //name_ and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT, 0, 0,"Crossbowman: "+std::to_string(quantity_), 12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void Crossbowman::update_counter(){
    std::string count=std::to_string(quantity_);
    counter_.setCaption("Archer: "+count);
    counter_.center();
}

int Crossbowman::attack_calculator(Type which){
    int hit=attack_;
    switch(which){
        case SWORD_MAN:
            return (int)((double)hit*1.32);
        case BOW_MAN:
            return (int)((double)hit*1.1);
        case SPEAR_MAN:
            return (int)((double)hit*1.21);
        case HEAVY_CAVALRY:
            return (int)((double)hit*0.55);
        case LIGHT_CAVALRY:
            return (int)((double)hit*0.77);
        case KNIGHT:
            return (int)((double)hit*1.01);
        case CROSSBOWMAN:
            return hit;
        case BILLMAN:
            return (int)((double)hit*1.21);
        case AXEMAN:
            return (int)((double)hit*1.32);
    }
}
