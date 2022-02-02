//
// Created by tosiek on 02.02.2022.
//

#include "Upgrade_tablet.h"

Upgrade_tablet::Upgrade_tablet()=default;

//Draw everything
void Upgrade_tablet::show(RenderWindow &W){
    this->name.show(W);
    this->responsible->show_demands(this->position-Vector2f(0,50),W);
    this->upgrade.show(W);
}

void Upgrade_tablet::create_upgrade(buildings *resp, std::string caption, sf::Vector2f pos){
    this->position=pos;
    this->responsible=resp;
    this->name.create(DEFAULT_FONT,this->position.x,this->position.y,caption,40);
    this->upgrade.create(40,100,this->position.x+400, this->position.y+50,"Upgrade");
}
