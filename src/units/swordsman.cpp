//
// Created by tosiek on 21.02.2022.
//

#include "../../headers/units/swordsman.h"

Swordsman::Swordsman(){
    //set stats
    hp_=100;
    armor_=50;
    attack_=75;
    quantity_=0;

    //set demands
    nIron_=5;
    nPeople_=1;
    nMoney_=10;
    upgradeTime_=5;

    //set _look
    texture_.loadFromFile("Textures/Units/swordsman.png");
    view_.setTexture(this->texture_);

    //name_ and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT, 0, 0,"Swordsman: "+std::to_string(quantity_), 12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void Swordsman::update_counter(){
    std::string count=std::to_string(quantity_);
    counter_.setCaption("Swordsman: "+count);
    counter_.center();
}

int Swordsman::attack_calculator(Type which){
    int hit=attack_;
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
        case KNIGHT:
            return (int)((double)hit*0.77);
        case CROSSBOWMAN:
            return (int)((double)hit*1.3);
        case BILLMAN:
            return hit;
        case AXEMAN:
            return (int)((double)hit*1.1);
    }
}

void Swordsman::launch_window(sf::RenderWindow &window){
    window1_.create(nMoney_,nPeople_,nIron_,(int)upgradeTime_,"Swordsman",window);
}
