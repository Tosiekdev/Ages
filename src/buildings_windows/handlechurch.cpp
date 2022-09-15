//
// Created by tosiek on 17.02.2022.
//

#include "../../headers/buildings-windows/handlechurch.h"

void HandleChurch::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                          int *iron,
                          int *bld) {
    //for resource info
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    this->resource_look();

    //info
    this->crete_info();
    this->info.setCaption("In Church you can obtain God's grace which can help you\n"
                          "in war, increase resource production and many more.\n"
                          "Higher level_ means more grace!");

    //buttons
    this->create_return_button();
}

void HandleChurch::handle_events(sf::Event &event, sf::RenderWindow &window, int &scene){
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            int i = sf::Mouse::getPosition(window).x;
            int j = sf::Mouse::getPosition(window).y;

            if(this->return_to_game.onClick(i,j)){
                this->return_to_village(scene);
            }
        }
    }
}

void HandleChurch::do_stuff(sf::RenderWindow &window){
    std::vector<bool> a;
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a.push_back(this->return_to_game.onFocus(x,y));

    sf::Vector2i mouse_pos=sf::Mouse::getPosition(window);

    if(std::any_of(a.begin(),a.end(),[](bool i){return i;}))
        this->cursor.loadFromSystem(sf::Cursor::Hand);
    else
        this->cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(this->cursor);
}

void HandleChurch::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    this->return_to_game.show(window);

    //resource info
    this->show_resources(window);

    //info
    this->info.show(window);

    window.display();
}
