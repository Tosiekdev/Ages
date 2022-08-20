//
// Created by tosiek on 11.08.22.
//

#include "../headers/Soldier.h"

Soldier::Soldier(){
    pTexture_.loadFromFile(PLANK);
    plank_.setTexture(pTexture_);

    plank_.setScale(0.186,0.186);
}

//this happens when player try to make train
std::array<int,3> Soldier::train(int people, int iron, int money){
    //assign resources that we can return it
    std::array<int,3> resources{people,iron,money};

    if(this->n_people<=people && this->n_money<=money && this->n_iron<=iron){
        //take needed resources
        resources[0]-=this->n_people;
        resources[1]-=this->n_iron;
        resources[2]-=this->n_money;

        this->time_left_=this->upgrade_time_;

        this->in_upgrade_=true;
    }

    return resources;
}

//to make showing unit easier
void Soldier::slide(float shift){
    sf::Vector2f position=this->view_.getPosition();
    position.x+=shift;
    set_position(position);
}

void Soldier::show(sf::RenderWindow &window){
    window.draw(this->view_);
    name_.draw(window);
    upgrade_.show(window);
    counter_.show(window);

    //stats
    window.draw(plank_);
    hp_.show(window);
    dmg_.show(window);
    arm_.show(window);
}

//returns vector of damage to hurt others
std::vector<int> Soldier::give_damage(Type which,std::vector<int> old_damage){
    for(int i=0; i<this->quantity; i++)
        old_damage.push_back(this->attack_calculator(which));

    return old_damage;
}

//this happens when time needed to train passed
void Soldier::end_upgrade(){
    in_upgrade_=false;
    lives_.push_back(this->hp);
    quantity++;
    update_counter();
}

void Soldier::set_position(sf::Vector2f pos){
    this->view_.setPosition(pos);

    sf::Vector2f name_pos=pos+sf::Vector2f(-1,113);
    name_.set_position(name_pos);

    sf::Vector2f button_pos=name_pos+sf::Vector2f(26,35);
    upgrade_.set_position(button_pos);

    sf::Vector2f count_pos=name_pos+sf::Vector2f(56,12);
    counter_.setPosition(count_pos);

    sf::Vector2f plank_pos=name_pos+sf::Vector2f(0,70);
    plank_.setPosition(plank_pos);

    sf::Vector2f hp_pos=plank_pos+sf::Vector2f(25,5);
    hp_.setPosition(hp_pos);

    sf::Vector2f dmg_pos=hp_pos+sf::Vector2f(0,17);
    dmg_.setPosition(dmg_pos);

    sf::Vector2f arm_pos=dmg_pos+sf::Vector2f(0,17);
    arm_.setPosition(arm_pos);
}

void Soldier::take_damage(std::vector<int> damage){
    size_t j=0;
    while(j<damage.size()){
        auto index=j%lives_.size();
        if(lives_[index] > 0){
            lives_[index]-=damage[j];
            if(lives_[index]<=0){
                quantity--;
            }
            j++;
        }
        if(j>damage.size()){ break; }
    }
}

void Soldier::set_stats(){
    int size=12;
    hp_.create(DEFAULT_FONT,0,0,"HP: "+std::to_string(hp),size);
    dmg_.create(DEFAULT_FONT,0,0,"Damage: "+std::to_string(attack),size);
    arm_.create(DEFAULT_FONT,0,0,"Armor: "+std::to_string(armor),size);
}
