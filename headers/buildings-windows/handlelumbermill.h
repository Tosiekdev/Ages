//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_HANDLELUMBERMILL_H
#define AGES1_HANDLELUMBERMILL_H

#include "handlebuildings.h"

class HandleLumberMill : public HandleBuildings{
public:
    void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;
    void create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni, int *iron,
                int *bld) override;

private:
    Label current, next;
};


#endif //AGES1_HANDLELUMBERMILL_H
