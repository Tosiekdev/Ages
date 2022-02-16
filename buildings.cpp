//
// Created by tosiek on 04.12.2021.
//

#include "buildings.h"
#include "needed.h"

using namespace std;
using namespace sf;

buildings::buildings(string the_name,string path_totext,int leveled,int need_s,int need_w,int need_g,Vector2f position){
    this->active=true;
    this->in_upgrade=false;
    this->create_building(the_name,path_totext,leveled,position,need_s,need_w,need_g);
}

//Building initiation
void buildings::create_building(string nm,string tx_path,int lvl,Vector2f pos,int ns,int nw,int np){
    this->name=nm; //set name
    this->level=lvl; //set level

    //set texture
    this->look.loadFromFile(tx_path);
    this->view.setTexture(this->look);

    //set position
    this->possition=pos;
    this->view.setPosition(this->possition);

    //set needed resources
    this->n_human=np*pow(1.67,this->level-1);
    this->n_wood=nw*pow(1.67,this->level-1);
    this->n_stone=ns*pow(1.67,this->level-1);

    //set label position
    this->s_name.setCaption(this->name);
    Vector2f l_pos=this->possition+Vector2f(10,100);
    this->s_name.setPosition(l_pos);

    //star to show level
    this->create_star();
}
;
//First part of upgrade, take resources
int buildings::take_resources(int &human, int &rock, int &wood) {
    if(this->n_human<=human && this->n_stone<=rock && this->n_wood <= wood && !this->in_upgrade && this->level<30){
        //take resources
        human-=this->n_human;
        rock-=this->n_stone;
        wood-=this->n_wood;

        //rise demands
        this->n_stone*=1.67;
        this->n_wood*=1.67;
        this->n_human*=1.67;

        this->in_upgrade=true;

        return 1;
    }
    return 0;
}

//Draw building
void buildings::show(RenderWindow &W){
    if(this->level>0){
        W.draw(this->view);
        W.draw(this->star_view);
        this->lvl_label.show(W);
        this->s_name.show(W);
    }
}

//creating star
void buildings::create_star(){
    //load texture
    this->star_look.loadFromFile("Textures/star.png");
    this->star_view.setTexture(this->star_look);
    this->star_view.setScale(0.05, 0.05);

    //positioning
    this->star_possition=this->possition+Vector2f(125, 0);
    this->star_view.setPosition(this->star_possition);

    //text
    this->lvl_label.create(DEFAULT_FONT, this->star_possition.x+20, this->star_possition.y+15, to_string(this->level), 15);
    this->lvl_label.center();
}

bool buildings::isClicked(int posx, int posy){
    if(this->view.getGlobalBounds().contains((float)posx,(float)posy) && this->active){
        return true;
    }else
        return false;
}

void buildings::show_demands(Vector2f pos, RenderWindow &window){
    //prepare labels
    this->for_human.create(DEFAULT_FONT,(int)pos.x,(int)pos.y,"People: "+ to_string(this->n_human),15);
    this->for_stone.create(DEFAULT_FONT,(int)pos.x+100,(int)pos.y,"Stone: "+ to_string(this->n_stone),15);
    this->for_wood.create(DEFAULT_FONT,(int)pos.x+200,(int)pos.y,"Wood: "+ to_string(this->n_wood),15);

    //display demands
    this->for_human.show(window);
    this->for_stone.show(window);
    this->for_wood.show(window);
}

int buildings::get_level() const{
    return this->level;
}

bool buildings::status() {
    return this->in_upgrade;
}

void buildings::end_upgrade(){
    this->level++;
    this->in_upgrade=false;
    this->lvl_label.setCaption(to_string(this->level));
    this->lvl_label.center();
}

void buildings::set_status(bool new_status){
    this->in_upgrade=new_status;
}

bool buildings::onFocus(int pos_x, int pos_y){
    if(this->view.getGlobalBounds().contains(pos_x,pos_y)){
        return true;
    }
    return false;
}

void buildings::activate(){
    this->active=true;
}

void buildings::disactivate(){
    this->active=false;
}

