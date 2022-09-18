//
// Created by tosiek on 07.09.22.
//

#include "../headers/trainingwindow.h"

void TrainingWindow::create(int nMoney,int nPeople,int nIron,int upgTime,const std::string& unitName,sf::RenderWindow &W){
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

    //creating info_ to show in upgrade window
    sure_.create(DEFAULT_FONT,225,100,"",30);

    //info_ about quantity of units to train
    count_.create(DEFAULT_FONT,90,155,"Quantity",30);
    counter_.create(DEFAULT_FONT,300,163,"1",30);
    counter_.center();
    plus_.create_element("Textures/plus.png",sf::Vector2f(320,155));
    minus_.create_element("Textures/minus.png",sf::Vector2f(250,155));

    //info_ which is changed relatively to the quantity
    set_captions();

    //starting window
    main_loop();
}

void TrainingWindow::handle_event(){
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
        }
    }
}

void TrainingWindow::main_loop() {
    while(window_.isOpen()){
        handle_event();
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

    window_.display();
}

void TrainingWindow::do_stuff(){
    auto mPos=sf::Mouse::getPosition(window_);
    int mPosX=mPos.x;
    int mPosY=mPos.y;

    std::vector<bool> focused;

    focused.push_back(plus_.onFocus(mPosX,mPosY));
    focused.push_back(minus_.onFocus(mPosX,mPosY));

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
    std::string thirdLine="Required iron: "+std::to_string(quantity_*people_)+"\n";
    std::string fourthLine="Upgrade time: "+std::to_string(quantity_*time_)+"\n";
    std::string sureCaption=firstLine+secondLine+thirdLine+fourthLine;
    sure_.setCaption(sureCaption);
    sure_.center();
}
