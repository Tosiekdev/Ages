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
#include "buildings-windows/handleironmine.h"

class HandleGame : public HandleWindow{
public:
    void create(std::string path);
    void main_loop(sf::RenderWindow &window, int &scene) override;
    void handle_event(int &scene, sf::RenderWindow &window) override;
    void do_stuff(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;

    /**
     * Makes all buildings not clickable.
     */
    void deactivate_buildings();
    /**
     * Makes all buildings clickable.
     */
    void activate_buildings();
    /**
     * Loads textures, set level and position of every building.
     */
    void prepare_buildings();
    /**
     * Loads saved file and calls prepare_buildings.
     */
    void create_buildings();
    /**
     * Saves current progress of game.
     */
    void save_game();
    /**
     * Assigns level of every building to main game array with levels.
     */
    void assign_levels();
    /**
     * Function to maintain everything that changes in every second.
     * @param scene Current game's scene.
     */
    void clocks(int scene);

    /**
     * Functions responsible for launching corresponding building-windows
     * @param window Window on which everything is displayed
     * @param scene Main window scene if need to be switched
     */
    void launch_th(sf::RenderWindow &window, int &scene);//town hall
    void launch_farm(sf::RenderWindow &window, int &scene);//farm
    void launch_lm(sf::RenderWindow &window, int &scene);//lumber mill
    void launch_sp(sf::RenderWindow &window, int &scene);//stone pit
    void launch_wh(sf::RenderWindow &window, int &scene);//warehouse
    void launch_academy(sf::RenderWindow &window, int &scene);//academy
    void launch_barracks(sf::RenderWindow &window, int &scene);//barracks
    void launch_church(sf::RenderWindow &window, int &scene);//church
    void launch_bank(sf::RenderWindow &window, int &scene);//bank
    void launch_irmine(sf::RenderWindow &window, int &scene);//iron mine

    /**
     * Sets time left for upgrading building in town hall.
     * @param index Index of building.
     * @param time Time left.
     * @param th Town Hall level to proper drawing of progress bar.
     */
    void set_ub_left(int index, float time, float th);

    //for making game
    /**
     * Sets starting levels of all buildings.
     */
    void set_levels();
    /**
     * Sets starting resources' count.
     */
    void set_resources();
    /**
     * Sets path to the save-file.
     * @param path Path to the file with save.
     */
    void set_path(std::string path);

private:
    std::array<buildings,10> building_;//0-academy 1-barracks 2-church 3-farm 4-lumber 5-stone 6-th 7-wh 8-bank 9-iron mine
    std::array<int, 10> levels_;//0-academy 1-barracks 2-church 3-farm 4-lumber 5-stone 6-th 7-wh 8-bank 9-iron mine
    std::array<std::string,10> numToNames_{
            "Academy",
            "Barracks",
            "Church",
            "Farm",
            "Lumber Mill",
            "Stone Pit",
            "Town Hall",
            "Warehouse",
            "Bank",
            "Iron Mine"
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
    SaveSystem saveSystem_;
    HandleWoSaving wsWindow_;

    HandleTownHall thWindow_; //town hall
    HandleFarm farmWindow_;//farm
    HandleLumberMill lmWindow_;//lumber mill
    HandleStonePit spWindow_;//stone pit
    HandleWarehouse whWindow_;//warehouse
    HandleAcademy academyWindow_;//academy
    HandleBarracks barracksWindow_;//barracks
    HandleChurch churchWindow_;//church
    HandleBank bankWindow_;//bank
    HandleIronMine ironMineWindow_;//iron mine

    /**
     * Function to check if every building is clicked
     * @param scene Scene of the game
     * @param i x coordinate of mouse in click moment
     * @param j y coordinate of mouse in click moment
     */
    void check_building_clicked(int &scene, int i, int j);
};


#endif //AGES1_HANDLEGAME_H
