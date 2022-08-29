//
// Created by tosiek on 29.08.22.
//

#ifndef AGES1_LIGHTCAVALRY_H
#define AGES1_LIGHTCAVALRY_H

#include "soldier.h"

class LightCavalry : public Soldier {
public:
    LightCavalry();

    //train
    void update_counter() override;

    //battle
    int attack_calculator(Type which) override;

private:
    Type type_=LIGHT_CAVALRY;
};


#endif //AGES1_LIGHTCAVALRY_H
