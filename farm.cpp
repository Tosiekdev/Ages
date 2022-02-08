//
// Created by tosiek on 07.02.2022.
//

#include "needed.h"

//Prepare everything
void Application::create_farm(){
    this->f_return_to_game.create(40,100,5,5,"Return");

    //changing resource info look
    this->resources_1();

    //info
    this->f_info.create(DEFAULT_FONT,5,100,"",30);
    this->f_info.setCaption("Farm reproduces people. Higher level equals more\n"
                            "people per second. Also upgrading farm gives space for\n"
                            "more and more human beings!");
    this->f_current.create(DEFAULT_FONT,400,300,"Current population growth: "+to_string(((int)(this->farm*1.2))*60)+"ppl/minute",30);
    this->f_current.center();
    this->f_next.create(DEFAULT_FONT,400,350,"Next level population growth: "+to_string(((int)((this->farm+1)*1.2))*60)+"ppl/minute",30);
    this->f_next.center();
    this->f_capacity.create(DEFAULT_FONT,400,400,"Current farm capacity: "+to_string(this->farm*83)+" people",30);
    this->f_capacity.center();
    this->f_next_capacity.create(DEFAULT_FONT,400,450,"Next level farm capacity: "+to_string((this->farm+1)*83)+" people",30);
    this->f_next_capacity.center();
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
            if(this->f_return_to_game.onClick(i,j)) this->return_to_village();
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

    //info
    this->f_info.show(this->screen);
    this->f_current.show(this->screen);
    this->f_next.show(this->screen);
    this->f_capacity.show(this->screen);
    this->f_next_capacity.show(this->screen);

    //resource numbers
    this->l_human.show(this->screen);
    this->l_rock.show(this->screen);
    this->l_wood.show(this->screen);

    this->screen.display();
}