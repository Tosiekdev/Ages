//
// Created by tosiek on 18.09.22.
//

#ifndef AGES1_HANDLEIRONMINE_H
#define AGES1_HANDLEIRONMINE_H

#include "handlebuildings.h"

class HandleIronMine : public HandleBuildings {
public:
    //default
    void handle_events(sf::Event &event, sf::RenderWindow &window, buildings::Scene &scene) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;
    void create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni, int *iron,
                int *bld) override;

private:
    Label current_, next_;
};


#endif //AGES1_HANDLEIRONMINE_H
