//
// Created by tosiek on 28.09.22.
//

#include "../../headers/map/map.h"

Map::Map(){
    return_.create(40,100,5,5,"Return");

    //setting first view at the map
    view_.setCenter(400.f,300.f);
    view_.setSize(800.f,600.f);

    //creating map of the world
    std::string pathToMap="Textures/Map/world.jpg";
    world_.create_obstacle(pathToMap,sf::Vector2f(1.f,1.f),sf::Vector2f(0,0));
}

void Map::handle_event(int &scene, sf::RenderWindow &window){
    while(window.pollEvent(event_)){
        if(event_.type==sf::Event::Closed){
            window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            auto mPos=sf::Mouse::getPosition();

            if(return_.onClick(mPos.x,mPos.y)){
                scene=4;
                //setting default camera to window
                window.setView(sf::View(sf::Vector2f(400,300),sf::Vector2f(800,600)));
            }
        }
    }
}

void Map::do_stuff(sf::RenderWindow &window){
    std::vector<bool> rect;//vector to animate cursor

    auto mPos=sf::Mouse::getPosition();

    //animating buttons
    rect.push_back(return_.onFocus(mPos.x,mPos.y));

    if(std::count(rect.begin(),rect.end(),true)){
        cursor_.loadFromSystem(sf::Cursor::Hand);
    }else{
        cursor_.loadFromSystem(sf::Cursor::Arrow);
    }
    window.setMouseCursor(cursor_);

    window.setView(view_);
}

void Map::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //map
    world_.draw(window);

    //buttons
    return_.show(window);

    window.display();
}
