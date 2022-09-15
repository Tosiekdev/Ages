//
// Created by tosiek on 16.02.2022.
//

#ifndef AGES1_HANDLEGAME_H
#define AGES1_HANDLEGAME_H

#include <array>
#include <map>
#include <algorithm>
#include <vector>

#include "handlewindow.h"
#include "ui/button.h"
#include "ui/label.h"
#include "exitwindow.h"
#include "handlewosaving.h"
#include "ui/obstacle.h"
#include "buildings.h"
#include "savesystem.h"
#include "buildings-windows/handlestonepit.h"
#include "buildings-windows/handlefarm.h"
#include "buildings-windows/handlelumbermill.h"
#include "buildings-windows/handletownhall.h"
#include "buildings-windows/handlewarehouse.h"
#include "handlewosaving.h"
#include "buildings-windows/handleacademy.h"
#include "buildings-windows/handlebarracks.h"
#include "buildings-windows/handlechurch.h"
#include "buildings-windows/handlebank.h"

class HandleGame : public HandleWindow{
public:
    void create(std::string path);
    void main_loop(sf::RenderWindow &window, int &scene) override;
    void handle_event(int &scene, sf::RenderWindow &window) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;

    void deactivate_buildings();
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
    void launch_church(sf::RenderWindow &window, int &scene);//church
    void launch_bank(sf::RenderWindow &window, int &scene);//bank

    void set_ub_left(int index, float time, float th);

    //for making game
    void set_levels();
    void set_resources();
    void set_path(std::string path);

private:
    std::array<buildings,10> building_;//0-academy 1-barracks 2-church 3-farm 4-lumber 5-stone 6-th 7-wh 8-bank 9-iron mine
    std::array<int, 10> levels_;//0-academy 1-barracks 2-church 3-farm 4-lumber 5-stone 6-th 7-wh 8-bank 9-iron mine
    std::map<int,std::string> numToNames{
            {0,"Academy"},
            {1,"Barracks"},
            {2,"Church"},
            {3,"Farm"},
            {4,"Lumber Mill"},
            {5,"Stone Pit"},
            {6,"Town Hall"},
            {7,"Warehouse"},
            {8,"Bank"},
            {9,"Iron Mine"}
    };
    int human_, rock_, wood_, money_, iron_;
    ExitWindow exitWindow;
    sf::Event e_;
    sf::Cursor cursor;
    sf::Clock resourceClock_, humanClock_;
    Button returnToMenu_, save;
    Obstacle resourcePlank_, resourceMan_, resourceWood_, resourceRock_, resourceMoney_, resourceIron_;
    Label lHuman_, lRock_, lWood_, lMoney_, lIron_;
    std::string savePath_, name_;
    SaveSystem saveSystem;
    HandleWoSaving wsWindow;

    HandleTownHall thWindow_; //town hall
    HandleFarm farmWindow_;//farm
    HandleLumberMill lmWindow_;//lumber mill
    HandleStonePit spWindow_;//stone pit
    HandleWarehouse whWindow_;//warehouse
    HandleAcademy academyWindow_;//academy
    HandleBarracks barracksWindow_;//barracks
    HandleChurch churchWindow_;//church
    HandleBank bankWindow_;//bank
};


#endif //AGES1_HANDLEGAME_H
