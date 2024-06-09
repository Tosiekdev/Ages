//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_BUILDINGS_H
#define AGES1_BUILDINGS_H


#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

#include "ui/label.h"

class buildings
{
public:
    enum class Scene {
        MENU=1,
        CREATE=2,
        LOAD=3,
        GAME=4,
        TOWN_HALL=5,
        FARM=6,
        LUMBER_MILL=7,
        STONE_PIT=8,
        WAREHOUSE=9,
        ACADEMY=10,
        BARRACKS=11,
        CHURCH=12,
        BANK=13,
        IRON_MINE=14,
        MAP=15
    };
    int take_resources(int &human, int &rock, int &wood); //takes resources
    void end_upgrade(); //finalize upgrade
    void create_building(std::string nm,const std::string& tx_path,int lvl,sf::Vector2f pos,int ns,int nw,int np); //load asset for building_
    void show(sf::RenderWindow &W); //draws building_ with background
    void show_demands(sf::Vector2f pos, sf::RenderWindow &window);
    bool isClicked(int posX, int posY); //check if building_ was clicked
    bool onFocus(int pos_x, int pos_y);//check if cursor_ is on the building_
    int get_level() const;//returns level_
    void set_level(int lvl);//set new level_
    bool status() const;//returns status
    void set_status(bool new_status);//set status
    void activate(); //make building_ Clickable
    void deactivate(); //make building_ un-Clickable
private:
    int level_;
    int nStone_,nWood_,nHuman_; //needed resources

    //building_
    std::string name_;
    sf::Texture look_;
    sf::Sprite view_;
    sf::Vector2f possition_;
    Label sName_;
    bool active_;

    //star
    std::string lvl_caption;
    sf::Texture starLook_;
    sf::Sprite starView_;
    sf::Vector2f starPossition_;
    Label lvlLabel_;
    void create_star();

    //demands
    Label forStone_, forWood_, forHuman_;
    bool inUpgrade_=false;
};


#endif //AGES1_BUILDINGS_H
