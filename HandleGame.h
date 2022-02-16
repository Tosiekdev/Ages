//
// Created by tosiek on 16.02.2022.
//

#ifndef AGES1_HANDLEGAME_H
#define AGES1_HANDLEGAME_H

#include <array>
#include <map>

#include "HandleWindow.h"
#include "button.h"
#include "label.h"
#include "ExitWindow.h"
#include "HandleWoSaving.h"
#include "obstacle.h"
#include "buildings.h"
#include "SaveSystem.h"
#include "HandleStonePit.h"
#include "HandleFarm.h"
#include "HandleLumberMill.h"
#include "HandleTownHall.h"
#include "HandleWarehouse.h"
#include "HandleWoSaving.h"
#include "HandleAcademy.h"
#include "HandleBarracks.h"

class HandleGame : public HandleWindow{
public:
    void create(string path);
    void main_loop(sf::RenderWindow &window, int &scene) override;
    void handle_event(int &scene, sf::RenderWindow &window) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;

    void disactivate_buildings();
    void activate_buildings();
    void prepare_buildings();
    void create_buildings();
    void save_game();
    void assign_levels();
    void clocks(int scene);

    void launch_th(sf::RenderWindow &window, int &scene);//town hall
    void launch_farm(sf::RenderWindow &window, int &scene);//farm
    void launch_lm(sf::RenderWindow &window, int &scene);//lumber mill
    void launch_sp(sf::RenderWindow &window, int &scene);//stone pit
    void launch_wh(sf::RenderWindow &window, int &scene);//warehouse
    void launch_academy(sf::RenderWindow &window, int &scene);//academy
    void launch_barracks(sf::RenderWindow &window, int &scene);//barracks

    void set_ub_left(int index, float time, float th);

    //for making game
    void set_levels();
    void set_resources();
    void set_path(string path);

private:
    std::array<buildings,8> building;//0-academy 1-barracks 2-church 3-farm 4-lumber 5-stone 6-th 7-wh
    std::array<int,8> levels;//0-academy 1-barracks 2-church 3-farm 4-lumber 5-stone 6-th 7-wh
    std::map<int,string> num_to_names{
            {0,"Academy"},
            {1,"Barracks"},
            {2,"Church"},
            {3,"Farm"},
            {4,"Lumber Mill"},
            {5,"Stone Pit"},
            {6,"Town Hall"},
            {7,"Warehouse"}
    };
    int human, rock, wood;
    ExitWindow exitWindow;
    sf::Event e;
    sf::Cursor cursor;
    sf::Clock resource_clock;
    Button return_to_menu, save;
    Obstacle resource_plank, resource_man, resource_wood, resource_rock;
    Label l_human, l_rock, l_wood;
    std::string save_path, name;
    SaveSystem saveSystem;
    HandleWoSaving wsWindow;

    HandleTownHall th_window; //town hall
    HandleFarm farm_window;//farm
    HandleLumberMill lm_window;//lumber mill
    HandleStonePit sp_window;//stone pit
    HandleWarehouse wh_window;//warehouse
    HandleAcademy academy_window;//academy
    HandleBarracks barracks_window;//barracks
};


#endif //AGES1_HANDLEGAME_H
