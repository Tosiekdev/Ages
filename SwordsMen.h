//
// Created by tosiek on 21.02.2022.
//

#ifndef AGES1_SWORDSMEN_H
#define AGES1_SWORDSMEN_H

#include "Soldier.h"

class SwordsMen : public Soldier{
public:
    SwordsMen();

    //sprite
    void set_position(sf::Vector2f pos) override;
    void slide(float shift) override;

    //upgrade
    std::array<int,3> take_resources(int people,int iron,int money) override;
    void end_upgrade() override;

    //timer
    void reset_timer() override;
    void get_time() override;

    //save
    float get_time_left() override;
    void load_left(float time) override;

    //battle
    std::vector<int> give_damage(Type which,std::vector<int> old_damage) override;
    int attack_calculator(Type which) override;
    void take_damage(std::vector<int> damage) override;

private:
    Type type=SWORD_MAN;
};


#endif //AGES1_SWORDSMEN_H
