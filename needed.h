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
#include "Upgrade_tablet.h"
#include "HandleStonePit.h"
#include "HandleFarm.h"
#include "HandleLumberMill.h"
#include "HandleManu.h"
#include "HandleTownHall.h"
#include "HandleWarehouse.h"
#include "HandleWoSaving.h"
#include "HandleAcademy.h"
#include "HandleBarracks.h"
#include "SaveSystem.h"

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
    5-town_hall 6-farm 7-lumber_mill 8-stone pit 9-ware house
    10-academy 11-barracks
    */

    //village
    string name,save_path;
    SaveSystem save_system;
    std::array<int,8> levels;//0-academy, 1-barracks, 2-church, 3-farm, 4-lumber, 5-stone, 6-town_hall,7-warehouse
    buildings b_academy,b_barracks,b_church,b_farm,b_lumber,b_stone,b_town,b_magazine;
    std::array<buildings*,8> b_ptr;
    int human,rock,wood;
    Texture background_menu_texture;
    Sprite background_menu_sprite;

    //wexit
    ExitWindow exitWindow;

    //menu
    HandleMenu menu;

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

    HandleTownHall th_window; //town hall
    HandleFarm farm_window;//farm
    HandleLumberMill lm_window;//lumber mill
    HandleStonePit sp_window;//stone pit
    HandleWarehouse wh_window;//warehouse
    HandleAcademy academy_window;//academy
    HandleBarracks barracks_window;//barracks
    HandleWoSaving wsWindow;//window to make sure that user want exit without saving

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

    //game
    void create_game();
    void game();
    void g_handle_event();
    void g_stuff();
    void display_game();
    void create_buildings();
    void prepare_buildings();
    void save_game();
    void assign_levels();
    void disactivate_buildings();
    void activate_buildings();

    void launch_th();//town hall
    void launch_farm();//farm
    void launch_lm();//lumber mill
    void launch_sp();//stone pit
    void launch_wh();//warehouse
    void launch_academy();//academy
    void launch_barracks();

    //threads functions
    void clocks();
};


#endif //AGES1_NEEDED_H
