//
// Created by tosiek on 07.09.22.
//

#include "../headers/trainingwindow.h"

#include <iostream>

void TrainingWindow::create(int nMoney, int nPeople, int nIron, int upgTime, const std::string &unitName,
                            sf::RenderWindow &W, int &count) {
    //assigning resources
    money_=nMoney;
    people_=nPeople;
    iron_=nIron;
    time_=upgTime;

    //creating info_-window
    sf::VideoMode mode=sf::VideoMode(450,300);
    window_.create(mode,"Train "+unitName,sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i windowPos=W.getPosition()+sf::Vector2i(175,150);
    window_.setPosition(windowPos);

    //creating info to show in upgrade window
    sure_.create(DEFAULT_FONT,225,100,"",30);

    //info about quantity of units to train
    count_.create(DEFAULT_FONT,90,155,"Quantity",30);
    counter_.create(DEFAULT_FONT,300,163,"1",30);
    counter_.center();
    plus_.create_element("Textures/plus.png",sf::Vector2f(320,155));
    minus_.create_element("Textures/minus.png",sf::Vector2f(250,155));

    //info which is changed relatively to the quantity
    set_captions();

    //buttons to decide if train or not
    train_.create(40,100,85,205,"Train");
    cancel_.create(40,100,245,205,"Cancel");

    //starting window
    main_loop(count);
}

void TrainingWindow::handle_event(int &count) {
    while(window_.pollEvent(event_)){
        if(event_.type==sf::Event::Closed){
            window_.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mPos=sf::Mouse::getPosition(window_);
            int mPosX=mPos.x;
            int mPosY=mPos.y;

            if(plus_.onClick(mPosX,mPosY)){
                quantity_++;
                set_captions();
            }

            if(minus_.onClick(mPosX,mPosY)){
                if(quantity_>=2){
                    quantity_--;
                    set_captions();
                }
            }

            if(train_.onClick(mPosX,mPosY)){
                window_.close();
                count=quantity_;
                quantity_=1;
            }

            if(cancel_.onClick(mPosX,mPosY)){
                window_.close();
                quantity_=1;
                count=0;
            }
        }
    }
}

void TrainingWindow::main_loop(int &count) {
    while(window_.isOpen()){
        handle_event(count);
        do_stuff();
        display();
    }
}

void TrainingWindow::display() {
    window_.clear(sf::Color::White);

    sure_.show(window_);

    //quantity
    count_.show(window_);
    counter_.show(window_);
    plus_.draw_it(window_);
    minus_.draw_it(window_);

    //buttons
    train_.show(window_);
    cancel_.show(window_);

    window_.display();
}

void TrainingWindow::do_stuff(){
    auto mPos=sf::Mouse::getPosition(window_);
    int mPosX=mPos.x;
    int mPosY=mPos.y;

    std::vector<bool> focused;

    //animate icons increasing amount of units to train
    focused.push_back(plus_.onFocus(mPosX,mPosY));
    focused.push_back(minus_.onFocus(mPosX,mPosY));

    //animate buttons
    focused.push_back(train_.onFocus(mPosX,mPosY));
    focused.push_back(cancel_.onFocus(mPosX,mPosY));

    //setting elegant mouse cursor
    if(std::count(focused.begin(),focused.end(),true)){
        cursor_.loadFromSystem(sf::Cursor::Hand);
    }else{
        cursor_.loadFromSystem(sf::Cursor::Arrow);
    }
    window_.setMouseCursor(cursor_);
}

void TrainingWindow::set_captions(){
    counter_.setCaption(std::to_string(quantity_));
    counter_.center();

    std::string firstLine="Required money: "+std::to_string(quantity_*money_)+"\n";
    std::string secondLine="Required people: "+std::to_string(quantity_*people_)+"\n";
    std::string thirdLine="Required iron: "+std::to_string(quantity_*iron_)+"\n";
    std::string fourthLine="Upgrade time: "+std::to_string(quantity_*time_)+"\n";
    std::string sureCaption=firstLine+secondLine+thirdLine+fourthLine;
    sure_.setCaption(sureCaption);
    sure_.center();
}
