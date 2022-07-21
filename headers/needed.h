//
// Created by tosiek on 04.12.2021.
//

#ifndef AGES1_NEEDED_H
#define AGES1_NEEDED_H


#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <thread>
#include <array>

#include "button.h"
#include "label.h"
#include "textbox.h"
#include "tablet.h"
#include "clickable.h"
#include "buildings.h"
#include "obstacle.h"
#include "constants.h"
#include "HandleManu.h"
#include "HandleGame.h"

class Application
{
private:
    sf::RenderWindow screen;
    sf::Vector2i possition;
    sf::Cursor cursor;
    sf::Event e;
    int height,width,max_fps;
    int scene;
    /*
    1-menu 2-create 3-load 4-game
    5-town_hall 6-farm 7-lumber_mill 8-stone pit 9-ware house
    10-academy 11-barracks 12-church
    */

    //village
    string name,save_path;
    int human,rock,wood;
    sf::Texture background_menu_texture;
    sf::Sprite background_menu_sprite;

    ExitWindow exitWindow;//w_exit
    HandleMenu menu;//menu

    //create
    Button return_button,ok_button,cancel_button;
    sf::Texture plank,obstacle_t;
    sf::Sprite space,obstacle_s;
    Label label1,label2;
    textbox t1;

    //load
    Button returning_button,load_button,remove_button;
    tablet t[5];
    clickable down,up;
    Label error_message;
    int down_level=0, focused_tablet;

    //game
    HandleGame game_window;

public:
    Application();
    void main_window();

    //data interference
    string create_city(string calling);

    //create
    void create_create();
    void create();
    void c_handle_event();
    void c_stuff();
    void display_create();
    bool textbox_rect();

    //load
    void prepare_tablets();
    void create_load();
    void load();
    void l_handle_event();
    void l_stuff();
    void display_load();
    void prepare_focused_tablets();
    void remove_save();

    void launch_game();//game

    void launch_th();//town hall
    void launch_farm();//farm
    void launch_lm();//lumber mill
    void launch_sp();//stone pit
    void launch_wh();//warehouse
    void launch_academy();//academy
    void launch_barracks();//barracks
    void launch_church();//church

    //thread functions
    void clocks();
};


#endif //AGES1_NEEDED_H
