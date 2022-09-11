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
    void create(int nMoney, int nPeople, int nIron, int upgTime, const std::string& unitName,sf::RenderWindow &W);
    void main_loop();
    void handle_event();
    void do_stuff();
    void display();

private:
    sf::RenderWindow window_;
    sf::Event event_;
    sf::Cursor cursor_;

    Label sure_,count_,counter_;
    Clickable plus_,minus_;

    int money_,people_,iron_,time_;
    int quantity_=1;

    void set_captions();
};


#endif //AGES1_TRAININGWINDOW_H
