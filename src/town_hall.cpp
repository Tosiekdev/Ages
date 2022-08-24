//
// Created by tosiek on 31.12.2021.
//

#include "../headers/needed.h"

using namespace sf;

void Application::launch_th(){
    this->gameWindow_.launch_th(this->screen_, this->scene_);
}
