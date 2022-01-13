//
// Created by tosiek on 31.12.2021.
//

#include "needed.h"

using namespace sf;

//set up everything
void Application::create_townhall() {
    this->th_return_to_game.create(40,100,5,5,"Return");

    //buildings label
    int y_position=100;
    for(int i=0; i<7; i++){
        this->l_buildings[i].create(DEFAULT_FONT,20,y_position,this->num_to_names[i+1],40);
        y_position+=100;
    }
}

//main loop
void Application::townhall() {
    //handle event
    this->th_handle_event();

    //do some stuff
    this->th_stuff();

    //draw everything
    this->display_townhall();
}

//event handling
void Application::th_handle_event(){
    while(this->screen.pollEvent(this->e)){
        //closing
        if (this->e.type == Event::Closed) this->screen.close();

        //when you click on screen
        if(Mouse::isButtonPressed(Mouse::Left)){
            //getting mouse position
            int a=Mouse::getPosition(this->screen).x;
            int b=Mouse::getPosition(this->screen).y;

            //button clicked
            if(this->th_return_to_game.onClick(a,b)){
                this->scene=4;
            }
        }
    }
}

//every frame backend
void Application::th_stuff() {
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    //cool animation
    this->th_return_to_game.onFocus(x,y);
}

//drawing everything
void Application::display_townhall() {
    this->screen.clear(Color::White);

    //buttons
    this->th_return_to_game.show(this->screen);

    //labels
    for(int i=0; i<7; i++)
        this->l_buildings[i].show(this->screen);

    this->screen.display();
}
