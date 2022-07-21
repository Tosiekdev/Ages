//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_HANDLEFARM_H
#define AGES1_HANDLEFARM_H

#include "HandleBuildings.h"

class HandleFarm : public HandleBuildings{
public:
    //default
    void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;
    void create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld) override;

private:
    Label f_current, f_next, f_capacity, f_next_capacity;
};


#endif //AGES1_HANDLEFARM_H
