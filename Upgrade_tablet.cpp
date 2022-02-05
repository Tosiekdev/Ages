//
// Created by tosiek on 02.02.2022.
//

#include "Upgrade_tablet.h"

//useless fckin' piece of shit
Upgrade_tablet::Upgrade_tablet()=default;

//Draw everything
void Upgrade_tablet::show(RenderWindow &W){
    this->name.show(W);

    //showing building demands
    this->responsible->show_demands(this->position+Vector2f(0,50),W);
    this->upgrade.show(W);
    if(this->responsible->status()){
        W.draw(this->counting_down);
        this->clock.show(W);
    }
}

//actual constructor
void Upgrade_tablet::create_upgrade(buildings *resp, std::string caption, sf::Vector2f pos){
    this->position=pos;
    this->responsible=resp;
    this->name.create(DEFAULT_FONT,this->position.x,this->position.y,caption,40);

    //button
    this->upgrade.create(40,100,this->position.x+600, this->position.y,"Upgrade");

    //timer
    this->clock.create(DEFAULT_FONT,this->position.x+400,this->position.y,"",40);

    //progress bar
    this->counting_down.setSize(sf::Vector2f(300,50));
    this->counting_down.setFillColor(sf::Color::Green);
    this->counting_down.setPosition(this->position+Vector2f(300,0));

    //restart timer
    this->timer.restart();
}

//returns position
sf::Vector2f Upgrade_tablet::Return_position(){
    return this->position;
}

//new position
void Upgrade_tablet::set_position(Vector2f new_pos){
    this->position=new_pos;
    this->upgrade.set_position(this->position+sf::Vector2f(600,0));//button
    this->name.setPosition(this->position);//building name
    this->clock.setPosition(this->position+Vector2f(400,0));//timer
    this->counting_down.setPosition(this->position+Vector2f(300,0));//progress bar
}

//cool animation
void Upgrade_tablet::button_animation(Vector2i pos){
    this->upgrade.onFocus(pos.x,pos.y);
}

//returns if button is clicked
bool Upgrade_tablet::button_clicked(Vector2i pos) {
    return this->upgrade.onClick(pos.x,pos.y);
}

//returns time
float Upgrade_tablet::get_time(){
    return this->timer.getElapsedTime().asSeconds();
}

//takes resources
void Upgrade_tablet::upgrade_building(int &human, int &rock, int &wood){
    if(this->responsible->take_resources(human,rock,wood)){
        this->timer.restart();
        this->time_left = ((float) this->responsible->get_level() + 1.f) * 10;
        this->update_timer(0);
    }
}

//update timer with every second
int Upgrade_tablet::update_timer(float time_passed){
    if(this->responsible->status()){
        //prepare timer
        this->time_left -= (int)time_passed;
        int minutes = (int) this->time_left / 60;
        int seconds = (int) this->time_left % 60;
        string m, s;
        if (minutes > 9)
            m = to_string(minutes);
        else
            m = "0" + to_string(minutes);
        if (seconds > 9)
            s = to_string(seconds);
        else
            s = "0" + to_string(seconds);
        this->clock.setCaption(m + ":" + s);

        //if time passed upgrade building
        if(this->time_left==0){
            this->responsible->end_upgrade();
            this->counting_down.setSize(sf::Vector2f(300,50));
            return 3;
        }

        //update progress bar
        Vector2f size = this->counting_down.getSize()-Vector2f(time_passed * (30.f/((float) this->responsible->get_level()+1)), 0);
        this->counting_down.setSize(size);

        return 2;
    }
    return 1;
}

//restarts timer
void Upgrade_tablet::reset_timer(){
    this->timer.restart();
}
