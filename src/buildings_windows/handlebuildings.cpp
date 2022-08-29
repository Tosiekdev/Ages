//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/handlebuildings.h"

void HandleBuildings::create_return_button(){
    this->return_to_game.create(40,100,5,5,"Return");
}

void HandleBuildings::main_loop(sf::Event &event, sf::RenderWindow &window, int &scene){
    this->handle_events(event,window,scene);
    this->do_stuff(window);
    this->display(window);
}

void HandleBuildings::resource_look(){
    //changing resource info _position
    this->l_human->setPosition(sf::Vector2f(200,5));
    this->l_rock->setPosition(sf::Vector2f(400,5));
    this->l_wood->setPosition(sf::Vector2f(600,5));

    //changing resource info text
    this->l_human->setCaption("People: "+std::to_string(*this->human));
    this->l_rock->setCaption("Stone: "+std::to_string(*this->rock));
    this->l_wood->setCaption("Wood: "+std::to_string(*this->wood));
}

void HandleBuildings::show_resources(sf::RenderWindow &window){
    this->l_human->show(window);
    this->l_rock->show(window);
    this->l_wood->show(window);
}

void HandleBuildings::return_to_village(int &scene){
    //default resource info _position
    this->l_human->setPosition(sf::Vector2f(620,5));
    this->l_rock->setPosition(sf::Vector2f(620,50));
    this->l_wood->setPosition(sf::Vector2f(620,95));

    //default resource info text
    this->l_human->setCaption(std::to_string(*this->human));
    this->l_rock->setCaption(std::to_string(*this->rock));
    this->l_wood->setCaption(std::to_string(*this->wood));

    scene=4;
}

void HandleBuildings::crete_info(){
    this->info.create(DEFAULT_FONT,5,100,"",30);
}

void HandleBuildings::assign_values(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //label value assigning
    this->l_human=lh;
    this->l_rock=lr;
    this->l_wood=lw;

    //resources value assigning
    this->human=hn;
    this->rock=rk;
    this->wood=wd;

    //building_ lvl
    this->building=bld;
}
