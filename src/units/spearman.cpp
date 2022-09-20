//
// Created by tosiek on 20.08.22.
//

#include "../../headers/units/spearman.h"

Spearman::Spearman(){
    //set stats
    this->hp_=80;
    this->armor_=45;
    this->attack_=85;
    this->quantity_=0;

    //set demands
    this->nIron_=4;
    this->nPeople_=1;
    this->nMoney_=8;
    this->upgradeTime_=4;

    //set _look
    this->texture_.loadFromFile("Textures/Units/spearman.png");
    this->view_.setTexture(this->texture_);

    //name_ and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT, 0, 0,"Spearman: "+std::to_string(quantity_), 12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void Spearman::update_counter(){
    std::string count=std::to_string(quantity_);
    counter_.setCaption("Spearman: "+count);
    counter_.center();
}

int Spearman::attack_calculator(Type which){
    switch(which){
        case SWORD_MAN:
            return (int)((double)attack_ * 0.95);
        case BOW_MAN:
            return (int)((double)attack_ * 1.5);
        case SPEAR_MAN:
            return attack_;
        case HEAVY_CAVALRY:
            return (int)((double)attack_ * 1.3);
        case LIGHT_CAVALRY:
            return (int)((double)attack_ * 1.55);
        case KNIGHT:
            return (int)((double)attack_ * 0.86);
        case CROSSBOWMAN:
            return (int)((double)attack_ * 1.25);
        case BILLMAN:
            return (int)((double)attack_ * 0.83);
        case AXEMAN:
            return (int)((double)attack_ * 0.95);
    }
}

void Spearman::launch_window(sf::RenderWindow &window){
    int count;
    window1_.create(nMoney_, nPeople_, nIron_, (int) upgradeTime_, "Spearman", window, count);
}
