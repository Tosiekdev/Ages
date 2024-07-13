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

#include "ui/button.h"
#include "ui/label.h"
#include "ui/textbox.h"
#include "ui/tablet.h"
#include "ui/clickable.h"
#include "buildings.h"
#include "ui/obstacle.h"
#include "constants.h"
#include "handlemenu.h"
#include "handlegame.h"

class Application
{
private:
    sf::RenderWindow screen_;
    sf::Vector2i position_;
    sf::Cursor cursor_;
    sf::Event e_{};
    int height_,width_,maxFps_;
    buildings::Scene scene_;

    //village
    std::string name,savePath_;
    int human_{}, rock_{}, wood_{};
    sf::Texture backgroundMenuTexture_;
    sf::Sprite backgroundMenuSprite_;

    ExitWindow exitWindow_;//wExit_
    HandleMenu menu_;//menu_

    //create
    Button returnButton_,okButton_,cancelButton_;
    sf::Texture plank_,obstacleT_;
    sf::Sprite space_,obstacleS_;
    Label label1_,label2_;
    textbox t1_;

    //load
    Button returningButton_,loadButton_,removeButton_;
    tablet t_[5];
    Clickable down_,up_;
    Label errorMessage_;
    int downLevel_=0, focusedTablet_{};

    //game
    HandleGame gameWindow_;

public:
    Application();
    void main_window();

    //data interference
    std::string create_city(const std::string& calling);

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

    void launch_th(){
        gameWindow_.launch_th(screen_,scene_);
    }
    void launch_farm(){
        gameWindow_.launch_farm(screen_,scene_);
    }
    void launch_lm(){
        gameWindow_.launch_lm(screen_,scene_);
    }
    void launch_sp(){
        gameWindow_.launch_sp(screen_,scene_);
    }
    void launch_wh(){
        gameWindow_.launch_wh(screen_,scene_);
    }
    void launch_academy(){
        gameWindow_.launch_academy(screen_,scene_);
    }
    void launch_barracks(){
        gameWindow_.launch_barracks(screen_,scene_);
    }
    void launch_church(){
        gameWindow_.launch_church(screen_,scene_);
    }
    void launch_bank(){
        gameWindow_.launch_bank(screen_,scene_);
    }
    void launch_irmine(){
        gameWindow_.launch_irmine(screen_,scene_);
    }

    void launch_map(){
        gameWindow_.launch_map(screen_,scene_);
    }

    //thread functions
    void clocks();
};


#endif //AGES1_NEEDED_H
