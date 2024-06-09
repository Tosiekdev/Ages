//
// Created by tosiek on 14.02.2022.
//

#ifndef AGES1_HANDLEWOSAVING_H
#define AGES1_HANDLEWOSAVING_H

#include "handlewindow.h"
#include "ui/label.h"
#include "ui/button.h"

class HandleWoSaving : public HandleWindow{
public:
    void create(sf::RenderWindow &W, buildings::Scene &scene);
    void main_loop(sf::RenderWindow &window, buildings::Scene &scene) override;
    void handle_event(buildings::Scene &scene, sf::RenderWindow &window) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;

private:
    sf::RenderWindow w_saving;
    Label no_save, ns_pt2;
    sf::Event e_save;
    Button am_sure, not_sure;
    sf::Cursor cursor;
};


#endif //AGES1_HANDLEWOSAVING_H
