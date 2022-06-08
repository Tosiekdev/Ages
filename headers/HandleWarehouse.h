//
// Created by tosiek on 14.02.2022.
//

#ifndef AGES1_HANDLEWAREHOUSE_H
#define AGES1_HANDLEWAREHOUSE_H

#include "HandleBuildings.h"

class HandleWarehouse : public HandleBuildings{
public:
    void create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld) override;
    void handle_events(Event &event, RenderWindow &window, int &scene) override;
    void do_stuff(RenderWindow &window) override;
    void display(RenderWindow &window) override;

private:
    Label current, next;
};


#endif //AGES1_HANDLEWAREHOUSE_H
