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
    void set_position(sf::Vector2f pos) override { this->view.setPosition(pos); }

    //upgrade
    void end_upgrade() override;

    //timer
    void reset_timer() override { this->for_upgrade.restart(); }
    void get_time() override { this->for_upgrade.getElapsedTime().asSeconds(); }

    //save
    float get_time_left() override { return this->time_left; }
    void load_left(float time) override { this->time_left=time; }

    //battle
    std::vector<int> give_damage(Type which,std::vector<int> old_damage) override;
    int attack_calculator(Type which) override;
    void take_damage(std::vector<int> damage) override;

    //displaying
    void display_image(sf::RenderWindow& window) override { window.draw(this->view); }

private:
    Type _type=SWORD_MAN;
};


#endif //AGES1_SWORDSMEN_H
