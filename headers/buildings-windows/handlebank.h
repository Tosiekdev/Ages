//
// Created by tosiek on 15.09.22.
//

#ifndef AGES1_HANDLEBANK_H
#define AGES1_HANDLEBANK_H

#include "handlebuildings.h"

class HandleBank : public HandleBuildings {
public:
    //default
    void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;
    void create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni, int *iron,
                int *bld) override;

private:
    Label f_current, f_next, f_capacity, f_next_capacity;
};


#endif //AGES1_HANDLEBANK_H
