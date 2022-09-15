//
// Created by tosiek on 17.02.2022.
//

#ifndef AGES1_HANDLECHURCH_H
#define AGES1_HANDLECHURCH_H

#include "handlebuildings.h"

class HandleChurch : public HandleBuildings{
public:
    void create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni, int *iron,
                int *bld) override;
    void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;
};


#endif //AGES1_HANDLECHURCH_H
