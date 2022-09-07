//
// Created by tosiek on 02.02.2022.
//

#ifndef AGES1_UPGRADETABLET_H
#define AGES1_UPGRADETABLET_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "buildings.h"
#include "ui/button.h"
#include "constants.h"

class Upgrade_tablet{
public:
    Upgrade_tablet();
    void create_upgrade(buildings* resp, std::string caption, sf::Vector2f pos);
    void show(sf::RenderWindow &W);

    void upgrade_building(int &human, int &rock, int &wood, int bonus);

    sf::Vector2f Return_position();
    void set_position(sf::Vector2f new_pos);

    bool button_animation(sf::Vector2i pos);
    bool button_clicked(sf::Vector2i pos);

    float get_time();
    int update_timer(float time_passed);
    void reset_timer();

    float get_left() const;
    void set_left(float time, float th);

    void update_level();

private:
    //building_ that it is responsible for
    buildings *responsible{};

    //building_ name_
    Label name;

    //level_ star
    sf::Texture star;
    sf::Sprite supernova;
    Label star_text;

    //timer for upgrade
    sf::Clock timer;
    sf::Vector2f position;
    float time_left;
    Label clock;
    sf::RectangleShape counting_down;

    Button upgrade;
};


#endif //AGES1_UPGRADETABLET_H
