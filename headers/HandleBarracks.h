//
// Created by tosiek on 16.02.2022.
//

#ifndef AGES1_HANDLEBARRACKS_H
#define AGES1_HANDLEBARRACKS_H

#include "HandleBuildings.h"
#include "swordsman.h"
#include "spearman.h"
#include "archer.h"
#include "Clickable.h"

class HandleBarracks : public HandleBuildings{
    SwordsMen swordsMen_;
    Spearman spearman_;
    Archer archer_;

    Clickable slide_left;
    Clickable slide_right;

    void slide_to_left();
    void slide_to_right();

public:
    void create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld) override;
    void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;
};


#endif //AGES1_HANDLEBARRACKS_H
