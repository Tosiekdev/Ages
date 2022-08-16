//
// Created by tosiek on 21.02.2022.
//

#ifndef AGES1_SWORDSMEN_H
#define AGES1_SWORDSMEN_H

#include "Soldier.h"

class SwordsMen : public Soldier{
public:
    SwordsMen();

    //train
    void update_counter() override;

    //battle
    int attack_calculator(Type which) override;

private:
    Type _type=SWORD_MAN;
};


#endif //AGES1_SWORDSMEN_H
