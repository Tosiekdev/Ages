//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_HANDLELUMBERMILL_H
#define AGES1_HANDLELUMBERMILL_H

#include "HandleBuildings.h"

class HandleLumberMill : public HandleBuildings{
public:
    void handle_events(Event &event, RenderWindow &window, int &scene) override;
    void do_stuff(RenderWindow &window) override;
    void display(RenderWindow &window) override;
    void create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld) override;

private:
    Label current, next;
};


#endif //AGES1_HANDLELUMBERMILL_H
