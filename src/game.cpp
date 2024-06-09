//
// Created by tosiek on 04.12.2021.
//

#include "../headers/needed.h"

//thread to count time
void Application::clocks(){
    while(screen_.isOpen()){
        gameWindow_.clocks(scene_);
    }
}

void Application::launch_game(){
    this->gameWindow_.main_loop(screen_, scene_);
}
