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
    this->clock.show(W);
}

void Upgrade_tablet::create_upgrade(buildings *resp, std::string caption, sf::Vector2f pos){
    this->position=pos;
    this->responsible=resp;
    this->name.create(DEFAULT_FONT,this->position.x,this->position.y,caption,40);

    //button
    this->upgrade.create(40,100,this->position.x+600, this->position.y,"Upgrade");

    //timer
    this->clock.create(DEFAULT_FONT,this->position.x+400,this->position.y,"",40);
}

sf::Vector2f Upgrade_tablet::Return_position(){
    return this->position;
}

void Upgrade_tablet::set_position(Vector2f new_pos){
    this->position=new_pos;
    this->upgrade.set_position(this->position+sf::Vector2f(600,0));
    this->name.setPosition(this->position);
    this->clock.setPosition(this->position+Vector2f(400,0));
}

void Upgrade_tablet::button_animation(Vector2i pos){
    this->upgrade.onFocus(pos.x,pos.y);
}

bool Upgrade_tablet::button_clicked(Vector2i pos) {
    return this->upgrade.onClick(pos.x,pos.y);
}

float Upgrade_tablet::get_time(){
    return this->timer.getElapsedTime().asSeconds();
}

void Upgrade_tablet::upgrade_building(int &human, int &rock, int &wood){
    if(this->responsible->take_resources(human,rock,wood)){
        this->time_left = ((float) this->responsible->get_level() + 1.f) * 10;
        this->update_timer(0);
    }
}

void Upgrade_tablet::update_timer(float time_passed){
    this->time_left-=time_passed;
    int minutes=(int)this->time_left/60;
    int seconds=(int)this->time_left%60;
    string m,s;
    if(minutes>9)
        m=to_string(minutes);
    else
        m="0"+to_string(minutes);
    if(seconds>9)
        s=to_string(seconds);
    else
        s="0"+to_string(seconds);
    this->clock.setCaption(m+":"+s);
}
