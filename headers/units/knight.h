//
// Created by tosiek on 29.08.22.
//

#ifndef AGES1_KNIGHT_H
#define AGES1_KNIGHT_H

#include "soldier.h"

class Knight : public Soldier {
public:
    Knight();

    //train
    void update_counter() override;

    //battle
    int attack_calculator(Type which) override;

    //upgrading
    int launch_window(sf::RenderWindow &window) override;

private:
    Type type_=KNIGHT;
};


#endif //AGES1_KNIGHT_H
