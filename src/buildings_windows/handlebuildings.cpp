//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/buildings-windows/handlebuildings.h"

void HandleBuildings::create_return_button(){
    return_to_game.create(40,100,5,5,"Return");
}

void HandleBuildings::main_loop(sf::Event &event, sf::RenderWindow &window, int &scene){
    handle_events(event,window,scene);
    do_stuff(window);
    display(window);
}

void HandleBuildings::resource_look(){
    //changing resource info _position
    lHuman_->setPosition(sf::Vector2f(150, 5));
    lRock_->setPosition(sf::Vector2f(270, 5));
    lWood_->setPosition(sf::Vector2f(410, 5));
    lMoney_->setPosition(sf::Vector2f(550,5));
    lIron_->setPosition(sf::Vector2f(690,5));

    //changing resource info text
    lHuman_->setCaption("People: " + std::to_string(*human_));
    lRock_->setCaption("Stone: " + std::to_string(*rock_));
    lWood_->setCaption("Wood: " + std::to_string(*wood_));
    lMoney_->setCaption("Money: "+std::to_string(*money_));
    lIron_->setCaption("Iron: "+std::to_string(*iron_));
}

void HandleBuildings::show_resources(sf::RenderWindow &window){
    lHuman_->show(window);
    lRock_->show(window);
    lWood_->show(window);
    lMoney_->show(window);
    lIron_->show(window);
}

void HandleBuildings::return_to_village(int &scene){
    //default resource info _position
    lHuman_->setPosition(sf::Vector2f(620, 5));
    lRock_->setPosition(sf::Vector2f(620, 33));
    lWood_->setPosition(sf::Vector2f(620, 61));
    lMoney_->setPosition(sf::Vector2f(620,89));
    lIron_->setPosition(sf::Vector2f(620,117));

    //default resource info text
    lHuman_->setCaption(std::to_string(*human_));
    lRock_->setCaption(std::to_string(*rock_));
    lWood_->setCaption(std::to_string(*wood_));
    lMoney_->setCaption(std::to_string(*money_));
    lIron_->setCaption(std::to_string(*iron_));

    scene=4;
}

void HandleBuildings::crete_info(){
    this->info.create(DEFAULT_FONT,5,100,"",30);
}

void HandleBuildings::assign_values(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd,
                                    int *bld, int *moni, int *iron) {
    //label value assigning
    lHuman_=lh;
    lRock_=lr;
    lWood_=lw;
    lMoney_=lm;
    lIron_=li;

    //resources value assigning
    human_=hn;
    rock_=rk;
    wood_=wd;
    money_=moni;
    iron_=iron;

    //building_ lvl
    building_=bld;
}
