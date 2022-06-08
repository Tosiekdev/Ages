//
// Created by tosiek on 16.02.2022.
//

#ifndef AGES1_HANDLEBARRACKS_H
#define AGES1_HANDLEBARRACKS_H

#include "HandleBuildings.h"

class HandleBarracks : public HandleBuildings{
public:
    void create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld) override;
    void handle_events(Event &event, RenderWindow &window, int &scene) override;
    void do_stuff(RenderWindow &window) override;
    void display(RenderWindow &window) override;

};


#endif //AGES1_HANDLEBARRACKS_H
