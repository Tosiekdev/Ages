//
// Created by tosiek on 31.08.22.
//

#ifndef AGES1_AXEMAN_H
#define AGES1_AXEMAN_H

#include "soldier.h"

class Axeman : public Soldier {
public:
    Axeman();

    //train
    void update_counter() override;

    //battle
    int attack_calculator(Type which) override;

    //upgrading
    int launch_window(sf::RenderWindow &window) override;

private:
    Type type_=AXEMAN;
};


#endif //AGES1_AXEMAN_H
