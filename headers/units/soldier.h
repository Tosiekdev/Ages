//
// Created by tosiek on 21.02.2022.
//

#ifndef AGES1_SOLDIER_H
#define AGES1_SOLDIER_H

#include <iostream>
#include <array>
#include <vector>
#include <SFML/Graphics.hpp>

#include "../battle.h"
#include "../ui/button.h"
#include "../ui/obstacle.h"
#include "../ui/label.h"

#include "../trainingwindow.h"

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
    virtual std::array<int, 3> train(int people, int iron, int money, int count);
    virtual void end_upgrade();
    virtual void reset_timer() { forUpgrade_.restart(); }
    virtual void get_time() { forUpgrade_.getElapsedTime().asSeconds(); }
    virtual void update_timer();
    virtual void update_counter()=0;
    virtual int launch_window(sf::RenderWindow &window)=0;

    //saving&loading
    virtual int get_time_left() { return timeLeft_; }
    virtual void load_left(int time);
    /**
     * Quantity getter.
     * @return Returns unit's quantity.
     */
    virtual int get_quantity() const { return quantity_; }
    /**
     * Quantity setter.
     * @param count New quantity.
     */
    virtual void set_quantity(int count);

    //interacting with buttons
    virtual bool animate_buttons(sf::Vector2i mouse_pos) {
        return upgrade_.onFocus(mouse_pos.x,mouse_pos.y);
    }
    virtual bool train_click(sf::Vector2i mouse_pos){ return upgrade_.onClick(mouse_pos.x,mouse_pos.y); }

    virtual void show(sf::RenderWindow& window);

protected:
    int hp_{}, attack_{}, armor_{}, quantity_{}, nPeople_{}, nIron_{}, nMoney_{};

    std::vector<int> lives_;

    int upgradeTime_{}, timeLeft_{}, unitTime_{};
    bool inUpgrade_=false;
    sf::Clock forUpgrade_;
    Label left_;
    TrainingWindow window1_;

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
