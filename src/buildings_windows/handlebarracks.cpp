//
// Created by tosiek on 16.02.2022.
//

#include "../../headers/handlebarracks.h"

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
    swordsMen_.set_position(sf::Vector2f(52,250));
    spearman_.set_position(sf::Vector2f(169,250));
    archer_.set_position(sf::Vector2f(286,250));
    heavyCavalry_.set_position(sf::Vector2f(403,250));
    lightCavalry_.set_position(sf::Vector2f(520,250));
    knight_.set_position(sf::Vector2f(637,250));
    crossbowman_.set_position(sf::Vector2f(871,250));

    //buttons
    this->create_return_button();

    //slide buttons
    slideLeft_.create_element("Textures/l_slide.png", sf::Vector2f(5, 275));
    slideRight_.create_element("Textures/r_slide.png", sf::Vector2f(755, 275));
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

            if(slideLeft_.onClick(i, j)){
               slide_to_left();
            }

            if(slideRight_.onClick(i, j)){
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

    anim.push_back(swordsMen_.animate_buttons(m_pos));
    anim.push_back(spearman_.animate_buttons(m_pos));
    anim.push_back(archer_.animate_buttons(m_pos));
    anim.push_back(heavyCavalry_.animate_buttons(m_pos));
    anim.push_back(lightCavalry_.animate_buttons(m_pos));
    anim.push_back(knight_.animate_buttons(m_pos));
    anim.push_back(crossbowman_.animate_buttons(m_pos));

    anim.push_back(slideLeft_.onFocus(x, y));
    if(swordsMen_.get_position().x<52){ anim.push_back(slideRight_.onFocus(x, y)); }

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
    swordsMen_.show(window);
    spearman_.show(window);
    archer_.show(window);
    heavyCavalry_.show(window);
    lightCavalry_.show(window);
    knight_.show(window);
    crossbowman_.show(window);

    //building_ info
    info.show(window);

    //sliders
    slideLeft_.draw_it(window);
    slideRight_.draw_it(window);

    window.display();
}

void HandleBarracks::slide_to_left(){
    left_slider(swordsMen_);
    left_slider(spearman_);
    left_slider(archer_);
    left_slider(heavyCavalry_);
    left_slider(lightCavalry_);
    left_slider(knight_);
    left_slider(crossbowman_);
}

void HandleBarracks::slide_to_right(){
    if(swordsMen_.get_position().x<52){
        right_slider(swordsMen_);
        right_slider(spearman_);
        right_slider(archer_);
        right_slider(heavyCavalry_);
        right_slider(lightCavalry_);
        right_slider(knight_);
        right_slider(crossbowman_);
    }
}

template<class T>
void HandleBarracks::left_slider(T &card){
    card.slide(-SLIDE);
    if(card.get_position().x<52 || card.get_position().x>637){
        card.slide(-SLIDE);
    }
}

template<class T>
void HandleBarracks::right_slider(T& card){
    card.slide(SLIDE);
    if(card.get_position().x<52 || card.get_position().x>637){
        card.slide(SLIDE);
    }
}
