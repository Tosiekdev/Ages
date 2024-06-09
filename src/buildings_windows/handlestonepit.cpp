//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/buildings-windows/handlestonepit.h"

void HandleStonePit::handle_events(sf::Event &event,sf::RenderWindow &window, buildings::Scene &scene){
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed) window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int i=sf::Mouse::getPosition(window).x;
            int j=sf::Mouse::getPosition(window).y;

            if(this->returnToGame_.onClick(i, j)){
                this->return_to_village(scene);
            }
        }
    }
}

void HandleStonePit::do_stuff(sf::RenderWindow &window){
    bool a[1];
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a[0]=this->returnToGame_.onFocus(x, y);

    //changing cursor_
    if(a[0])
        this->cursor_.loadFromSystem(sf::Cursor::Hand);
    else
        this->cursor_.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(this->cursor_);
}

void HandleStonePit::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    this->returnToGame_.show(window);

    //resource info_
    this->show_resources(window);

    //building_ info_
    this->info_.show(window);
    this->next.show(window);
    this->current.show(window);

    window.display();
}

void
HandleStonePit::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                       int *iron,
                       int *bld) {
    //for resource info_
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    this->resource_look();

    //info_
    this->crete_info();
    this->info_.setCaption("Stone Pit simply mine stone for upgrading buildings.\n"
                          "Higher level means, obviously, more stone!");
    int stone=*this->building_;
    this->current.create(DEFAULT_FONT,400,300,"",30);
    this->current.setCaption("Current stone growth: "+std::to_string(stone*60)+" rocks/minute");
    this->current.center();
    this->next.create(DEFAULT_FONT,400,350,"",30);
    this->next.setCaption("Next level_ stone growth: "+std::to_string((stone+1)*60)+" rocks/minute");
    this->next.center();

    //buttons
    this->create_return_button();
}
