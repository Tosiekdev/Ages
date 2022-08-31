//
// Created by tosiek on 20.08.22.
//

#ifndef AGES1_SPEARMAN_H
#define AGES1_SPEARMAN_H

#include "soldier.h"

class Spearman : public Soldier{
public:
    Spearman();

    //train
    void update_counter() override;

    //battle
    int attack_calculator(Type which) override;

private:
    Type _type=SPEAR_MAN;
};


#endif //AGES1_SPEARMAN_H
