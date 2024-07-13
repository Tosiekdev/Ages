//
// Created by tosiek on 02.02.2022.
//

#include "../headers/upgradetablet.h"

//useless fckin' piece of shit
Upgrade_tablet::Upgrade_tablet()=default;

//Draw everything
void Upgrade_tablet::show(sf::RenderWindow &W){
    name.show(W);

    //star
    W.draw(supernova);
    star_text.show(W);

    //showing building_ demands
    responsible->show_demands(position+sf::Vector2f(0,50),W);
    upgrade.show(W);
    if(responsible->status()){
        W.draw(counting_down);
        clock.show(W);
    }
}

//actual constructor
void Upgrade_tablet::create_upgrade(buildings *resp, std::string caption, sf::Vector2f pos){
    position=pos;
    responsible=resp;
    responsible->set_status(false);

    //building_ name_
    name.create(DEFAULT_FONT,position.x,position.y,caption,40);

    //star
    star.loadFromFile("Textures/star.png");
    supernova.setTexture(star);
    supernova.setScale(0.08,0.08);
    float width=position.x+name.getWidth();
    supernova.setPosition(width+10,position.y-15);
    star_text.create(DEFAULT_FONT,width+41,position.y+10,std::to_string(responsible->get_level()),25);
    star_text.center();

    //button
    upgrade.create(40,100,position.x+600, position.y,"Upgrade");

    //timer
    clock.create(DEFAULT_FONT,position.x+400,position.y,"",40);

    //progress bar
    counting_down.setSize(sf::Vector2f(300,50));
    counting_down.setFillColor(sf::Color::Green);
    counting_down.setPosition(position+sf::Vector2f(300,0));

    //restart timer
    timer.restart();
}

//returns _position
sf::Vector2f Upgrade_tablet::Return_position(){
    return position;
}

//new _position
void Upgrade_tablet::set_position(sf::Vector2f new_pos){
    position=new_pos;
    upgrade.set_position(position+sf::Vector2f(600,0));//button
    name.setPosition(position);//building_ name_
    clock.setPosition(position+sf::Vector2f(400,0));//timer
    counting_down.setPosition(position+sf::Vector2f(300,0));//progress bar
    supernova.setPosition(position.x+name.getWidth()+10,position.y-15);//star
    star_text.setPosition(sf::Vector2f(position.x+name.getWidth()+41,position.y+10));//star text
}

//cool animation
bool Upgrade_tablet::button_animation(sf::Vector2i pos){
    return upgrade.onFocus(pos.x,pos.y);
}

//returns if button is clicked
bool Upgrade_tablet::button_clicked(sf::Vector2i pos) {
    return upgrade.onClick(pos.x,pos.y);
}

//returns time
float Upgrade_tablet::get_time(){
    return timer.getElapsedTime().asSeconds();
}

//takes resources
void Upgrade_tablet::upgrade_building(int &human, int &rock, int &wood, int bonus){
    if(responsible->take_resources(human,rock,wood)){
        timer.restart();
        time_left=((float)responsible->get_level()+1.f)*10;
        update_timer((float)bonus);
    }
}

//update timer with every second
int Upgrade_tablet::update_timer(float time_passed){
    if(responsible->status()){
        //prepare timer
        time_left -= (int)time_passed;
        int minutes = (int) time_left / 60;
        int seconds = (int) time_left % 60;
        std::string m, s;
        if (minutes > 9)
            m = std::to_string(minutes);
        else
            m = "0" + std::to_string(minutes);
        if (seconds > 9)
            s = std::to_string(seconds);
        else
            s = "0" + std::to_string(seconds);
        clock.setCaption(m + ":" + s);

        //if time passed upgrade building_
        if(time_left<=0){
            responsible->end_upgrade();
            counting_down.setSize(sf::Vector2f(300,50));
            update_level();
            star_text.center();
            return 3;
        }

        //update progress bar
        sf::Vector2f size = counting_down.getSize()-sf::Vector2f(time_passed * (30.f/((float) responsible->get_level()+1)), 0);
        counting_down.setSize(size);

        return 2;
    }
    return 1;
}

//restarts timer
void Upgrade_tablet::reset_timer(){
    timer.restart();
}

float Upgrade_tablet::get_left() const{
    return time_left;
}

void Upgrade_tablet::set_left(float time,float th){
    if(time!=0){
        responsible->set_status(true);
        time_left=((float)responsible->get_level()+1.f)*10;
        update_timer(th);
        update_timer(time_left-time);
        time_left=time;
    }else{
        time_left=time;
    }
}

void Upgrade_tablet::update_level(){
    star_text.setCaption(std::to_string(responsible->get_level()));
}

