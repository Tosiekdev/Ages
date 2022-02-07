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

#include "button.h"
#include "label.h"
#include "textbox.h"
#include "tablet.h"
#include "clickable.h"
#include "buildings.h"
#include "obstacle.h"
#include "constants.h"
#include "Upgrade_tablet.h"

using namespace sf;
using namespace std;

class Application
{
private:
    RenderWindow screen;
    Vector2i possition;
    Event e;
    int height,width,max_fps;
    int scene;
    /*
    1-menu 2-create 3-load 4-game
    5-town_hall
    */

    //village
    string name,save_path;
    int academy,barracks,church,farm,lumber_mill,stone_pit,town_hall,magazine;
    buildings b_academy,b_barracks,b_church,b_farm,b_lumber,b_stone,b_town,b_magazine;
    buildings *b_ptr[8];
    int human,rock,wood;

    //wexit
    RenderWindow wexit;
    Label sure;
    Event exit_e;
    Button yes,no;

    //menu
    Button new_game,load_game,exit;
    Texture background_menu_texture;
    Sprite background_menu_sprite;
    Label ages,programmer,graphic,tosiek,iwa;

    //create
    Button return_button,ok_button,cancel_button;
    Texture plank,obstacle_t;
    Sprite space,obstacle_s;
    Label label1,label2;
    textbox t1;

    //load
    Button returning_button,load_button,remove_button;
    tablet t[5];
    Vector2f victor;
    clickable down,up;
    Label error_message;
    int down_level=0, focused_tablet;

    //game
    Button return_to_menu, save;
    Obstacle resource_plank, resource_man, resource_wood, resource_rock;
    Label l_human, l_rock, l_wood;
    Clock resource_clock;

    //town hall
    Button th_return_to_game;
    Upgrade_tablet u_buildings[8];
    map<int,string> num_to_names{
        {1,"Academy"},
        {2,"Barracks"},
        {3,"Church"},
        {4,"Farm"},
        {5,"Lumber Mill"},
        {6,"Stone Pit"},
        {7,"Town Hall"},
        {8,"Magazine"}
    };
    Label th_info;

    //window to make sure that user want exit without saving
    RenderWindow wsaving;
    Label no_save, ns_pt2;
    Event e_save;
    Button am_sure, not_sure;

public:
    Application();
    void u_sure(RenderWindow &W);
    void main_window();

    //data interference
    string create_city(string calling);

    //menu
    void menu();
    void m_handle_event();
    void display_menu();
    void m_stuff();

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

    //game
    void create_game();
    void game();
    void g_handle_event();
    void g_stuff();
    void display_game();
    void create_buildings();
    void prepare_buildings();
    void save_game();
    void wo_saving();
    void assign_levels();

    //town hall
    void create_townhall();
    void townhall();
    void th_handle_event();
    void th_stuff();
    void display_townhall();

    //threads functions
    void clocks();
};


#endif //AGES1_NEEDED_H
