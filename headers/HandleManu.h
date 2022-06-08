//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_HANDLEMANU_H
#define AGES1_HANDLEMANU_H

#include "HandleWindow.h"
#include "button.h"
#include "label.h"
#include "ExitWindow.h"

class HandleMenu : public HandleWindow{
public:
    void create();
    void main_loop(sf::RenderWindow &window, int &scene) override;
    void handle_event(int &scene, sf::RenderWindow &window) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;

private:
    Button new_game,load_game,exit;
    Texture background_menu_texture;
    Sprite background_menu_sprite;
    Label ages,programmer,graphic,tosiek,iwa;
    Event e;
    Cursor cursor;
    ExitWindow exitWindow;
};


#endif //AGES1_HANDLEMANU_H
