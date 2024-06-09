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
#include "map/map.h"

class HandleGame : public HandleWindow{
public:
    /**
     * Create game
     * @param path Path to the file with saved stats.
     */
    void create(std::string path);
    /**
     * Main loop of the game.
     * @param window Game's main window.
     * @param scene Game's scene.
     */
    void main_loop(sf::RenderWindow &window, buildings::Scene &scene) override;
    /**
     * Function to handling events.
     * @param scene Game's scene.
     * @param window Game's main window.
     */
    void handle_event(buildings::Scene &scene, sf::RenderWindow &window) override;
    /**
     * Function to do stuff every frame.
     * @param window Game's main window.
     */
    void do_stuff(sf::RenderWindow &window) override;
    /**
     * Function responsible for drawing everything on the screen.
     * @param window Game's main window.
     */
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
     * Loads textures, set level and position_ of every building.
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
    void clocks(buildings::Scene scene);

    /**
     * Functions responsible for launching corresponding building-windows
     * @param window Window on which everything is displayed
     * @param scene Main window scene if need to be switched
     */
    void launch_th(sf::RenderWindow &window, buildings::Scene &scene){
        thWindow_.main_loop(e_, window, scene);
    }//town hall
    void launch_farm(sf::RenderWindow &window, buildings::Scene &scene){
        farmWindow_.main_loop(e_, window, scene);
    }//farm
    void launch_lm(sf::RenderWindow &window, buildings::Scene &scene){
        lmWindow_.main_loop(e_, window, scene);
    }//lumber mill
    void launch_sp(sf::RenderWindow &window, buildings::Scene &scene){
        spWindow_.main_loop(e_, window, scene);
    }//stone pit
    void launch_wh(sf::RenderWindow &window, buildings::Scene &scene){
        whWindow_.main_loop(e_, window, scene);
    }//warehouse
    void launch_academy(sf::RenderWindow &window, buildings::Scene &scene){
        academyWindow_.main_loop(e_, window, scene);
    }//academy
    void launch_barracks(sf::RenderWindow &window, buildings::Scene &scene){
        barracksWindow_.main_loop(e_, window, scene);
    }//barracks
    void launch_church(sf::RenderWindow &window, buildings::Scene &scene){
        churchWindow_.main_loop(e_, window, scene);
    }//church
    void launch_bank(sf::RenderWindow &window, buildings::Scene &scene){
        bankWindow_.main_loop(e_, window, scene);
    }//bank
    void launch_irmine(sf::RenderWindow &window, buildings::Scene &scene){
        ironMineWindow_.main_loop(e_, window, scene);
    }//iron mine

    /**
     * Function to launch map.
     * @param window Main game's window
     * @param scene Game's scene
     */
    void launch_map(sf::RenderWindow &window, buildings::Scene &scene){
        world_.main_loop(window,scene);
    }

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
     * Sets path to the save_-file.
     * @param path Path to the file with save_.
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
    sf::Cursor cursor_;
    sf::Clock resourceClock_, humanClock_;
    Button returnToMenu_, save_;
    Obstacle resourcePlank_, resourceMan_, resourceWood_, resourceRock_, resourceMoney_, resourceIron_;
    Label lHuman_, lRock_, lWood_, lMoney_, lIron_;
    std::string savePath_, name_;
    SaveSystem saveSystem_;
    HandleWoSaving wsWindow_;

    /**
     * Buildings' windows.
     */
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

    //Map of the world
    Clickable mapIcon_;
    Map world_; //screen with map of the world

    /**
     * Function to check if every building is clicked
     * @param scene Scene of the game
     * @param i x coordinate of mouse in click moment
     * @param j y coordinate of mouse in click moment
     */
    void check_building_clicked(buildings::Scene &scene, int i, int j);
};


#endif //AGES1_HANDLEGAME_H
