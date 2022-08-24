//
// Created by tosiek on 04.12.2021.
//

#include "../headers/needed.h"

//thread to count time
void Application::clocks(){
    while(this->screen_.isOpen()){
        this->gameWindow_.clocks(this->scene_);
    }
}

void Application::launch_game(){
    this->gameWindow_.main_loop(this->screen_, this->scene_);
}
