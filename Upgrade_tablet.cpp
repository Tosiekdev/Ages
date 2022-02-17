//
// Created by tosiek on 02.02.2022.
//

#include "Upgrade_tablet.h"

//useless fckin' piece of shit
Upgrade_tablet::Upgrade_tablet()=default;

//Draw everything
void Upgrade_tablet::show(RenderWindow &W){
    this->name.show(W);

    //star
    W.draw(this->supernova);
    this->star_text.show(W);

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
    this->responsible->set_status(false);

    //building name
    this->name.create(DEFAULT_FONT,this->position.x,this->position.y,caption,40);

    //star
    this->star.loadFromFile("Textures/star.png");
    this->supernova.setTexture(this->star);
    this->supernova.setScale(0.08,0.08);
    float width=this->position.x+this->name.getWidth();
    this->supernova.setPosition(width+10,this->position.y-15);
    this->star_text.create(DEFAULT_FONT,width+41,this->position.y+10,to_string(this->responsible->get_level()),25);
    this->star_text.center();

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
    this->supernova.setPosition(this->position.x+this->name.getWidth()+10,this->position.y-15);//star
    this->star_text.setPosition(Vector2f(this->position.x+this->name.getWidth()+41,this->position.y+10));//star text
}

//cool animation
bool Upgrade_tablet::button_animation(Vector2i pos){
    return this->upgrade.onFocus(pos.x,pos.y);
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
void Upgrade_tablet::upgrade_building(int &human, int &rock, int &wood, int bonus){
    if(this->responsible->take_resources(human,rock,wood)){
        this->timer.restart();
        this->time_left=((float)this->responsible->get_level()+1.f)*10;
        this->update_timer((float)bonus);
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
        if(this->time_left<=0){
            this->responsible->end_upgrade();
            this->counting_down.setSize(sf::Vector2f(300,50));
            this->update_level();
            this->star_text.center();
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

float Upgrade_tablet::get_left() const{
    return this->time_left;
}

void Upgrade_tablet::set_left(float time,float th){
    if(time!=0){
        this->responsible->set_status(true);
        this->time_left=((float)this->responsible->get_level()+1.f)*10;
        std::cout << this->time_left-time << "\n";
        this->update_timer(th);
        this->update_timer(this->time_left-time);
        this->time_left=time;
    }else{
        this->time_left=time;
    }
}

void Upgrade_tablet::update_level(){
    this->star_text.setCaption(std::to_string(this->responsible->get_level()));
}

