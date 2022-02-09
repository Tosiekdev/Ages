//
// Created by tosiek on 09.02.2022.
//

#include "needed.h"

void Application::launch_sp(){
    this->sp_window.main_loop(this->e, this->screen, this->scene);
}