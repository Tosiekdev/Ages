//
// Created by tosiek on 08.02.2022.
//

#include "needed.h"

void Application::launch_lm(){
    this->lm_window.main_loop(this->e, this->screen, this->scene);
}