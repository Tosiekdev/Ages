//
// Created by tosiek on 09.02.2022.
//

#include "../headers/ExitWindow.h"

void ExitWindow::create(sf::RenderWindow &W, int &scene){
    //creating window
    this->w_exit.create(sf::VideoMode(300,200),"Are you sure?",sf::Style::Titlebar | sf::Style::Close);
    this->w_exit.setPosition(sf::Vector2i(250+W.getPosition().x,200+W.getPosition().y));
    this->w_exit.setMouseCursorGrabbed(true);

    //creating buttons
    this->yes.create(40,100,167,110,"Yes");
    this->no.create(40,100,33,110,"No");
    this->sure.create(DEFAULT_FONT,2,20,"Are sure you want exit?",28);

    this->main_loop(W,scene);
}

void ExitWindow::main_loop(sf::RenderWindow &window, int &scene){
    while(this->w_exit.isOpen()) {
        this->handle_event(scene,window);
        this->do_stuff(window);
        this->display(window);
    }
}

void ExitWindow::handle_event(int &scene, sf::RenderWindow &window){
    while(this->w_exit.pollEvent(this->exit_e)){
        //Exit
        if(this->exit_e.type==sf::Event::Closed) this->w_exit.close();

        //Is button clicked?
        if(this->exit_e.type==sf::Event::MouseButtonPressed){
            //Getting mouse _position
            int x=sf::Mouse::getPosition(this->w_exit).x;
            int y=sf::Mouse::getPosition(this->w_exit).y;

            //yes button
            if(this->yes.onClick(x,y)){
                window.close();
                this->w_exit.close();
            }

            //no button
            if(this->no.onClick(x,y)) this->w_exit.close();
        }
    }
}

void ExitWindow::do_stuff(sf::RenderWindow &window){
    //Button animation
    bool a[2];
    a[0]=this->yes.onFocus(sf::Mouse::getPosition(this->w_exit).x,sf::Mouse::getPosition(this->w_exit).y);
    a[1]=this->no.onFocus(sf::Mouse::getPosition(this->w_exit).x,sf::Mouse::getPosition(this->w_exit).y);

    //cursor_
    if(a[0] || a[1])
        this->cursor.loadFromSystem(sf::Cursor::Hand);
    else
        this->cursor.loadFromSystem(sf::Cursor::Arrow);
    this->w_exit.setMouseCursor(this->cursor);
}

void ExitWindow::display(sf::RenderWindow &window){
    //Drawing everything
    this->w_exit.clear(sf::Color::White);
    this->yes.show(this->w_exit);
    this->no.show(this->w_exit);
    this->sure.show(this->w_exit);
    this->w_exit.display();
}
