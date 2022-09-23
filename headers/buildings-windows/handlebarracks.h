//
// Created by tosiek on 16.02.2022.
//

#ifndef AGES1_HANDLEBARRACKS_H
#define AGES1_HANDLEBARRACKS_H

#include "handlebuildings.h"

#include "../units/swordsman.h"
#include "../units/spearman.h"
#include "../units/archer.h"
#include "../units/heavycavalery.h"
#include "../units/lightcavalry.h"
#include "../units/knight.h"
#include "../units/crossbowman.h"
#include "../units/billman.h"
#include "../units/axeman.h"

#include "../ui/clickable.h"

class HandleBarracks : public HandleBuildings{
    Swordsman swordsman_;
    Spearman spearman_;
    Archer archer_;
    HeavyCavalry heavyCavalry_;
    LightCavalry lightCavalry_;
    Knight knight_;
    Crossbowman crossbowman_;
    Billman billman_;
    Axeman axeman_;

    Clickable slideLeft_;
    Clickable slideRight_;

    /**
     * Sliding cards with units to the left
     */
    void slide_to_left();
    /**
     * Sliding cards with units to the right
     */
    void slide_to_right();

    /**
     * Slides card with unit to the left
     * @tparam T type of unit
     * @param card card to slide
     */
    template<class T>
            void left_slider(T& card);

    /**
     * Slides card with unit to the left
     * @tparam T type of unit
     * @param card card to slide
     */
    template<class T>
            void right_slider(T& card);

    /**
     * Function to checking if train button of any unit is clicked
     * @param mPos Mouse position in the moment of click
     */
    void launch_windows(sf::Vector2i mPos, sf::RenderWindow& window);

    /**
     * Function checking single unit to open training window.
     * @tparam T Type of unit.
     * @param window Main window of the game, needed to proper display of training window.
     */
    template<class T>
            void launch_single(sf::Vector2i mPos, sf::RenderWindow& window, T& unit);

public:
    /**
     * Function to create barracks' window
     * @param lh Pointer to label containing quantity of humans
     * @param lr Pointer to label containing quantity of rocks
     * @param lw Pointer to label containing quantity of wood
     * @param lm Pointer to label containing quantity of money
     * @param li Pointer to label containing quantity of iron
     * @param hn Pointer to label containing quantity of humans
     * @param rk Pointer to quantity of human
     * @param wd Pointer to quantity of wood
     * @param moni Pointer to quantity of money
     * @param iron Pointer to quantity of iron
     * @param bld Pointer to barracks level
     */
    void create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni, int *iron,
                int *bld) override;
    /**
     * Function to handle player's input
     * @param event Main game's event (pretty unnecessary tbh)
     * @param window Main game's window
     * @param scene Main game's scene
     */
    void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene) override;
    /**
     * This function do stuff every frame
     * @param window Main game's window
     */
    void do_stuff(sf::RenderWindow &window) override;
    /**
     * Function to display everything to game's window.
     * @param window Main game's window.
     */
    void display(sf::RenderWindow &window) override;
    /**
     * Function to maintaining time of units in upgrade
     */
    void update_timer();
};


#endif //AGES1_HANDLEBARRACKS_H
