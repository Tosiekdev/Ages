//
// Created by tosiek on 09.02.2022.
//

#include "../headers/exitwindow.h"

void ExitWindow::create(sf::RenderWindow &W, int &scene){
    //creating window
    wExit_.create(sf::VideoMode(300, 200), "Are you sure_?", sf::Style::Titlebar | sf::Style::Close);
    wExit_.setPosition(sf::Vector2i(250 + W.getPosition().x, 200 + W.getPosition().y));
    wExit_.setMouseCursorGrabbed(true);

    //creating buttons
    yes_.create(40, 100, 167, 110, "Yes");
    no_.create(40, 100, 33, 110, "No");
    sure_.create(DEFAULT_FONT, 2, 20, "Are sure_ you want exit?", 28);

    main_loop(W,scene);
}

void ExitWindow::main_loop(sf::RenderWindow &window, int &scene){
    while(wExit_.isOpen()) {
        handle_event(scene,window);
        do_stuff(window);
        display(window);
    }
}

void ExitWindow::handle_event(int &scene, sf::RenderWindow &window){
    while(wExit_.pollEvent(exitE_)){
        //Exit
        if(exitE_.type == sf::Event::Closed) wExit_.close();

        //Is button clicked?
        if(exitE_.type == sf::Event::MouseButtonPressed){
            //Getting mouse _position
            int x=sf::Mouse::getPosition(wExit_).x;
            int y=sf::Mouse::getPosition(wExit_).y;

            //yes_ button
            if(yes_.onClick(x, y)){
                window.close();
                wExit_.close();
            }

            //no_ button
            if(no_.onClick(x, y)) wExit_.close();
        }
    }
}

void ExitWindow::do_stuff(sf::RenderWindow &window){
    //Button animation
    bool a[2];
    int posX=sf::Mouse::getPosition(wExit_).x;
    int posY=sf::Mouse::getPosition(wExit_).y;
    a[0]=yes_.onFocus(posX,posY);
    a[1]=no_.onFocus(posX,posY);

    //cursor_
    if(a[0] || a[1])
        cursor_.loadFromSystem(sf::Cursor::Hand);
    else
        cursor_.loadFromSystem(sf::Cursor::Arrow);
    wExit_.setMouseCursor(cursor_);
}

void ExitWindow::display(sf::RenderWindow &window){
    //Drawing everything
    wExit_.clear(sf::Color::White);
    yes_.show(wExit_);
    no_.show(wExit_);
    sure_.show(wExit_);
    wExit_.display();
}
