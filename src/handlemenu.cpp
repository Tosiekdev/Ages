//
// Created by tosiek on 09.02.2022.
//

#include "../headers/handlemenu.h"

void HandleMenu::create(){
    //Textures loading
    background_menu_texture.loadFromFile("Textures/background.png");
    background_menu_sprite.setTexture(background_menu_texture);
    background_menu_sprite.setPosition(0,0);

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

void HandleMenu::main_loop(sf::RenderWindow &window, buildings::Scene &scene){
    this->handle_event(scene,window);
    this->do_stuff(window);
    this->display(window);
}

void HandleMenu::handle_event(buildings::Scene &scene, sf::RenderWindow &window){
    while(window.pollEvent(this->e)){
        if(this->e.type==sf::Event::Closed) window.close();
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) this->exitWindow.create(window,scene);

        //Mouse pressed events
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //getting mouse _position
            int a=sf::Mouse::getPosition(window).x;
            int b=sf::Mouse::getPosition(window).y;

            //new game button
            if(this->new_game.onClick(a,b)){
                scene=buildings::Scene::CREATE;
            }

            //load game button
            if(this->load_game.onClick(a,b)){
                scene=buildings::Scene::LOAD;
            }

            //exit button
            if(this->exit.onClick(a,b)){
                window.close();
            }
        }
    }
}

void HandleMenu::do_stuff(sf::RenderWindow &window){
    bool a[3];
    //getting mouse _position
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //checking buttons focus_
    a[0]=this->new_game.onFocus(x,y);
    a[1]=this->load_game.onFocus(x,y);
    a[2]=this->exit.onFocus(x,y);

    //cursor_
    if(a[0] || a[1] || a[2])
        this->cursor.loadFromSystem(sf::Cursor::Hand);
    else
        this->cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(this->cursor);
}

void HandleMenu::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

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
