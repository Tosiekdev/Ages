//
// Created by tosiek on 26.08.22.
//

#include "../../headers/units/heavycavalery.h"

HeavyCavalry::HeavyCavalry(){
    //set stats
    hp_=200;
    armor_=75;
    attack_=120;
    quantity_=0;

    //set demands
    nIron_=15;
    nPeople_=3;
    nMoney_=20;
    upgradeTime_=10;

    //set _look
    texture_.loadFromFile("Textures/Units/h_cavalry.png");
    view_.setTexture(texture_);

    //name_ and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT, 0, 0,"Heavy cavalry: "+std::to_string(quantity_), 12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void HeavyCavalry::update_counter(){
    std::string count=std::to_string(quantity_);
    counter_.setCaption("Heavy cavalry: "+count);
    counter_.center();
}

int HeavyCavalry::attack_calculator(Type which){
    int hit=attack_;
    switch(which){
        case SWORD_MAN:
            return (int)((double)hit*1.5);
        case BOW_MAN:
            return (int)((double)hit*2);
        case SPEAR_MAN:
            return (int)((double)hit*0.7);
        case HEAVY_CAVALRY:
            return hit;
        case LIGHT_CAVALRY:
            return (int)((double)hit*1.1);
        case KNIGHT:
            return (int)((double)hit*1.11);
        case CROSSBOWMAN:
            return (int)((double)hit*1.7);
        case BILLMAN:
            return (int)((double)hit*0.5);
        case AXEMAN:
            return (int)((double)hit*1.5);
    }
}

int HeavyCavalry::launch_window(sf::RenderWindow &window){
    int count;
    window1_.create(nMoney_, nPeople_, nIron_, (int) upgradeTime_, "Heavy cavalry", window, count);
    return count;
}
