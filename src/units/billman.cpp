//
// Created by tosiek on 29.08.22.
//

#include "../../headers/units/billman.h"

Billman::Billman(){
    //set stats
    hp_=96;
    armor_=51;
    attack_=102;
    quantity_=0;

    //set demands
    nIron_=6;
    nPeople_=1;
    nMoney_=10;
    upgradeTime_=5;

    //set _look
    texture_.loadFromFile("Textures/Units/billman.png");
    view_.setTexture(texture_);

    //name_ and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT, 0, 0,"Billman: "+std::to_string(quantity_), 12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void Billman::update_counter(){
    std::string count=std::to_string(quantity_);
    counter_.setCaption("Billman: "+count);
    counter_.center();
}

int Billman::attack_calculator(Type which){
    switch(which){
        case SWORD_MAN:
            return (int)((double)attack_ * 1.05);
        case BOW_MAN:
            return (int)((double)attack_ * 1.65);
        case SPEAR_MAN:
            return attack_;
        case HEAVY_CAVALRY:
            return (int)((double)attack_ * 1.43);
        case LIGHT_CAVALRY:
            return (int)((double)attack_ * 1.61);
        case KNIGHT:
            return (int)((double)attack_ * 0.95);
        case CROSSBOWMAN:
            return (int)((double)attack_ * 1.37);
        case BILLMAN:
            return attack_;
        case AXEMAN:
            return (int)((double)attack_ * 1.05);
    }
}
