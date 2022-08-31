//
// Created by tosiek on 25.08.22.
//

#ifndef AGES1_ARCHER_H
#define AGES1_ARCHER_H

#include "soldier.h"

class Archer : public Soldier{
public:
    Archer();

    //train
    void update_counter() override;

    //battle
    int attack_calculator(Type which) override;

private:
    Type type_=BOW_MAN;
};


#endif //AGES1_ARCHER_H
