//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_HANDLETOWNHALL_H
#define AGES1_HANDLETOWNHALL_H

#include "HandleBuildings.h"
#include "Upgrade_tablet.h"
#include "buildings.h"

#include <map>

class HandleTownHall : public HandleBuildings{
public:
    //default
    void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;
    void create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld) override;

    //uniq
    void crete_ub(buildings* resp, sf::Vector2f pos, int index);
    void set_ub_left(int index,float time,float th);
    float get_ub_left(int index);
    float ub_get_time(int index);
    void ub_reset_timer(int index);
    int ub_update_timer(int index, float time_passed);
    void ub_update_level(int index);

private:
    std::map<int,std::string> num_to_names{
            {1,"Academy"},
            {2,"Barracks"},
            {3,"Church"},
            {4,"Farm"},
            {5,"Lumber Mill"},
            {6,"Stone Pit"},
            {7,"Town Hall"},
            {8,"Warehouse"}
    };
    Upgrade_tablet u_buildings[8];
};


#endif //AGES1_HANDLETOWNHALL_H
