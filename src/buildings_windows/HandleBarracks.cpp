//
// Created by tosiek on 16.02.2022.
//

#include "../../headers/HandleBarracks.h"

#define SLIDE 117

void HandleBarracks::create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //for resource info
    assign_values(lh,lr,lw,hn,rk,wd,bld);

    //change resource _look
    resource_look();

    //info
    crete_info();
    info.setCaption("In Barracks you train your soldiers to make your army\n"
                          "bigger and stronger!\n"
                          "Upgrading Barracks allows you to train better units!");

    //for training units
    swordsMen.set_position(sf::Vector2f(52,250));
    spearman.set_position(sf::Vector2f(169,250));

    //buttons
    this->create_return_button();

    //slide buttons
    slide_left.create_element("Textures/l_slide.png",sf::Vector2f(5,275));
    slide_right.create_element("Textures/r_slide.png",sf::Vector2f(755,275));
}

void HandleBarracks::handle_events(sf::Event &event, sf::RenderWindow &window, int &scene){
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed) window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int i=sf::Mouse::getPosition(window).x;
            int j=sf::Mouse::getPosition(window).y;

            if(return_to_game.onClick(i,j)){
                return_to_village(scene);
            }

            if(slide_left.onClick(i,j)){
               slide_to_left();
            }

            if(slide_right.onClick(i,j)){
                slide_to_right();
            }
        }
    }
}

void HandleBarracks::do_stuff(sf::RenderWindow &window){
    std::vector<bool> anim;
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;
    sf::Vector2i m_pos=sf::Mouse::getPosition(window);

    //cool animation
    anim.push_back(return_to_game.onFocus(x,y));
    anim.push_back(swordsMen.animate_buttons(m_pos));
    anim.push_back(spearman.animate_buttons(m_pos));
    anim.push_back(slide_left.onFocus(x,y));
    anim.push_back(slide_right.onFocus(x,y));

    //changing cursor_
    if(std::count(anim.begin(),anim.end(),true))
        cursor.loadFromSystem(sf::Cursor::Hand);
    else
        cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor);
}

void HandleBarracks::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    return_to_game.show(window);

    //resource info
    show_resources(window);

    //units training
    swordsMen.show(window);
    spearman.show(window);

    //building info
    info.show(window);

    //sliders
    slide_left.draw_it(window);
    slide_right.draw_it(window);

    window.display();
}

void HandleBarracks::slide_to_left(){
    swordsMen.slide(-SLIDE);
    if(swordsMen.get_position().x<52){
        swordsMen.slide(-SLIDE);
    }
    if(swordsMen.get_position().x>638){
        swordsMen.slide(-SLIDE);
    }

    spearman.slide(-SLIDE);
    if(spearman.get_position().x<52){
        spearman.slide(-SLIDE);
    }
    if(spearman.get_position().x>638){
        spearman.slide(-SLIDE);
    }
}

void HandleBarracks::slide_to_right(){
    swordsMen.slide(SLIDE);
    if(swordsMen.get_position().x<52){
        swordsMen.slide(SLIDE);
    }
    if(swordsMen.get_position().x>638){
        swordsMen.slide(SLIDE);
    }

    spearman.slide(SLIDE);
    if(spearman.get_position().x<52){
        spearman.slide(SLIDE);
    }
    if(spearman.get_position().x>638){
        spearman.slide(SLIDE);
    }
}
