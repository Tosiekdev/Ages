//
// Created by tosiek on 16.02.2022.
//

#include "../../headers/buildings-windows/handleacademy.h"

void HandleAcademy::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                           int *iron,
                           int *bld) {
    //for resource info_
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    resource_look();

    //info_
    crete_info();
    info_.setCaption("In Academy you discover new technologies which can\n"
                          "improve yours army strength, or increase your resource\n"
                          "production. Upgrading Academy helps you to discover\n"
                          "more technologies!");

    //buttons
    create_return_button();
}

void HandleAcademy::handle_events(sf::Event &event, sf::RenderWindow &window, buildings::Scene &scene){
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            int i = sf::Mouse::getPosition(window).x;
            int j = sf::Mouse::getPosition(window).y;

            if(returnToGame_.onClick(i, j)){
                return_to_village(scene);
            }
        }
    }
}

void HandleAcademy::do_stuff(sf::RenderWindow &window){
    std::vector<bool> a;
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a.push_back(returnToGame_.onFocus(x, y));

    sf::Vector2i mouse_pos=sf::Mouse::getPosition(window);

    if(std::any_of(a.begin(),a.end(),[](bool i){return i;}))
        cursor_.loadFromSystem(sf::Cursor::Hand);
    else
        cursor_.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor_);
}

void HandleAcademy::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    returnToGame_.show(window);

    //resource info_
    show_resources(window);

    //info_
    info_.show(window);

    window.display();
}
