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
    new_game.create(40,100,40,130,"New Game");
    load_game.create(40,100,40,190,"Load Game");
    exit.create(40,100,40,250,"Exit");

    //Captions
    ages.create(DEFAULT_FONT,330,0,"Ages",60);
    programmer.create(DEFAULT_FONT,500,395,"Programista:",40);
    tosiek.create(DEFAULT_FONT,500,440,"Tosiek",35);
    graphic.create(DEFAULT_FONT,500,485,"Grafika:",40);
    iwa.create(DEFAULT_FONT,500,530,"Iwa",35);
}

void HandleMenu::main_loop(sf::RenderWindow &window, buildings::Scene &scene){
    handle_event(scene,window);
    do_stuff(window);
    display(window);
}

void HandleMenu::handle_event(buildings::Scene &scene, sf::RenderWindow &window){
    while(window.pollEvent(e)){
        if(e.type==sf::Event::Closed) window.close();
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) exitWindow.create(window,scene);

        //Mouse pressed events
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //getting mouse _position
            int a=sf::Mouse::getPosition(window).x;
            int b=sf::Mouse::getPosition(window).y;

            //new game button
            if(new_game.onClick(a,b)){
                scene=buildings::Scene::CREATE;
            }

            //load game button
            if(load_game.onClick(a,b)){
                scene=buildings::Scene::LOAD;
            }

            //exit button
            if(exit.onClick(a,b)){
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
    a[0]=new_game.onFocus(x,y);
    a[1]=load_game.onFocus(x,y);
    a[2]=exit.onFocus(x,y);

    //cursor_
    if(a[0] || a[1] || a[2])
        cursor.loadFromSystem(sf::Cursor::Hand);
    else
        cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor);
}

void HandleMenu::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //Background
    window.draw(background_menu_sprite);

    //Captions
    ages.show(window);
    programmer.show(window);
    tosiek.show(window);
    graphic.show(window);
    iwa.show(window);

    //Buttons
    new_game.show(window);
    load_game.show(window);
    exit.show(window);

    window.display();
}
