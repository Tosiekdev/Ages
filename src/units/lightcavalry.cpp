//
// Created by tosiek on 29.08.22.
//

#include "../../headers/units/lightcavalry.h"

LightCavalry::LightCavalry(){
//set stats
    hp_=160;
    armor_=50;
    attack_=96;
    quantity_=0;

    //set demands
    nIron_=12;
    nPeople_=3;
    nMoney_=16;
    upgradeTime_=8;

    //set _look
    texture_.loadFromFile("Textures/Units/l_cavalry.png");
    view_.setTexture(this->texture_);

    //name_ and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT, 0, 0,"Light cavalry: "+std::to_string(quantity_), 12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void LightCavalry::update_counter(){
    std::string count=std::to_string(quantity_);
    counter_.setCaption("Light cavalry: "+count);
    counter_.center();
}

int LightCavalry::attack_calculator(Type which){
    int hit=attack_;
    switch(which){
        case SWORD_MAN:
            return (int)((double)hit*1.2);
        case BOW_MAN:
            return (int)((double)hit*1.6);
        case SPEAR_MAN:
            return (int)((double)hit*0.56);
        case HEAVY_CAVALRY:
            return (int)((double)hit*0.91);
        case LIGHT_CAVALRY:
            return hit;
        case KNIGHT:
            return (int)((double)hit*0.88);
        case CROSSBOWMAN:
            return (int)((double)hit*1.36);
        case BILLMAN:
            return (int)((double)hit*0.4);
        case AXEMAN:
            return (int)((double)hit*1.2);
    }
}

void LightCavalry::launch_window(sf::RenderWindow &window){
    int count;
    window1_.create(nMoney_, nPeople_, nIron_, (int) upgradeTime_, "Light cavalry", window, count);
}
