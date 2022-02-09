//
// Created by tosiek on 09.02.2022.
//

#include "HandleTownHall.h"

void HandleTownHall::create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //for resource info
    this->assign_values(lh,lr,lw,hn,rk,wd,bld);

    //change resource look
    this->resource_look();

    //info
    this->crete_info();
    this->info.setCaption("In Town Hall you can upgrade your buildings.\n"
                          "Upgrading Town Hall make upgrade's times shorter!");

    //buttons
    this->create_return_button();
}

void HandleTownHall::handle_events(Event &event, RenderWindow &window, int &scene){
    while(window.pollEvent(event)){
        if(event.type==Event::Closed) window.close();

        if(Mouse::isButtonPressed(Mouse::Left)){
            int i=Mouse::getPosition(window).x;
            int j=Mouse::getPosition(window).y;

            if(this->return_to_game.onClick(i,j)){
                this->return_to_village(scene);
            }
        }
    }
}

void HandleTownHall::do_stuff(RenderWindow &window){
    bool a[1];
    int x=Mouse::getPosition(window).x;
    int y=Mouse::getPosition(window).y;

    //cool animation
    a[0]=this->return_to_game.onFocus(x,y);

    if(a[0])
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    window.setMouseCursor(this->cursor);
}

void HandleTownHall::display(RenderWindow &window){
    window.clear(Color::White);

    //buttons
    this->return_to_game.show(window);

    //resource info
    this->show_resources(window);

    //building info
    this->info.show(window);

    window.display();
}

void HandleTownHall::crete_ub(buildings *resp, sf::Vector2f pos, int index){
    this->u_buildings[index].create_upgrade(resp,this->num_to_names[index+1],pos);
}

void HandleTownHall::set_ub_left(int index, float time, float th){
    this->u_buildings[index].set_left(time,th);
}

float HandleTownHall::get_ub_left(int index){
    return this->u_buildings[index].get_left();
}
