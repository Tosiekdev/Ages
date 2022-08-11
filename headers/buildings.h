//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_BUILDINGS_H
#define AGES1_BUILDINGS_H


#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

#include "label.h"

class buildings
{
public:
    buildings(std::string="default",std::string="Textures/default.png",int=0,int=0,int=0,int=0,sf::Vector2f=sf::Vector2f(0,0));
    int take_resources(int &human, int &rock, int &wood); //takes resources
    void end_upgrade(); //finalize upgrade
    void create_building(std::string nm,std::string tx_path,int lvl,sf::Vector2f pos,int ns,int nw,int np); //load asset for building
    void show(sf::RenderWindow &W); //draws building with background
    void show_demands(sf::Vector2f pos, sf::RenderWindow &window);
    bool isClicked(int posx, int posy); //check if building was clicked
    bool onFocus(int pos_x, int pos_y);//check if cursor is on the building
    int get_level() const;//returns level
    void set_level(int lvl);//set new level
    bool status();//returns status
    void set_status(bool new_status);//set status
    void activate(); //make building Clickable
    void deactivate(); //make building un-Clickable
private:
    int level;
    int n_stone,n_wood,n_human; //needed resources

    //building
    std::string name;
    sf::Texture look;
    sf::Sprite view;
    sf::Vector2f possition;
    Label s_name;
    bool active;

    //star
    std::string lvl_caption;
    sf::Texture star_look;
    sf::Sprite star_view;
    sf::Vector2f star_possition;
    Label lvl_label;
    void create_star();

    //demands
    Label for_stone, for_wood, for_human;
    bool in_upgrade;
};


#endif //AGES1_BUILDINGS_H
