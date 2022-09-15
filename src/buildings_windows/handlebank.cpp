//
// Created by tosiek on 15.09.22.
//

#include "../../headers/buildings-windows/handlebank.h"

void HandleBank::handle_events(sf::Event &event, sf::RenderWindow &window, int &scene){
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

void HandleBank::do_stuff(sf::RenderWindow &window){
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

void HandleBank::display(sf::RenderWindow &window){
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

void HandleBank::create(Label *lh, Label *lr, Label *lw, Label *lm, int *hn, int *rk, int *wd, int *moni, int *bld){
//for resource info
    assign_values(lh,lr,lw,lm,hn,rk,wd,bld,moni);

    //change resource _look
    this->resource_look();

    //info
    this->crete_info();
    this->info.setCaption("Bank is place where money are created. You can also\n"
                          "make deals with other villages here. Higher bank's level\n"
                          "gives you more money and better position at marketplace.");
    int bank=*building_;
    this->f_current.create(DEFAULT_FONT,400,300,"Current Money growth: "+
                                                std::to_string(bank*3*60)+"coins/minute",30);
    this->f_current.center();
    this->f_next.create(DEFAULT_FONT,400,350,"Next level money growth: "+
                                             std::to_string((bank+1)*3*60)+"coins/minute",30);
    this->f_next.center();
    this->f_capacity.create(DEFAULT_FONT,400,400,"Current safe capacity: "+
                                                 std::to_string(bank*2048)+" coins",30);
    this->f_capacity.center();
    this->f_next_capacity.create(DEFAULT_FONT,400,450,"Next level safe capacity: "+
                                                      std::to_string((bank+1)*2048)+" coins",30);
    this->f_next_capacity.center();

    //buttons
    this->create_return_button();
}
