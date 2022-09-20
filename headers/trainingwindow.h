//
// Created by tosiek on 07.09.22.
//

#ifndef AGES1_TRAININGWINDOW_H
#define AGES1_TRAININGWINDOW_H

#include <vector>
#include <algorithm>

#include "ui/label.h"
#include "ui/button.h"
#include "ui/clickable.h"

class TrainingWindow {
public:
    /**
     * Creates training window.
     * @param nMoney Amount of money needed to train unit.
     * @param nPeople Amount of people needed to train unit.
     * @param nIron Amount of iron needed to train unit.
     * @param upgTime Amount of time needed to train unit.
     * @param unitName Name of trained unit.
     * @param W Game window.
     * @param count variable to storage number of unit we want to train.
     */
    void create(int nMoney, int nPeople, int nIron, int upgTime, const std::string &unitName, sf::RenderWindow &W,
                int &count);
    /**
     * Main loop of training window.
     * @param count variable to storage number of unit we want to train.
     */
    void main_loop(int &count);
    /**
     * Function responsible for handling events in training window.
     * @param count variable to storage number of unit we want to train.
     */
    void handle_event(int &count);
    /**
     * Function responsible for doing stuff for every frame.
     */
    void do_stuff();
    /**
     * Function responsible for displaying training window content.
     */
    void display();

private:
    sf::RenderWindow window_;
    sf::Event event_;
    sf::Cursor cursor_;

    Label sure_,count_,counter_;
    Clickable plus_,minus_;
    Button train_,cancel_;

    int money_,people_,iron_,time_;
    int quantity_=1;

    /**
     * Sets captions to labels in training window.
     */
    void set_captions();
};


#endif //AGES1_TRAININGWINDOW_H
