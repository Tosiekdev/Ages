//
// Created by tosiek on 29.08.22.
//

#include "../../headers/units/knight.h"

Knight::Knight(){
    //set stats
    hp_=130;
    armor_=65;
    attack_=98;
    quantity_=0;

    //set demands
    nIron_=6;
    nPeople_=2;
    nMoney_=13;
    upgradeTime_=7;

    //set _look
    texture_.loadFromFile("Textures/Units/knight.png");
    view_.setTexture(this->texture_);

    //name and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT, 0, 0,"Knight: "+std::to_string(quantity_), 12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void Knight::update_counter(){
    std::string count=std::to_string(quantity_);
    counter_.setCaption("Swordsman: "+count);
    counter_.center();
}

int Knight::attack_calculator(Type which){
    int hit=attack_;
    switch(which){
        case SWORD_MAN:
            return (int)((double)hit*1.3);
        case BOW_MAN:
            return (int)((double)hit*1.95);
        case SPEAR_MAN:
            return (int)((double)hit*1.43);
        case HEAVY_CAVALRY:
            return (int)((double)hit*0.975);
        case LIGHT_CAVALRY:
            return (int)((double)hit*1.3);
        case KNIGHT:
            return hit;
        case CROSSBOWMAN:
            return (int)((double)hit*1.69);
        case BILLMAN:
            return (int)((double)hit*1.3);
        case AXEMAN:
            return (int)((double)hit*1.43);
    }
}
