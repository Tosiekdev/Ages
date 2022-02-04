//
// Created by tosiek on 02.02.2022.
//

#include "Upgrade_tablet.h"

Upgrade_tablet::Upgrade_tablet()=default;

//Draw everything
void Upgrade_tablet::show(RenderWindow &W){
    this->name.show(W);
    this->responsible->show_demands(this->position+Vector2f(0,50),W);
    this->upgrade.show(W);
}

void Upgrade_tablet::create_upgrade(buildings *resp, std::string caption, sf::Vector2f pos){
    this->position=pos;
    this->responsible=resp;
    this->name.create(DEFAULT_FONT,this->position.x,this->position.y,caption,40);
    this->upgrade.create(40,100,this->position.x+600, this->position.y,"Upgrade");
}

sf::Vector2f Upgrade_tablet::Return_position(){
    return this->position;
}

void Upgrade_tablet::set_position(Vector2f new_pos){
    this->position=new_pos;
    this->upgrade.set_position(this->position+sf::Vector2f(600,0));
    this->name.setPosition(this->position);
}

void Upgrade_tablet::button_animation(Vector2i pos){
    this->upgrade.onFocus(pos.x,pos.y);
}

bool Upgrade_tablet::button_clicked(Vector2i pos) {
    return this->upgrade.onClick(pos.x,pos.y);
}
