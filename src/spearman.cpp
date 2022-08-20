//
// Created by tosiek on 20.08.22.
//

#include "../headers/spearman.h"

Spearman::Spearman(){
    //set stats
    this->hp=80;
    this->armor=45;
    this->attack=85;
    this->quantity=0;

    //set demands
    this->n_iron=4;
    this->n_people=1;
    this->n_money=8;
    this->upgrade_time_=4;

    //set _look
    this->texture_.loadFromFile("Textures/Units/spearman.png");
    this->view_.setTexture(this->texture_);

    //name and button to training
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    counter_.create(DEFAULT_FONT,0,0,"Spearman: "+std::to_string(quantity),12);
    counter_.center();
    upgrade_.create(30,60,0,0,"Train");

    //stats show
    set_stats();
}

void Spearman::update_counter(){
    std::string count=std::to_string(quantity);
    counter_.setCaption("Spearman: "+count);
    counter_.center();
}

int Spearman::attack_calculator(Type which){
    switch(which){
        case SWORD_MAN:
            return (int)((double)attack*0.95);
        case BOW_MAN:
            return (int)((double)attack*1.5);
        case SPEAR_MAN:
            return attack;
        case HEAVY_CAVALRY:
            return (int)((double)attack*1.3);
        case LIGHT_CAVALRY:
            return (int)((double)attack*1.55);
    }
}
