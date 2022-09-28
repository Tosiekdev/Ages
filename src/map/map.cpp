//
// Created by tosiek on 28.09.22.
//

#include "../../headers/map/map.h"

Map::Map(){
    return_.create(40,100,5,5,"Return");
}

void Map::handle_event(int &scene, sf::RenderWindow &window){
    while(window.pollEvent(event_)){
        if(event_.type==sf::Event::Closed){
            window.close();
        }
    }
}

void Map::do_stuff(sf::RenderWindow &window){

}

void Map::display(sf::RenderWindow &window){

}
