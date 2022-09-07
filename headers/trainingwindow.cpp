//
// Created by tosiek on 07.09.22.
//

#include "trainingwindow.h"

void TrainingWindow::create(int nMoney, int nPeople, int nIron, int upgTime, std::string unitName){
    //creating info-window
    window_.create(sf::VideoMode(300,450),"");

    //creating info to show in upgrade window
    sure_.create(DEFAULT_FONT, 10, 10, "", 20);

    std::string firstLine="Required money: "+std::to_string(nMoney)+"/n";
    std::string secondLine="Required people: "+std::to_string(nPeople)+"/n";
    std::string thirdLine="Required iron: "+std::to_string(nIron)+"/n";
    std::string fourthLine="Upgrade time: "+std::to_string(upgTime)+"/n";
    std::string sureCaption=firstLine+secondLine+thirdLine+fourthLine;
    sure_.setCaption(sureCaption);
}

bool TrainingWindow::handle_event(sf::RenderWindow &window) {
    return false;
}

void TrainingWindow::main_loop(sf::RenderWindow &window, int &scene) {

}

void TrainingWindow::display(sf::RenderWindow &window){

}
