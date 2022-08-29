//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/handlefarm.h"

void HandleFarm::handle_events(sf::Event &event, sf::RenderWindow &window, int &scene){
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed) window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int i=sf::Mouse::getPosition(window).x;
            int j=sf::Mouse::getPosition(window).y;

            if(this->return_to_game.onClick(i,j)){
                this->return_to_village(scene);
            }
        }
    }
}

void HandleFarm::do_stuff(sf::RenderWindow &window){
    bool a[1];
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a[0]=this->return_to_game.onFocus(x,y);

    if(a[0])
        this->cursor.loadFromSystem(sf::Cursor::Hand);
    else
        this->cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(this->cursor);
}

void HandleFarm::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    this->return_to_game.show(window);

    //resource info
    this->show_resources(window);

    //building_ info
    this->info.show(window);
    this->f_current.show(window);
    this->f_next.show(window);
    this->f_capacity.show(window);
    this->f_next_capacity.show(window);


    window.display();
}

void HandleFarm::create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //for resource info
    this->assign_values(lh,lr,lw,hn,rk,wd,bld);

    //change resource _look
    this->resource_look();

    //info
    this->crete_info();
    this->info.setCaption("Farm reproduces people. Higher level equals more\n"
                          "people per second. Also upgrading farm gives space_ for\n"
                          "more and more human_ beings!");
    int farm=*this->building;
    this->f_current.create(DEFAULT_FONT,400,300,"Current population growth: "+
                            std::to_string(((int)(farm*1.2))*60)+"ppl/minute",30);
    this->f_current.center();
    this->f_next.create(DEFAULT_FONT,400,350,"Next level population growth: "+
                            std::to_string(((int)((farm+1)*1.2))*60)+"ppl/minute",30);
    this->f_next.center();
    this->f_capacity.create(DEFAULT_FONT,400,400,"Current farm capacity: "+
                            std::to_string(farm*156)+" people",30);
    this->f_capacity.center();
    this->f_next_capacity.create(DEFAULT_FONT,400,450,"Next level farm capacity: "+
                            std::to_string((farm+1)*156)+" people",30);
    this->f_next_capacity.center();

    //buttons
    this->create_return_button();
}
