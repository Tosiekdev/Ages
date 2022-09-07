//
// Created by tosiek on 07.09.22.
//

#include "../headers/trainingwindow.h"

void TrainingWindow::create(int nMoney, int nPeople, int nIron, int upgTime, const std::string& unitName,sf::RenderWindow &W){
    //creating info-window
    //auto mode=sf::VideoMode(300,450);
    window_.create(sf::VideoMode(300,450),"Train "+unitName,sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i windowPos=W.getPosition()+sf::Vector2i(250,75);
    window_.setPosition(windowPos);

    //creating info to show in upgrade window
    sure_.create(DEFAULT_FONT, 150, 100, "", 30);

    std::string firstLine="Required money: "+std::to_string(nMoney)+"\n";
    std::string secondLine="Required people: "+std::to_string(nPeople)+"\n";
    std::string thirdLine="Required iron: "+std::to_string(nIron)+"\n";
    std::string fourthLine="Upgrade time: "+std::to_string(upgTime)+"\n";
    std::string sureCaption=firstLine+secondLine+thirdLine+fourthLine;
    sure_.setCaption(sureCaption);
    sure_.center();

    //starting window
    main_loop();
}

void TrainingWindow::handle_event(){
    while(window_.pollEvent(event_)){
        if(event_.type==sf::Event::Closed){
            window_.close();
        }
    }
}

void TrainingWindow::main_loop() {
    while(window_.isOpen()){
        handle_event();
        display();
    }
}

void TrainingWindow::display() {
    window_.clear(sf::Color::White);

    sure_.show(window_);

    window_.display();
}
