//
// Created by tosiek on 28.09.22.
//

#ifndef AGES1_MAP_H
#define AGES1_MAP_H

#include "../handlewindow.h"
#include "../ui/button.h"
#include "../ui/obstacle.h"
#include "../ui/clickable.h"

class Map : public HandleWindow {
    Button return_; //Button to return to main game
    sf::View view_; //Camera in the map
    sf::Cursor cursor_; //Window cursor

    Obstacle world_; //Map of the world

    /**
     * Controls
     * @param left_ Navigation button to see left side of the map
     * @param right_ Navigation button to see right side of the map
     * @param top_ Navigation button to see top side of the map
     * @param bottom_ Navigation button to see bottom side of the map
     */
    Clickable left_,right_,top_,bottom_;

    /**
     * Checking if any navigation bar is clicked
     * @param window Game's window
     */
    void moving_map(sf::RenderWindow &window);
    /**
     * Function handling proper display of control buttons/
     * @param shift Information about how map is shifted
     */
    void shift_controls(sf::Vector2f shift);

public:
    Map();
    /**
     * Function to set all needed settings for map.
     */
    void create();
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
