//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/buildings-windows/handlebuildings.h"

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
    this->l_human->setPosition(sf::Vector2f(150,5));
    this->l_rock->setPosition(sf::Vector2f(310,5));
    this->l_wood->setPosition(sf::Vector2f(470,5));
    lMoney_->setPosition(sf::Vector2f(630,5));

    //changing resource info text
    this->l_human->setCaption("People: "+std::to_string(*this->human));
    this->l_rock->setCaption("Stone: "+std::to_string(*this->rock));
    this->l_wood->setCaption("Wood: "+std::to_string(*this->wood));
    lMoney_->setCaption("Money: "+std::to_string(*money_));
}

void HandleBuildings::show_resources(sf::RenderWindow &window){
    this->l_human->show(window);
    this->l_rock->show(window);
    this->l_wood->show(window);
    lMoney_->show(window);
}

void HandleBuildings::return_to_village(int &scene){
    //default resource info _position
    this->l_human->setPosition(sf::Vector2f(620,5));
    this->l_rock->setPosition(sf::Vector2f(620,41));
    this->l_wood->setPosition(sf::Vector2f(620,77));
    lMoney_->setPosition(sf::Vector2f(620,113));

    //default resource info text
    this->l_human->setCaption(std::to_string(*this->human));
    this->l_rock->setCaption(std::to_string(*this->rock));
    this->l_wood->setCaption(std::to_string(*this->wood));
    lMoney_->setCaption(std::to_string(*money_));

    scene=4;
}

void HandleBuildings::crete_info(){
    this->info.create(DEFAULT_FONT,5,100,"",30);
}

void HandleBuildings::assign_values(Label *lh, Label *lr, Label *lw, Label *lm, int *hn, int *rk, int *wd, int *bld,
                                    int *moni) {
    //label value assigning
    this->l_human=lh;
    this->l_rock=lr;
    this->l_wood=lw;
    lMoney_=lm;

    //resources value assigning
    this->human=hn;
    this->rock=rk;
    this->wood=wd;
    money_=moni;

    //building_ lvl
    this->building_=bld;
}
