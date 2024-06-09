//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_EXITWINDOW_H
#define AGES1_EXITWINDOW_H

#include "handlewindow.h"
#include "ui/label.h"
#include "ui/button.h"

class ExitWindow : public HandleWindow{
public:
    void create(sf::RenderWindow &W, buildings::Scene &scene);
    void main_loop(sf::RenderWindow &window, buildings::Scene &scene) override;
    void handle_event(buildings::Scene &scene, sf::RenderWindow &window) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;

private:
    sf::RenderWindow wExit_;
    Label sure_;
    sf::Event exitE_;
    Button yes_,no_;
    sf::Cursor cursor_;
};


#endif //AGES1_EXITWINDOW_H
