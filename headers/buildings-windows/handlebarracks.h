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

    void slide_to_left();
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

public:
    void create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld) override;
    void handle_events(sf::Event &event, sf::RenderWindow &window, int &scene) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;
};


#endif //AGES1_HANDLEBARRACKS_H
