//
// Created by tosiek on 11.08.22.
//

#include "../headers/Soldier.h"

//this happens when player try to make upgrade
std::array<int,3> Soldier::take_resources(int people,int iron,int money){
    //assign resources that we can return it
    std::array<int,3> resources{people,iron,money};

    if(this->n_people<=people && this->n_money<=money && this->n_iron<=iron){
        //take needed resources
        resources[0]-=this->n_people;
        resources[1]-=this->n_iron;
        resources[2]-=this->n_money;

        this->time_left=this->upgrade_time;

        this->in_upgrade=true;
    }

    return resources;
}

//to make showing unit easier
void Soldier::slide(float shift){
    sf::Vector2f position=this->view.getPosition();
    position.x+=shift;
    this->view.setPosition(position);
}