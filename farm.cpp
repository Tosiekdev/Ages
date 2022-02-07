//
// Created by tosiek on 07.02.2022.
//

#include "needed.h"

//Prepare everything
void Application::create_farm(){
    this->f_return_to_game.create(40,100,5,5,"Return");
}

//main loop
void Application::m_farm(){
    //handle event
    this->f_handle_event();

    //do stuff
    this->f_stuff();

    //display everything
    this->display_farm();
}

//handling events
void Application::f_handle_event(){
    while(this->screen.pollEvent(this->e)){
        //Closing events
        if (this->e.type == Event::Closed) this->screen.close();
        if ((Keyboard::isKeyPressed(Keyboard::Escape))) this->u_sure(this->screen);

        //button clicked
        if(Mouse::isButtonPressed(Mouse::Left)){
            //getting mouse position
            int i=Mouse::getPosition(this->screen).x;
            int j=Mouse::getPosition(this->screen).y;

            //buttons
            if(this->f_return_to_game.onClick(i,j)) this->scene=4;
        }
    }
}

//every frame stuff
void Application::f_stuff(){
    bool for_cursor[1];
    //cool animation
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    for_cursor[0]=this->f_return_to_game.onFocus(x,y);

    //cursor
    if(for_cursor[0]){
        this->cursor.loadFromSystem(Cursor::Hand);
    }
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    this->screen.setMouseCursor(this->cursor);
}

//display everything
void Application::display_farm(){
    this->screen.clear(Color::White);

    //buttons
    this->f_return_to_game.show(this->screen);

    this->screen.display();
}