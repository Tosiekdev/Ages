//
// Created by tosiek on 14.02.2022.
//

#ifndef AGES1_HANDLEWAREHOUSE_H
#define AGES1_HANDLEWAREHOUSE_H

#include "handlebuildings.h"

class HandleWarehouse : public HandleBuildings{
public:
    void create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni, int *iron,
                int *bld) override;
    void handle_events(sf::Event &event, sf::RenderWindow &window, buildings::Scene &scene) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;

private:
    Label current, next;
};


#endif //AGES1_HANDLEWAREHOUSE_H
