//
// Created by tosiek on 09.02.2022.
//

#include "../headers/ExitWindow.h"

void ExitWindow::create(sf::RenderWindow &W, int &scene){
    //creating window
    this->w_exit.create(VideoMode(300,200),"Are you sure?",Style::Titlebar | Style::Close);
    this->w_exit.setPosition(Vector2i(250+W.getPosition().x,200+W.getPosition().y));
    this->w_exit.setMouseCursorGrabbed(true);

    //creating buttons
    this->yes.create(40,100,167,110,"Yes");
    this->no.create(40,100,33,110,"No");
    this->sure.create(DEFAULT_FONT,2,20,"Are sure you want exit?",28);

    this->main_loop(W,scene);
}

void ExitWindow::main_loop(RenderWindow &window, int &scene){
    while(this->w_exit.isOpen()) {
        this->handle_event(scene,window);
        this->do_stuff(window);
        this->display(window);
    }
}

void ExitWindow::handle_event(int &scene, RenderWindow &window){
    while(this->w_exit.pollEvent(this->exit_e)){
        //Exit
        if(this->exit_e.type==Event::Closed) this->w_exit.close();

        //Is button clicked?
        if(this->exit_e.type==Event::MouseButtonPressed){
            //Getting mouse position
            int x=Mouse::getPosition(this->w_exit).x;
            int y=Mouse::getPosition(this->w_exit).y;

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

void ExitWindow::do_stuff(RenderWindow &window){
    //Button animation
    bool a[2];
    a[0]=this->yes.onFocus(Mouse::getPosition(this->w_exit).x,Mouse::getPosition(this->w_exit).y);
    a[1]=this->no.onFocus(Mouse::getPosition(this->w_exit).x,Mouse::getPosition(this->w_exit).y);

    //cursor
    if(a[0] || a[1])
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    this->w_exit.setMouseCursor(this->cursor);
}

void ExitWindow::display(RenderWindow &window){
    //Drawing everything
    this->w_exit.clear(Color::White);
    this->yes.show(this->w_exit);
    this->no.show(this->w_exit);
    this->sure.show(this->w_exit);
    this->w_exit.display();
}
