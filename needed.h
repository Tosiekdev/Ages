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
#include "HandleStonePit.h"
#include "HandleFarm.h"
#include "HandleLumberMill.h"
#include "HandleManu.h"

using namespace sf;
using namespace std;

class Application
{
private:
    RenderWindow screen;
    Vector2i possition;
    Cursor cursor;
    Event e;
    int height,width,max_fps;
    int scene;
    /*
    1-menu 2-create 3-load 4-game
    5-town_hall 6-farm 7-lumber_mill 8-stone pit
    */

    //village
    string name,save_path;
    int academy,barracks,church,farm,lumber_mill,stone_pit,town_hall,magazine;
    buildings b_academy,b_barracks,b_church,b_farm,b_lumber,b_stone,b_town,b_magazine;
    buildings *b_ptr[8];
    int human,rock,wood;
    Texture background_menu_texture;
    Sprite background_menu_sprite;

    //wexit
    ExitWindow exitWindow;

    //menu
    HandleManu menu;

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

    Button return_to_game;

    //town hall
    Upgrade_tablet u_buildings[8];
    map<int,string> num_to_names{
        {1,"Academy"},
        {2,"Barracks"},
        {3,"Church"},
        {4,"Farm"},
        {5,"Lumber Mill"},
        {6,"Stone Pit"},
        {7,"Town Hall"},
        {8,"Warehouse"}
    };
    Label th_info;

    //farm
    HandleFarm farm_window;

    //lumber mill
    HandleLumberMill lm_window;

    //stone pit
    HandleStonePit sp_window;

    //window to make sure that user want exit without saving
    RenderWindow wsaving;
    Label no_save, ns_pt2;
    Event e_save;
    Button am_sure, not_sure;

public:
    Application();
    void main_window();
    void return_to_village();
    void resources_1();

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

    //return to game button
    void create_return_button();
    void show_return_button();
    void return_button_clicked(int pos_x, int pos_y);
    bool return_button_focused(int pos_x, int pos_y);

    //town hall
    void create_townhall();
    void townhall();
    void th_handle_event();
    void th_stuff();
    void display_townhall();

    //farm
    void launch_farm();

    //lumber mill
    void launch_lm();

    //stone pit
    void launch_sp();

    //threads functions
    void clocks();
};


#endif //AGES1_NEEDED_H
