//
// Created by tosiek on 14.02.2022.
//

#include "../../headers/HandleWarehouse.h"

void HandleWarehouse::create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //for resource info
    this->assign_values(lh,lr,lw,hn,rk,wd,bld);

    //change resource look
    this->resource_look();

    //info
    this->crete_info();
    this->info.setCaption("In Warehouse you store your goods. Upgrading it gives\n"
                          "you more space!");
    int warehouse=*this->building;
    this->current.create(DEFAULT_FONT,400,300,"",30);
    this->current.setCaption("Current capacity: "+to_string(warehouse*1296));
    this->current.center();
    this->next.create(DEFAULT_FONT,400,350,"",30);
    this->next.setCaption("Next level capacity: "+to_string((warehouse+1)*1296));
    this->next.center();

    //buttons
    this->create_return_button();
}

void HandleWarehouse::handle_events(Event &event, RenderWindow &window, int &scene){
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

void HandleWarehouse::do_stuff(RenderWindow &window){
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

void HandleWarehouse::display(RenderWindow &window){
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
