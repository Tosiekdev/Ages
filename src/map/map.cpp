//
// Created by tosiek on 28.09.22.
//

#include "../../headers/map/map.h"

Map::Map(){
    return_.create(40,100,5,5,"Return");

    //creating map of the world
    std::string pathToMap="Textures/Map/world.jpg";
    world_.create_obstacle(pathToMap,sf::Vector2f(1.f,1.f),sf::Vector2f(0,0));

    //navigation buttons
    left_.create_element("Textures/l_slide.png",sf::Vector2f(5,275));
    right_.create_element("Textures/r_slide.png",sf::Vector2f(755,275));
    top_.create_element("Textures/up.png",sf::Vector2f(375,5));
    bottom_.create_element("Textures/down.png",sf::Vector2f(375,555));
}

void Map::create(){
    //setting first view_ at the map
    view_.setCenter(400.f,300.f);
    view_.setSize(800.f,600.f);
}

void Map::handle_event(buildings::Scene &scene, sf::RenderWindow &window){
    while(window.pollEvent(event_)){
        if(event_.type==sf::Event::Closed){
            window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            auto mPos=sf::Mouse::getPosition(window);

            moving_map(window);

            if(return_.onClick(mPos.x,mPos.y)){
                //setting default camera to window
                view_.setCenter(400.f,300.f);
                view_.setSize(800.f,600.f);
                window.setView(view_);

                scene=buildings::Scene::GAME;
            }
        }
    }
}

void Map::do_stuff(sf::RenderWindow &window){
    std::vector<bool> rect;//vector to animate cursor

    auto mPos=sf::Mouse::getPosition(window);

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

    //navigation buttons
    left_.draw_it(window);
    right_.draw_it(window);
    top_.draw_it(window);
    bottom_.draw_it(window);

    //buttons
    return_.show(window);

    window.display();
}

void Map::moving_map(sf::RenderWindow &window){
    auto mPos=sf::Mouse::getPosition(window);
    mPos = (sf::Vector2i)window.mapPixelToCoords(mPos);

    if(left_.onClick(mPos.x,mPos.y)){
        view_.move(-100.f,0.f);
        //setting new position
        sf::Vector2f shift=sf::Vector2f(-100.f,0.f);
        shift_controls(shift);
    }
    if(right_.onClick(mPos.x,mPos.y)){
        view_.move(100.f,0.f);
        //setting new position
        sf::Vector2f shift=sf::Vector2f(100.f,0.f);
        shift_controls(shift);
    }
    if(top_.onClick(mPos.x,mPos.y)){
        view_.move(0.f,-100.f);
        //setting new position
        sf::Vector2f shift=sf::Vector2f(0.f,-100.f);
        shift_controls(shift);
    }
    if(bottom_.onClick(mPos.x,mPos.y)){
        view_.move(0.f,100.f);
        //setting new position
        sf::Vector2f shift=sf::Vector2f(0.f,100.f);
        shift_controls(shift);
    }
    window.setView(view_);
}

void Map::shift_controls(sf::Vector2f shift){
    sf::Vector2f leftPos=left_.get_position();
    leftPos+=shift;
    left_.set_position(leftPos);

    sf::Vector2f rightPos=right_.get_position();
    rightPos+=shift;
    right_.set_position(rightPos);

    sf::Vector2f topPos=top_.get_position();
    topPos+=shift;
    top_.set_position(topPos);

    sf::Vector2f bottomPos=bottom_.get_position();
    bottomPos+=shift;
    bottom_.set_position(bottomPos);
}
