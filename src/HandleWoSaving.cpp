//
// Created by tosiek on 14.02.2022.
//

#include "../headers/HandleWoSaving.h"

void HandleWoSaving::create(sf::RenderWindow &W, int &scene){
    //creating window
    this->w_saving.create(sf::VideoMode(300, 200), "Are you sure?",sf::Style::Titlebar | sf::Style::Close);
    this->w_saving.setPosition(sf::Vector2i(250 + W.getPosition().x,200 + W.getPosition().y));
    this->w_saving.setMouseCursorGrabbed(true);

    //creating buttons
    this->am_sure.create(40,100,167,110,"Yes");
    this->not_sure.create(40,100,33,110,"No");
    this->no_save.create(DEFAULT_FONT,2,20,"Are sure you want exit?",28);
    this->ns_pt2.create(DEFAULT_FONT,15,55,"All unsaved progress will be lost.",18);

    this->main_loop(W,scene);
}

void HandleWoSaving::main_loop(sf::RenderWindow &window, int &scene){
    while(this->w_saving.isOpen()){
        this->handle_event(scene, window);
        this->do_stuff(window);
        this->display(window);
    }
}

void HandleWoSaving::handle_event(int &scene, sf::RenderWindow &window){
    while (this->w_saving.pollEvent(this->e_save)) {
        //Exit
        if (this->e_save.type == sf::Event::Closed) this->w_saving.close();

        //Is button clicked?
        if (this->e_save.type == sf::Event::MouseButtonPressed) {
            //Getting mouse position
            int x = sf::Mouse::getPosition(this->w_saving).x;
            int y = sf::Mouse::getPosition(this->w_saving).y;

            //yes button
            if (this->am_sure.onClick(x, y)) {
                scene = 1;
                this->w_saving.close();
            }

            //no button
            if (this->not_sure.onClick(x, y)) this->w_saving.close();
        }
    }
}

void HandleWoSaving::do_stuff(sf::RenderWindow &window){
    //Button animation
    bool a[2];
    a[0]=this->am_sure.onFocus(sf::Mouse::getPosition(this->w_saving).x,sf::Mouse::getPosition(this->w_saving).y);
    a[1]=this->not_sure.onFocus(sf::Mouse::getPosition(this->w_saving).x,sf::Mouse::getPosition(this->w_saving).y);

    //cursor
    if(a[0] || a[1])
        this->cursor.loadFromSystem(sf::Cursor::Hand);
    else
        this->cursor.loadFromSystem(sf::Cursor::Arrow);
    this->w_saving.setMouseCursor(this->cursor);
}

void HandleWoSaving::display(sf::RenderWindow &window){
    this->w_saving.clear(sf::Color::White);
    this->am_sure.show(this->w_saving);
    this->not_sure.show(this->w_saving);
    this->no_save.show(this->w_saving);
    this->ns_pt2.show(this->w_saving);

    this->w_saving.display();
}
