//
// Created by tosiek on 14.02.2022.
//

#include "HandleWoSaving.h"

void HandleWoSaving::create(sf::RenderWindow &W, int &scene){
    //creating window
    this->wsaving.create(VideoMode(300,200),"Are you sure?",Style::Titlebar | Style::Close);
    this->wsaving.setPosition(Vector2i(250+W.getPosition().x,200+W.getPosition().y));
    this->wsaving.setMouseCursorGrabbed(true);

    //creating buttons
    this->am_sure.create(40,100,167,110,"Yes");
    this->not_sure.create(40,100,33,110,"No");
    this->no_save.create(DEFAULT_FONT,2,20,"Are sure you want exit?",28);
    this->ns_pt2.create(DEFAULT_FONT,15,55,"All unsaved progress will be lost.",18);

    this->main_loop(W,scene);
}

void HandleWoSaving::main_loop(sf::RenderWindow &window, int &scene){
    while(this->wsaving.isOpen()){
        this->handle_event(scene, window);
        this->do_stuff(window);
        this->display(window);
    }
}

void HandleWoSaving::handle_event(int &scene, sf::RenderWindow &window){
    while (this->wsaving.pollEvent(this->e_save)) {
        //Exit
        if (this->e_save.type == Event::Closed) this->wsaving.close();

        //Is button clicked?
        if (this->e_save.type == Event::MouseButtonPressed) {
            //Getting mouse position
            int x = Mouse::getPosition(this->wsaving).x;
            int y = Mouse::getPosition(this->wsaving).y;

            //yes button
            if (this->am_sure.onClick(x, y)) {
                scene = 1;
                this->wsaving.close();
            }

            //no button
            if (this->not_sure.onClick(x, y)) this->wsaving.close();
        }
    }
}

void HandleWoSaving::do_stuff(sf::RenderWindow &window){
    //Button animation
    bool a[2];
    a[0]=this->am_sure.onFocus(Mouse::getPosition(this->wsaving).x,Mouse::getPosition(this->wsaving).y);
    a[1]=this->not_sure.onFocus(Mouse::getPosition(this->wsaving).x,Mouse::getPosition(this->wsaving).y);

    //cursor
    if(a[0] || a[1])
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    this->wsaving.setMouseCursor(this->cursor);
}

void HandleWoSaving::display(sf::RenderWindow &window){
    this->wsaving.clear(Color::White);
    this->am_sure.show(this->wsaving);
    this->not_sure.show(this->wsaving);
    this->no_save.show(this->wsaving);
    this->ns_pt2.show(this->wsaving);

    this->wsaving.display();
}
