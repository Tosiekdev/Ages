//
// Created by tosiek on 21.02.2022.
//

#include "../headers/SwordsMen.h"

SwordsMen::SwordsMen(){
    //set stats
    this->hp=100;
    this->armor=50;
    this->attack=75;
    this->quantity=0;

    //set demands
    this->n_iron=5;
    this->n_people=1;
    this->n_money=10;
    this->upgrade_time=5;

    //set _look
    this->texture.loadFromFile("Textures/swordsman.png");
    this->view.setTexture(this->texture);

    //name and button to upgrade
    name_.create_obstacle("Textures/plank.png",sf::Vector2f(0.1,0.1),sf::Vector2f(0,0));
    upgrade_.create(60,100,0,0,"Upgrade");
}

//this happens when time needed to upgrade passed
void SwordsMen::end_upgrade(){
    this->in_upgrade=false;
    this->lives.push_back(this->hp);
}

//returns vector of damage to hurt others
std::vector<int> SwordsMen::give_damage(Type which,std::vector<int> old_damage) {
    for(int i=0; i<this->quantity; i++)
        old_damage.push_back(this->attack_calculator(which));

    return old_damage;
}

int SwordsMen::attack_calculator(Type which){
    int hit=this->attack;
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
    }
}

void SwordsMen::take_damage(std::vector<int> damage){
    size_t j=0;
    while(j<damage.size()){
        if(lives[j%lives.size()]>0){
            lives[j%lives.size()]-=damage[j];
            j++;
        }
        if(j>damage.size()){ break; }
    }
}

void SwordsMen::set_position(sf::Vector2f pos){
    this->view.setPosition(pos);

    sf::Vector2f name_pos=pos+sf::Vector2f(-1,113);
    name_.set_position(name_pos);

    sf::Vector2f button_pos=name_pos+sf::Vector2f(1,35);
    upgrade_.set_position(button_pos);
}
