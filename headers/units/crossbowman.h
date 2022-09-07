//
// Created by tosiek on 29.08.22.
//

#ifndef AGES1_CROSSBOWMAN_H
#define AGES1_CROSSBOWMAN_H

#include "soldier.h"

class Crossbowman : public Soldier {
public:
    Crossbowman();

    //train
    void update_counter() override;

    //battle
    int attack_calculator(Type which) override;

    //upgrading
    void launch_window(sf::RenderWindow &window) override;

private:
    Type type_=BOW_MAN;
};


#endif //AGES1_CROSSBOWMAN_H
