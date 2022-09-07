//
// Created by tosiek on 07.09.22.
//

#ifndef AGES1_TRAININGWINDOW_H
#define AGES1_TRAININGWINDOW_H

#include "handlewindow.h"
#include "ui/label.h"
#include "ui/button.h"

class TrainingWindow : public HandleWindow {
public:
    void create(int nMoney, int nPeople, int nIron, int upgTime, std::string unitName);
    void main_loop(sf::RenderWindow &window, int &scene) override;
    bool handle_event(sf::RenderWindow &window);
    void display(sf::RenderWindow &window) override;

private:
    sf::RenderWindow window_;
    Label sure_;
    sf::Event exit_e;
    Button yes,no;
    sf::Cursor cursor;
};


#endif //AGES1_TRAININGWINDOW_H
