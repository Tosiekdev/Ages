//
// Created by tosiek on 07.02.2022.
//

#include "needed.h"

void Application::launch_farm(){
    this->farm_window.main_loop(this->e, this->screen, this->scene);
}