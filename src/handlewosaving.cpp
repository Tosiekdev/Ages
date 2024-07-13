//
// Created by tosiek on 14.02.2022.
//

#include "../headers/handlewosaving.h"

void HandleWoSaving::create(sf::RenderWindow &W, buildings::Scene &scene){
    //creating window
    w_saving.create(sf::VideoMode(300, 200), "Are you sure_?",sf::Style::Titlebar | sf::Style::Close);
    w_saving.setPosition(sf::Vector2i(250 + W.getPosition().x,200 + W.getPosition().y));
    w_saving.setMouseCursorGrabbed(true);

    //creating buttons
    am_sure.create(40,100,167,110,"Yes");
    not_sure.create(40,100,33,110,"No");
    no_save.create(DEFAULT_FONT,2,20,"Are sure_ you want exit?",28);
    ns_pt2.create(DEFAULT_FONT,15,55,"All unsaved progress will be lost.",18);

    main_loop(W,scene);
}

void HandleWoSaving::main_loop(sf::RenderWindow &window, buildings::Scene &scene){
    while(w_saving.isOpen()){
        handle_event(scene, window);
        do_stuff(window);
        display(window);
    }
}

void HandleWoSaving::handle_event(buildings::Scene &scene, sf::RenderWindow &window){
    while (w_saving.pollEvent(e_save)) {
        //Exit
        if (e_save.type == sf::Event::Closed) w_saving.close();

        //Is button clicked?
        if (e_save.type == sf::Event::MouseButtonPressed) {
            //Getting mouse _position
            int x = sf::Mouse::getPosition(w_saving).x;
            int y = sf::Mouse::getPosition(w_saving).y;

            //yes_ button
            if (am_sure.onClick(x, y)) {
                scene = buildings::Scene::MENU;
                w_saving.close();
            }

            //no_ button
            if (not_sure.onClick(x, y)) w_saving.close();
        }
    }
}

void HandleWoSaving::do_stuff(sf::RenderWindow &window){
    //Button animation
    bool a[2];
    a[0]=am_sure.onFocus(sf::Mouse::getPosition(w_saving).x,sf::Mouse::getPosition(w_saving).y);
    a[1]=not_sure.onFocus(sf::Mouse::getPosition(w_saving).x,sf::Mouse::getPosition(w_saving).y);

    //cursor_
    if(a[0] || a[1])
        cursor.loadFromSystem(sf::Cursor::Hand);
    else
        cursor.loadFromSystem(sf::Cursor::Arrow);
    w_saving.setMouseCursor(cursor);
}

void HandleWoSaving::display(sf::RenderWindow &window){
    w_saving.clear(sf::Color::White);
    am_sure.show(w_saving);
    not_sure.show(w_saving);
    no_save.show(w_saving);
    ns_pt2.show(w_saving);

    w_saving.display();
}
