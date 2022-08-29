//
// Created by tosiek on 26.08.22.
//

#ifndef AGES1_HEAVYCAVALRY_H
#define AGES1_HEAVYCAVALRY_H

#include "soldier.h"

class HeavyCavalry : public Soldier {
public:
    HeavyCavalry();

    //train
    void update_counter() override;

    //battle
    int attack_calculator(Type which) override;

private:
    Type type_=HEAVY_CAVALRY;
};


#endif //AGES1_HEAVYCAVALRY_H
