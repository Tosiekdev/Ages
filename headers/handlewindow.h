//
// Created by tosiek on 09.02.2022.
//

#ifndef AGES1_HANDLEWINDOW_H
#define AGES1_HANDLEWINDOW_H

#include <SFML/Graphics.hpp>

class HandleWindow{
public:
    virtual void main_loop(sf::RenderWindow &window, int &scene){
        handle_event(scene,window);
        do_stuff(window);
        display(window);
    }
    virtual void handle_event(int &scene, sf::RenderWindow &window)=0;
    virtual void do_stuff(sf::RenderWindow &window)=0;
    virtual void display(sf::RenderWindow &window)=0;

protected:
    sf::Event event_{};
};

#endif //AGES1_HANDLEWINDOW_H
