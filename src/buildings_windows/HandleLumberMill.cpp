//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/HandleLumberMill.h"

void HandleLumberMill::create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //for resource info
    this->assign_values(lh,lr,lw,hn,rk,wd,bld);

    //change resource look
    this->resource_look();

    //info
    this->crete_info();
    this->info.setCaption("Lumber Mill takes care about your wood supply.\n"
                          "Those are needed to upgrade buildings.\n"
                          "Higher level means more wood!");
    int lumber=*this->building;
    this->current.create(DEFAULT_FONT,400,300,"",30);
    this->current.setCaption("Current wood growth: "+to_string(lumber*60)+" rocks/minute");
    this->current.center();
    this->next.create(DEFAULT_FONT,400,350,"",30);
    this->next.setCaption("Next level wood growth: "+to_string((lumber+1)*60)+" rocks/minute");
    this->next.center();

    //buttons
    this->create_return_button();
}

void HandleLumberMill::handle_events(Event &event, RenderWindow &window, int &scene){
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

void HandleLumberMill::do_stuff(RenderWindow &window){
    bool a[1];
    int x=Mouse::getPosition(window).x;
    int y=Mouse::getPosition(window).y;

    //cool animation
    a[0]=this->return_to_game.onFocus(x,y);

    //changing cursor
    if(a[0])
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    window.setMouseCursor(this->cursor);
}

void HandleLumberMill::display(RenderWindow &window){
    window.clear(Color::White);

    //buttons
    this->return_to_game.show(window);

    //resource info
    this->show_resources(window);

    //building info
    this->info.show(window);
    this->next.show(window);
    this->current.show(window);

    window.display();
}
