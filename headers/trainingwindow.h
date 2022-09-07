//
// Created by tosiek on 07.09.22.
//

#ifndef AGES1_TRAININGWINDOW_H
#define AGES1_TRAININGWINDOW_H

#include "ui/label.h"
#include "ui/button.h"

class TrainingWindow {
public:
    void create(int nMoney, int nPeople, int nIron, int upgTime, const std::string& unitName,sf::RenderWindow &W);
    void main_loop();
    void handle_event();
    void display();

private:
    sf::RenderWindow window_;
    Label sure_;
    sf::Event event_;
    sf::Cursor cursor_;
};


#endif //AGES1_TRAININGWINDOW_H
