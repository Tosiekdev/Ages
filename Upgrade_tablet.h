//
// Created by tosiek on 02.02.2022.
//

#ifndef AGES1_UPGRADE_TABLET_H
#define AGES1_UPGRADE_TABLET_H

#include <SFML/Graphics.hpp>
#include <string>

#include "buildings.h"
#include "button.h"
#include "constants.h"

class Upgrade_tablet{
public:
    Upgrade_tablet();
    void create_upgrade(buildings* resp, std::string caption, sf::Vector2f pos);
    void show(sf::RenderWindow &W);

    void upgrade_building(int &human, int &rock, int &wood);

    sf::Vector2f Return_position();
    void set_position(Vector2f new_pos);

    void button_animation(Vector2i pos);
    bool button_clicked(Vector2i pos);

    float get_time();
    int update_timer(float time_passed);
    void reset_timer();

private:
    //building that it is responsible for
    buildings *responsible{};

    //building name
    Label name;

    //level star
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


#endif //AGES1_UPGRADE_TABLET_H
