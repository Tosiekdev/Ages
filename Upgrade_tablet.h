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

    sf::Vector2f Return_position();
    void set_position(Vector2f new_pos);

private:
    //building that it is responsible for
    buildings *responsible{};

    //building name
    Label name;

    //timer for upgrade
    sf::Clock timer;
    sf::Vector2f position;
    Button upgrade;
};


#endif //AGES1_UPGRADE_TABLET_H
