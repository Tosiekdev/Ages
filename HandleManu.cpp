//
// Created by tosiek on 09.02.2022.
//

#include "HandleManu.h"

void HandleMenu::create(){
    //Textures loading
    this->background_menu_texture.loadFromFile("Textures/background.png");
    this->background_menu_sprite.setTexture(this->background_menu_texture);
    this->background_menu_sprite.setPosition(0,0);

    //Buttons
    this->new_game.create(40,100,40,130,"New Game");
    this->load_game.create(40,100,40,190,"Load Game");
    this->exit.create(40,100,40,250,"Exit");

    //Captions
    this->ages.create(DEFAULT_FONT,330,0,"Ages",60);
    this->programmer.create(DEFAULT_FONT,500,395,"Programista:",40);
    this->tosiek.create(DEFAULT_FONT,500,440,"Tosiek",35);
    this->graphic.create(DEFAULT_FONT,500,485,"Grafika:",40);
    this->iwa.create(DEFAULT_FONT,500,530,"Iwa",35);
}

void HandleMenu::main_loop(RenderWindow &window, int &scene){
    this->handle_event(scene,window);
    this->do_stuff(window);
    this->display(window);
}

void HandleMenu::handle_event(int &scene, RenderWindow &window){
    while(window.pollEvent(this->e)){
        if(this->e.type==Event::Closed) window.close();
        if((Keyboard::isKeyPressed(Keyboard::Escape))) this->exitWindow.create(window,scene);

        //Mouse pressed events
        if(Mouse::isButtonPressed(Mouse::Left)){
            //getting mouse position
            int a=Mouse::getPosition(window).x;
            int b=Mouse::getPosition(window).y;

            //new game button
            if(this->new_game.onClick(a,b)){
                scene=2;
            }

            //load game button
            if(this->load_game.onClick(a,b)){
                scene=3;
            }

            //exit button
            if(this->exit.onClick(a,b)){
                window.close();
            }
        }
    }
}

void HandleMenu::do_stuff(RenderWindow &window){
    bool a[3];
    //getting mouse position
    int x=Mouse::getPosition(window).x;
    int y=Mouse::getPosition(window).y;

    //checking buttons focus
    a[0]=this->new_game.onFocus(x,y);
    a[1]=this->load_game.onFocus(x,y);
    a[2]=this->exit.onFocus(x,y);

    //cursor
    if(a[0] || a[1] || a[2])
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    window.setMouseCursor(this->cursor);
}

void HandleMenu::display(RenderWindow &window){
    window.clear(Color::White);

    //Background
    window.draw(this->background_menu_sprite);

    //Captions
    this->ages.show(window);
    this->programmer.show(window);
    this->tosiek.show(window);
    this->graphic.show(window);
    this->iwa.show(window);

    //Buttons
    this->new_game.show(window);
    this->load_game.show(window);
    this->exit.show(window);

    window.display();
}
