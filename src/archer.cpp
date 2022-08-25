//
// Created by tosiek on 25.08.22.
//

#include "../headers/archer.h"

Archer::Archer(){
    //set stats
    hp_=75;
    armor_=25;
    attack_=60;
    quantity_=0;

    //set demands
    nIron_=2;
    nPeople_=1;
    nMoney_=5;
    upgrade_time_=2;

    //set _look
    texture_.loadFromFile("Textures/Units/archer.png");
    view_.setTexture(this->texture_);

    //name and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT, 0, 0,"Archer: "+std::to_string(quantity_), 12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void Archer::update_counter(){
    std::string count=std::to_string(quantity_);
    counter_.setCaption("Archer: "+count);
    counter_.center();
}

int Archer::attack_calculator(Type which){
    int hit=attack_;
    switch(which){
        case SWORD_MAN:
            return (int)((double)hit*1.2);
        case BOW_MAN:
            return hit;
        case SPEAR_MAN:
            return (int)((double)hit*1.1);
        case HEAVY_CAVALRY:
            return (int)((double)hit*0.5);
        case LIGHT_CAVALRY:
            return (int)((double)hit*0.7);
    }
}
