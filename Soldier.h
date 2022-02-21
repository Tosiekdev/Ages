//
// Created by tosiek on 21.02.2022.
//

#ifndef AGES1_SOLDIER_H
#define AGES1_SOLDIER_H

#include <array>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Battle.h"

class Soldier{
public:
    virtual std::array<int,3> take_resources(int people,int iron,int money)=0;
    virtual void end_upgrade()=0;
    virtual std::vector<int> give_damage(Type which, std::vector<int> old_damage)=0;
    virtual void take_damage(std::vector<int> damage)=0;
    virtual void set_position(sf::Vector2f pos)=0;
    virtual void slide(float shift)=0;
    virtual void reset_timer()=0;
    virtual void get_time()=0;
    virtual float get_time_left()=0;
    virtual void load_left(float time)=0;
    virtual int attack_calculator(Type which)=0;

protected:
    int hp{}, attack{}, armor{}, quantity{}, n_people{}, n_iron{}, n_money{};
    float upgrade_time{}, time_left{};
    bool in_upgrade=false;
    sf::Clock for_upgrade;
    sf::Sprite view;
    sf::Texture texture;
};


#endif //AGES1_SOLDIER_H
