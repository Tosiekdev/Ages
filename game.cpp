//
// Created by tosiek on 04.12.2021.
//

#include "needed.h"

//thread to count time
void Application::clocks(){
    while(this->screen.isOpen()){
        this->game_window.clocks(this->scene);
    }
}

void Application::launch_game(){
    this->game_window.main_loop(this->screen, this->scene);
}
