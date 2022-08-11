//
// Created by tosiek on 16.02.2022.
//

#include "../../headers/HandleBarracks.h"

void HandleBarracks::create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //for resource info
    assign_values(lh,lr,lw,hn,rk,wd,bld);

    //change resource _look
    resource_look();

    //info
    crete_info();
    info.setCaption("In Barracks you train your soldiers to make your army\n"
                          "bigger and stronger!\n"
                          "Upgrading Barracks allows you to train better units!");

    //for training units
    swordsMen.set_position(sf::Vector2f(5,250));

    //buttons
    this->create_return_button();

    //slide buttons
    slide_left.create_element("Textures/l_slide.png",sf::Vector2f(5,275));
}

void HandleBarracks::handle_events(sf::Event &event, sf::RenderWindow &window, int &scene){
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed) window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int i=sf::Mouse::getPosition(window).x;
            int j=sf::Mouse::getPosition(window).y;

            if(return_to_game.onClick(i,j)){
                return_to_village(scene);
            }
        }
    }
}

void HandleBarracks::do_stuff(sf::RenderWindow &window){
    bool a[1];
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a[0]=return_to_game.onFocus(x,y);

    //changing cursor
    if(a[0])
        cursor.loadFromSystem(sf::Cursor::Hand);
    else
        cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor);
}

void HandleBarracks::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    return_to_game.show(window);

    //resource info
    show_resources(window);

    //units training
    swordsMen.display_image(window);

    //building info
    info.show(window);

    //sliders
    slide_left.draw_it(window);

    window.display();
}
