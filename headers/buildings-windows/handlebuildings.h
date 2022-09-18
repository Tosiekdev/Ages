//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_HANDLEBUILDINGS_H
#define AGES1_HANDLEBUILDINGS_H

#include "../ui/button.h"
#include "../ui/label.h"
#include <string>

class HandleBuildings{
public:
    virtual void
    create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni, int *iron,
           int *bld) =0;
    void main_loop(sf::Event &event, sf::RenderWindow &window, int &scene);
    virtual void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene)=0;
    virtual void do_stuff(sf::RenderWindow &window)=0;
    virtual void display(sf::RenderWindow &window)=0;
    void create_return_button();
    void resource_look();
    void show_resources(sf::RenderWindow &window);
    void crete_info();
    void return_to_village(int &scene);
    void assign_values(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd,
                       int *bld, int *moni, int *iron);

protected:
    Button returnToGame_;
    Label *lHuman_, *lRock_, *lWood_, *lMoney_, *lIron_;
    Label info_;
    sf::Cursor cursor_;
    int *human_, *rock_, *wood_, *building_, *money_, *iron_;
};


#endif //AGES1_HANDLEBUILDINGS_H
