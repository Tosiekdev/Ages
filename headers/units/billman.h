//
// Created by tosiek on 29.08.22.
//

#ifndef AGES1_BILLMAN_H
#define AGES1_BILLMAN_H

#include "soldier.h"

class Billman : public Soldier {
public:
    Billman();

    //train
    void update_counter() override;

    //battle
    int attack_calculator(Type which) override;

    //upgrading
    void launch_window(sf::RenderWindow &window) override;

private:
    Type type_=BILLMAN;

};


#endif //AGES1_BILLMAN_H
