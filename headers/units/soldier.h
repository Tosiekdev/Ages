//
// Created by tosiek on 21.02.2022.
//

#ifndef AGES1_SOLDIER_H
#define AGES1_SOLDIER_H

#include <array>
#include <vector>
#include <SFML/Graphics.hpp>

#include "../battle.h"
#include "../ui/button.h"
#include "../ui/obstacle.h"
#include "../ui/label.h"

class Soldier{
protected:
    void set_stats();

public:
    Soldier();

    //battle
    virtual std::vector<int> give_damage(Type which, std::vector<int> old_damage);
    virtual void take_damage(std::vector<int> damage);
    virtual int attack_calculator(Type which)=0;

    //positioning
    virtual void set_position(sf::Vector2f pos);
    virtual sf::Vector2f get_position() { return view_.getPosition(); }
    virtual void slide(float shift);

    //upgrading
    virtual std::array<int,3> train(int people, int iron, int money);
    virtual void end_upgrade();
    virtual void reset_timer() { forUpgrade_.restart(); }
    virtual void get_time() { forUpgrade_.getElapsedTime().asSeconds(); }
    virtual void update_counter()=0;

    //saving&loading
    virtual float get_time_left() { return this->timeLeft_; }
    virtual void load_left(float time) { this->timeLeft_=time; }

    //interacting with buttons
    virtual bool animate_buttons(sf::Vector2i mouse_pos) {
        return upgrade_.onFocus(mouse_pos.x,mouse_pos.y);
    }

    virtual void show(sf::RenderWindow& window);

protected:
    int hp_{}, attack_{}, armor_{}, quantity_{}, nPeople_{}, nIron_{}, nMoney_{};

    std::vector<int> lives_;

    float upgradeTime_{}, timeLeft_{};
    bool inUpgrade_=false;
    sf::Clock forUpgrade_;

    sf::Sprite view_;
    sf::Texture texture_;

    //for showing stats
    sf::Sprite plank_;
    sf::Texture pTexture_;
    Label lHp_, dmg_, arm_;

    Obstacle name_;
    Button upgrade_;
    Label counter_;
};


#endif //AGES1_SOLDIER_H
