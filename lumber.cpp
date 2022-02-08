//
// Created by tosiek on 08.02.2022.
//

#include "needed.h"

//a'la constructor
void Application::create_lumber(){
    this->lm_return_to_game.create(40,100,5,5,"Return");

    //info
    this->lm_info.create(DEFAULT_FONT,5,100,"",30);
    this->lm_info.setCaption("Lumber Mill takes care about your wood supply.\n"
                             "Those are needed to upgrade buildings.\n"
                             "Higher level means more wood!");
    this->lm_current.create(DEFAULT_FONT,400,300,"",30);
    this->lm_current.setCaption("Current wood growth: "+to_string(this->lumber_mill*600)+" wood/minute");
    this->lm_current.center();
    this->lm_next.create(DEFAULT_FONT,400,350,"",30);
    this->lm_next.setCaption("Current wood growth: "+to_string((this->lumber_mill+1)*600)+" wood/minute");
    this->lm_next.center();

    //changing resource info look
    this->resources_1();
}

//main thread
void Application::lumber(){
    //handle event
    this->lm_handle_event();

    //do some stuff
    this->lm_stuff();

    //drawing everything
    this->display_lumber();
}

//handling event
void Application::lm_handle_event(){
    while(this->screen.pollEvent(this->e)){
        //Closing events
        if(this->e.type == Event::Closed) this->screen.close();
        if((Keyboard::isKeyPressed(Keyboard::Escape))) this->u_sure(this->screen);

        //button clicked
        if(Mouse::isButtonPressed(Mouse::Left)) {
            //getting mouse position
            int i = Mouse::getPosition(this->screen).x;
            int j = Mouse::getPosition(this->screen).y;

            if(this->lm_return_to_game.onClick(i,j)) this->return_to_village();
        }
    }
}

//every frame backend
void Application::lm_stuff(){
    bool a[1];
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    //cool animation
    a[0]=this->lm_return_to_game.onFocus(x,y);

    //cursor
    if(a[0]){
        this->cursor.loadFromSystem(Cursor::Hand);
    }
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    this->screen.setMouseCursor(this->cursor);
}

//simply displaying
void Application::display_lumber(){
    this->screen.clear(Color::White);

    //buttons
    this->lm_return_to_game.show(this->screen);

    //info
    this->lm_info.show(this->screen);
    this->lm_current.show(this->screen);
    this->lm_next.show(this->screen);

    //resource numbers
    this->l_human.show(this->screen);
    this->l_rock.show(this->screen);
    this->l_wood.show(this->screen);

    this->screen.display();
}
