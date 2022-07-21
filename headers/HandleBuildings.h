//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_HANDLEBUILDINGS_H
#define AGES1_HANDLEBUILDINGS_H

#include "button.h"
#include "label.h"
#include <string>

class HandleBuildings{
public:
    ~HandleBuildings();
    virtual void create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld)=0;
    void main_loop(sf::Event &event, sf::RenderWindow &window, int &scene);
    virtual void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene)=0;
    virtual void do_stuff(sf::RenderWindow &window)=0;
    virtual void display(sf::RenderWindow &window)=0;
    void create_return_button();
    void resource_look();
    void show_resources(sf::RenderWindow &window);
    void crete_info();
    void return_to_village(int &scene);
    void assign_values(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld);
protected:
    Button return_to_game;
    Label *l_human, *l_rock, *l_wood;
    Label info;
    sf::Cursor cursor;
    int *human, *rock, *wood, *building;
};


#endif //AGES1_HANDLEBUILDINGS_H
