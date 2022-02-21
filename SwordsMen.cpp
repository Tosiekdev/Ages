//
// Created by tosiek on 21.02.2022.
//

#include "SwordsMen.h"

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

    //set look
    this->texture.loadFromFile("Textures/swordman.png");
    this->view.setTexture(this->texture);
}

void SwordsMen::set_position(sf::Vector2f pos){
    this->view.setPosition(pos);
}

//to make showing unit easier
void SwordsMen::slide(float shift){
    sf::Vector2f position=this->view.getPosition();
    position.x+=shift;
    this->view.setPosition(position);
}

//this happens when player try to make upgrade
std::array<int, 3> SwordsMen::take_resources(int people,int iron,int money){
    //assign resources that we can return it
    std::array<int,3> resources{};
    resources[0]=people;
    resources[1]=iron;
    resources[2]=money;

    if(this->n_people<=people,this->n_money<=money,this->n_iron<=iron){
        //take needed resources
        resources[0]-=this->n_people;
        resources[1]-=this->n_iron;
        resources[2]-=this->n_money;

        this->time_left=this->upgrade_time;

        this->in_upgrade=true;
    }

    return resources;
}

//this happens when time needed to upgrade passed
void SwordsMen::end_upgrade(){
    this->in_upgrade=false;
}

void SwordsMen::reset_timer(){
    this->for_upgrade.restart();
}

void SwordsMen::get_time(){
    this->for_upgrade.getElapsedTime().asSeconds();
}

float SwordsMen::get_time_left(){
    return this->time_left;
}

void SwordsMen::load_left(float time){
    this->time_left=time;
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
    std::vector<int> lives;

    for(int i=0; i<quantity; i++)
        lives.push_back(this->hp);
}
