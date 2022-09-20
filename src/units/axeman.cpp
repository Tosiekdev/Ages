//
// Created by tosiek on 31.08.22.
//

#include "../../headers/units/axeman.h"

Axeman::Axeman(){
//set stats
    hp_=90;
    armor_=45;
    attack_=90;
    quantity_=0;

    //set demands
    nIron_=4;
    nPeople_=1;
    nMoney_=8;
    upgradeTime_=5;

    //set _look
    texture_.loadFromFile("Textures/Units/axeman.png");
    view_.setTexture(this->texture_);

    //name_ and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT, 0, 0,"Axeman: "+std::to_string(quantity_), 12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void Axeman::update_counter(){
    std::string count=std::to_string(quantity_);
    counter_.setCaption("Axeman: "+count);
    counter_.center();
}

int Axeman::attack_calculator(Type which) {
    int hit=attack_;
    switch(which){
        case SWORD_MAN:
            return (int)((double)hit*1.1);
        case BOW_MAN:
            return (int)((double)hit*1.6);
        case SPEAR_MAN:
            return hit;
        case HEAVY_CAVALRY:
            return (int)((double)hit*0.8);
        case LIGHT_CAVALRY:
            return (int)((double)hit*1.1);;
        case KNIGHT:
            return (int)((double)hit*0.8);
        case CROSSBOWMAN:
            return (int)((double)hit*1.2);
        case BILLMAN:
            return (int)((double)hit*0.95);
        case AXEMAN:
            return hit;
    }
}

void Axeman::launch_window(sf::RenderWindow &window){
    int count;
    window1_.create(nMoney_, nPeople_, nIron_, (int) upgradeTime_, "Axeman", window,count);
}
