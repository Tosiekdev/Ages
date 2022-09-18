//
// Created by tosiek on 14.02.2022.
//

#include "../../headers/buildings-windows/handlewarehouse.h"

void
HandleWarehouse::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                        int *iron,
                        int *bld) {
    //for resource info_
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    this->resource_look();

    //info_
    this->crete_info();
    this->info_.setCaption("In Warehouse you store your goods. Upgrading it gives\n"
                          "you more space_!");
    int warehouse=*this->building_;
    this->current.create(DEFAULT_FONT,400,300,"",30);
    this->current.setCaption("Current capacity: "+std::to_string(warehouse*1296));
    this->current.center();
    this->next.create(DEFAULT_FONT,400,350,"",30);
    this->next.setCaption("Next level_ capacity: "+std::to_string((warehouse+1)*1296));
    this->next.center();

    //buttons
    this->create_return_button();
}

void HandleWarehouse::handle_events(sf::Event &event, sf::RenderWindow &window, int &scene){
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

void HandleWarehouse::do_stuff(sf::RenderWindow &window){
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

void HandleWarehouse::display(sf::RenderWindow &window){
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
