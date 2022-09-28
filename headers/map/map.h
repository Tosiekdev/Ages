//
// Created by tosiek on 28.09.22.
//

#ifndef AGES1_MAP_H
#define AGES1_MAP_H

#include "../handlewindow.h"
#include "../ui/button.h"

class Map : public HandleWindow {
    Button return_; //Button to return to main game


public:
    Map();
    /**
     * Function responsible for handling event.
     * @param scene Main game's scene
     * @param window Main game's window
     */
    void handle_event(int &scene, sf::RenderWindow &window) override;
    /**
     * Function to do some stuff in every frame
     * @param window Main game's window
     */
    void do_stuff(sf::RenderWindow &window) override;
    /**
     * Function to display map on the screen
     * @param window Target window
     */
    void display(sf::RenderWindow &window) override;
};


#endif //AGES1_MAP_H
