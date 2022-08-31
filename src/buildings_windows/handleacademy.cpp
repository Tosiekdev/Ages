//
// Created by tosiek on 16.02.2022.
//

#include "../../headers/buildings-windows/handleacademy.h"

void HandleAcademy::create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //for resource info
    this->assign_values(lh,lr,lw,hn,rk,wd,bld);

    //change resource _look
    this->resource_look();

    //info
    this->crete_info();
    this->info.setCaption("In Academy you discover new technologies which can\n"
                          "improve yours army strength, or increase your resource\n"
                          "production. Upgrading Academy helps you to discover\n"
                          "more technologies!");

    //buttons
    this->create_return_button();
}

void HandleAcademy::handle_events(sf::Event &event, sf::RenderWindow &window, int &scene){
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

void HandleAcademy::do_stuff(sf::RenderWindow &window){
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

void HandleAcademy::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    this->return_to_game.show(window);

    //resource info
    this->show_resources(window);

    //info
    this->info.show(window);

    window.display();
}
