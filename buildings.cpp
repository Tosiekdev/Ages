//
// Created by tosiek on 04.12.2021.
//

#include "buildings.h"
#include "needed.h"

using namespace std;
using namespace sf;

buildings::buildings(string the_name,string path_totext,int leveled,int need_s,int need_w,int need_g,Vector2f position){
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
    this->n_human=np;
    this->n_wood=nw;
    this->n_stone=ns;

    //set label position
    this->s_name.setCaption(this->name);
    Vector2f l_pos=this->possition+Vector2f(10,100);
    this->s_name.setPosition(l_pos);

    //star to show level
    this->create_star();
}
;
//Building upgrade
void buildings::upgrade(int &lvl, int &human, int &rock, int &wood){
    if(this->n_human<=human && this->n_stone<=rock && this->n_wood <= wood){
        //take resources
        human-=this->n_human;
        rock-=this->n_stone;
        wood-=this->n_wood;

        //increase level
        this->level++;
        lvl++;

        //rise demands
        this->n_stone+=pow(n_stone,2/3);
        this->n_wood+=pow(n_wood,2/3);
        this->n_human+=pow(n_human,2/3);
    }
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
    this->lvl_label.create(DEFAULT_FONT, this->star_possition.x+15, this->star_possition.y+5, to_string(this->level), 20);
}

bool buildings::isClicked(int posx, int posy) {
    if(this->view.getGlobalBounds().contains((float)posx,(float)posy)){
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

