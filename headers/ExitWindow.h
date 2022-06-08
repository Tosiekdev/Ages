//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_EXITWINDOW_H
#define AGES1_EXITWINDOW_H

#include "HandleWindow.h"
#include "label.h"
#include "button.h"

class ExitWindow : public HandleWindow{
public:
    void create(sf::RenderWindow &W, int &scene);
    void main_loop(sf::RenderWindow &window, int &scene) override;
    void handle_event(int &scene, sf::RenderWindow &window) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;

private:
    sf::RenderWindow w_exit;
    Label sure;
    Event exit_e;
    Button yes,no;
    sf::Cursor cursor;
};


#endif //AGES1_EXITWINDOW_H
