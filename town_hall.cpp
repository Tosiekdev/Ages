//
// Created by tosiek on 31.12.2021.
//

#include "needed.h"

using namespace sf;

void Application::launch_th(){
    this->th_window.main_loop(this->e,this->screen,this->scene);
}
