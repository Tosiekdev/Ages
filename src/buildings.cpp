//
// Created by tosiek on 04.12.2021.
//

#include <utility>

#include "../headers/buildings.h"

//Building initiation
void buildings::create_building(std::string nm,const std::string& tx_path,int lvl,sf::Vector2f pos,int ns,int nw,int np){
    name_=std::move(nm); //set name_
    level_=lvl; //set level_

    //set texture_
    look_.loadFromFile(tx_path);
    view_.setTexture(look_);

    //set _position
    possition_=pos;
    view_.setPosition(possition_);

    //set needed resources
    nHuman_= static_cast<int>(np * pow(1.67,level_ - 1));
    nWood_= static_cast<int>(nw * pow(1.67,level_ - 1));
    nStone_= static_cast<int>(ns * pow(1.67,level_ - 1));

    //set label _position
    sName_.setCaption(name_);
    sf::Vector2f l_pos= possition_ + sf::Vector2f(10, 100);
    sName_.setPosition(l_pos);

    //star to show level_
    create_star();
}

//First part of upgrade, take resources
int buildings::take_resources(int &human, int &rock, int &wood) {
    if(nHuman_ <= human && nStone_ <= rock && nWood_ <= wood && !inUpgrade_ && level_ < 30){
        //take resources
        human-=nHuman_;
        rock-=nStone_;
        wood-=nWood_;

        //rise demands
        nStone_*=1.67;
        nWood_*=1.67;
        nHuman_*=1.67;

        inUpgrade_=true;

        return 1;
    }
    return 0;
}

//Draw building
void buildings::show(sf::RenderWindow &W){
    if(level_ > 0){
        W.draw(view_);
        W.draw(starView_);
        lvlLabel_.show(W);
        sName_.show(W);
    }
}

//creating star
void buildings::create_star(){
    //load texture_
    starLook_.loadFromFile("Textures/star.png");
    starView_.setTexture(starLook_);
    starView_.setScale(0.05, 0.05);

    //positioning
    starPossition_= possition_ + sf::Vector2f(125, 0);
    starView_.setPosition(starPossition_);

    //text
    float labelPosX=starPossition_.x+20;
    float labelPosY=starPossition_.y+15;
    lvlLabel_.create(DEFAULT_FONT,labelPosX,labelPosY,std::to_string(level_),15);
    lvlLabel_.center();
}

bool buildings::isClicked(int posX, int posY){
    return view_.getGlobalBounds().contains((float)posX, (float)posY) && active_;
}

void buildings::show_demands(sf::Vector2f pos, sf::RenderWindow &window){
    //prepare labels
    forHuman_.create(DEFAULT_FONT,pos.x,pos.y,"People: " + std::to_string(nHuman_),15);
    forStone_.create(DEFAULT_FONT,pos.x+100,pos.y,"Stone: "+std::to_string(nStone_),15);
    forWood_.create(DEFAULT_FONT,pos.x+200,pos.y,"Wood: "+std::to_string(nWood_),15);

    //display demands
    forHuman_.show(window);
    forStone_.show(window);
    forWood_.show(window);
}

int buildings::get_level() const{
    return level_;
}

bool buildings::status() const {
    return inUpgrade_;
}

void buildings::end_upgrade(){
    level_++;
    inUpgrade_=false;
    lvlLabel_.setCaption(std::to_string(this->level_));
    lvlLabel_.center();
}

void buildings::set_status(bool new_status){
    inUpgrade_=new_status;
}

bool buildings::onFocus(int pos_x, int pos_y){
    return view_.getGlobalBounds().contains((float)pos_x,(float)pos_y);
}

void buildings::activate(){
    active_=true;
}

void buildings::deactivate(){
    active_=false;
}

void buildings::set_level(int lvl){
    level_=lvl;
}

