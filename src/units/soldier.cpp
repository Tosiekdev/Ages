//
// Created by tosiek on 11.08.22.
//

#include "../../headers/units/soldier.h"

Soldier::Soldier(){
    pTexture_.loadFromFile(PLANK);
    plank_.setTexture(pTexture_);

    plank_.setScale(0.186,0.186);

    left_.create(DEFAULT_FONT,0,0,"0s",20);
}

//this happens when player try to make train
std::array<int, 3> Soldier::train(int people, int iron, int money, int count) {
    //assign resources that we can return it
    std::array<int,3> resources{people,iron,money};

    std::array<int,3> needed{count*nPeople_,count*nIron_,count*nMoney_};

    if(needed[0] <= people && needed[1] <= money && needed[2] <= iron){
        //take needed resources
        for(size_t i=0; i<3; i++){
            resources[i]-=needed[i];
        }

        timeLeft_=upgradeTime_*static_cast<float>(count);
        unitTime_=0;
        forUpgrade_.restart();
        inUpgrade_=true;

        left_.setCaption(std::to_string((int)timeLeft_)+"s");
        left_.center();
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
    window.draw(view_);
    name_.draw(window);
    upgrade_.show(window);
    counter_.show(window);

    //stats
    window.draw(plank_);
    lHp_.show(window);
    dmg_.show(window);
    arm_.show(window);

    //timer
    if(inUpgrade_){
        left_.show(window);
    }
}

//returns vector of damage to hurt others
std::vector<int> Soldier::give_damage(Type which,std::vector<int> old_damage){
    for(int i=0; i<this->quantity_; i++)
        old_damage.push_back(this->attack_calculator(which));

    return old_damage;
}

//this happens when time needed to train passed
void Soldier::end_upgrade(){
    inUpgrade_=false;
    lives_.push_back(this->hp_);
    quantity_++;
    update_counter();
}

void Soldier::set_position(sf::Vector2f pos){
    view_.setPosition(pos);

    sf::Vector2f name_pos=pos+sf::Vector2f(-1,113);
    name_.set_position(name_pos);

    sf::Vector2f button_pos=name_pos+sf::Vector2f(26,35);
    upgrade_.set_position(button_pos);

    sf::Vector2f count_pos=name_pos+sf::Vector2f(56,12);
    counter_.setPosition(count_pos);

    sf::Vector2f plank_pos=name_pos+sf::Vector2f(0,70);
    plank_.setPosition(plank_pos);

    sf::Vector2f hp_pos=plank_pos+sf::Vector2f(25,5);
    lHp_.setPosition(hp_pos);

    sf::Vector2f dmg_pos=hp_pos+sf::Vector2f(0,17);
    dmg_.setPosition(dmg_pos);

    sf::Vector2f arm_pos=dmg_pos+sf::Vector2f(0,17);
    arm_.setPosition(arm_pos);

    sf::Vector2f timer_pos=arm_pos+sf::Vector2f(25,37);
    left_.setPosition(timer_pos);
}

void Soldier::take_damage(std::vector<int> damage){
    size_t j=0;
    while(j<damage.size()){
        auto index=j%lives_.size();
        if(lives_[index] > 0){
            lives_[index]-=damage[j];
            if(lives_[index]<=0){
                quantity_--;
            }
            j++;
        }
        if(j>damage.size()){ break; }
    }
}

void Soldier::set_stats(){
    int size=12;
    lHp_.create(DEFAULT_FONT, 0, 0, "HP: " + std::to_string(hp_), size);
    dmg_.create(DEFAULT_FONT, 0, 0,"Damage: "+std::to_string(attack_), size);
    arm_.create(DEFAULT_FONT, 0, 0,"Armor: "+std::to_string(armor_), size);
}

void Soldier::update_timer(){
    auto elapsed=static_cast<int>(forUpgrade_.getElapsedTime().asSeconds());
    if(elapsed>=1 && timeLeft_>=1){
        //if at least second passes
        forUpgrade_.restart();
        timeLeft_-=elapsed;
        left_.setCaption(std::to_string((int)timeLeft_)+"s");
        left_.center();
        sf::sleep(sf::milliseconds(100));

        //increasing training time of one unit
        unitTime_+=elapsed;
        if(unitTime_==upgradeTime_){
            unitTime_=0;
            quantity_++;
            update_counter();
        }

        //when upgrade time ends
        if(timeLeft_<=0){
            inUpgrade_=false;
        }
    }
}

void Soldier::load_left(int time){
    unitTime_=time%upgradeTime_;
    if(time>0){
        timeLeft_=time;
        inUpgrade_=true;
        left_.setCaption(std::to_string((int)timeLeft_)+"s");
        left_.center();
        forUpgrade_.restart();
    }
}
