//
// Created by tosiek on 16.02.2022.
//

#include "../../headers/buildings-windows/handlebarracks.h"

#define SLIDE 117

void
HandleBarracks::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                       int *iron,
                       int *bld) {
    //for resource info_
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    resource_look();

    //info_
    crete_info();
    info_.setCaption("In Barracks you train your soldiers to make your army\n"
                          "bigger and stronger!\n"
                          "Upgrading Barracks allows you to train better units!");

    //for training units
    swordsman_.set_position(sf::Vector2f(52, 250));
    spearman_.set_position(sf::Vector2f(169,250));
    archer_.set_position(sf::Vector2f(286,250));
    heavyCavalry_.set_position(sf::Vector2f(403,250));
    lightCavalry_.set_position(sf::Vector2f(520,250));
    knight_.set_position(sf::Vector2f(637,250));
    crossbowman_.set_position(sf::Vector2f(871,250));
    billman_.set_position(sf::Vector2f(1105,250));
    axeman_.set_position(sf::Vector2f(1339,250));

    //buttons
    create_return_button();

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
            auto pos=sf::Mouse::getPosition(window);

            if(returnToGame_.onClick(i, j)){
                return_to_village(scene);
            }

            if(slideLeft_.onClick(i, j)){
               slide_to_left();
            }

            if(slideRight_.onClick(i, j)){
                slide_to_right();
            }

            launch_windows(pos,window);
        }
    }
}

void HandleBarracks::do_stuff(sf::RenderWindow &window){
    std::vector<bool> anim;
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;
    sf::Vector2i m_pos=sf::Mouse::getPosition(window);

    //cool animation
    anim.push_back(returnToGame_.onFocus(x, y));

    //animating train button at every unit
    anim.push_back(swordsman_.animate_buttons(m_pos));
    anim.push_back(spearman_.animate_buttons(m_pos));
    anim.push_back(archer_.animate_buttons(m_pos));
    anim.push_back(heavyCavalry_.animate_buttons(m_pos));
    anim.push_back(lightCavalry_.animate_buttons(m_pos));
    anim.push_back(knight_.animate_buttons(m_pos));
    anim.push_back(crossbowman_.animate_buttons(m_pos));
    anim.push_back(billman_.animate_buttons(m_pos));
    anim.push_back(axeman_.animate_buttons(m_pos));

    if(axeman_.get_position().x>637){ anim.push_back(slideLeft_.onFocus(x, y)); }
    if(swordsman_.get_position().x<52){ anim.push_back(slideRight_.onFocus(x, y)); }

    //changing cursor_
    if(std::count(anim.begin(),anim.end(),true))
        cursor_.loadFromSystem(sf::Cursor::Hand);
    else
        cursor_.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor_);
}

void HandleBarracks::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    returnToGame_.show(window);

    //resource info_
    show_resources(window);

    //units training
    swordsman_.show(window);
    spearman_.show(window);
    archer_.show(window);
    heavyCavalry_.show(window);
    lightCavalry_.show(window);
    knight_.show(window);
    crossbowman_.show(window);
    billman_.show(window);
    axeman_.show(window);

    //building_ info_
    info_.show(window);

    //sliders
    slideLeft_.draw_it(window);
    slideRight_.draw_it(window);

    window.display();
}

void HandleBarracks::slide_to_left(){
    if(axeman_.get_position().x>637){
        left_slider(swordsman_);
        left_slider(spearman_);
        left_slider(archer_);
        left_slider(heavyCavalry_);
        left_slider(lightCavalry_);
        left_slider(knight_);
        left_slider(crossbowman_);
        left_slider(billman_);
        left_slider(axeman_);
    }
}

void HandleBarracks::slide_to_right(){
    if(swordsman_.get_position().x<52){
        right_slider(swordsman_);
        right_slider(spearman_);
        right_slider(archer_);
        right_slider(heavyCavalry_);
        right_slider(lightCavalry_);
        right_slider(knight_);
        right_slider(crossbowman_);
        right_slider(billman_);
        right_slider(axeman_);
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

void HandleBarracks::launch_windows(sf::Vector2i mPos, sf::RenderWindow& window){
    launch_single(mPos,window,swordsman_);
    launch_single(mPos,window,spearman_);
    launch_single(mPos,window,archer_);
    launch_single(mPos,window,heavyCavalry_);
    launch_single(mPos,window,lightCavalry_);
    launch_single(mPos,window,knight_);
    launch_single(mPos,window,crossbowman_);
    launch_single(mPos,window,billman_);
    launch_single(mPos,window,axeman_);
}

template<class T>
void HandleBarracks::launch_single(sf::Vector2i mPos, sf::RenderWindow &window, T& unit){
    if(unit.train_click(mPos)){
        int unitCount=unit.launch_window(window);
        if(unitCount){
            //stuff to do if player wants to train some units
            std::array<int,3> newResources=unit.train(*human_,*iron_,*money_,unitCount);
            //assigning new
            int h=newResources[0];
            *human_=h;
            int i=newResources[1];
            *iron_=i;
            int m=newResources[2];
            *money_=m;
        }
    }
}

void HandleBarracks::update_timer(){
    archer_.update_timer();
    axeman_.update_timer();
    billman_.update_timer();
    crossbowman_.update_timer();
    heavyCavalry_.update_timer();
    knight_.update_timer();
    lightCavalry_.update_timer();
    spearman_.update_timer();
    swordsman_.update_timer();
}

void HandleBarracks::set_remaining_time(std::vector<int> time){
    archer_.load_left(time[0]);
    axeman_.load_left(time[1]);
    billman_.load_left(time[2]);
    crossbowman_.load_left(time[3]);
    heavyCavalry_.load_left(time[4]);
    knight_.load_left(time[5]);
    lightCavalry_.load_left(time[6]);
    spearman_.load_left(time[7]);
    swordsman_.load_left(time[8]);
}

std::vector<int> HandleBarracks::get_remaining_time() {
    std::vector<int> times;
    times.push_back(archer_.get_time_left());
    times.push_back(axeman_.get_time_left());
    times.push_back(billman_.get_time_left());
    times.push_back(crossbowman_.get_time_left());
    times.push_back(heavyCavalry_.get_time_left());
    times.push_back(knight_.get_time_left());
    times.push_back(lightCavalry_.get_time_left());
    times.push_back(spearman_.get_time_left());
    times.push_back(swordsman_.get_time_left());
    return times;
}

std::vector<int> HandleBarracks::get_units_quantity() {
    std::vector<int> quantity;
    quantity.push_back(archer_.get_quantity());
    quantity.push_back(axeman_.get_quantity());
    quantity.push_back(billman_.get_quantity());
    quantity.push_back(crossbowman_.get_quantity());
    quantity.push_back(heavyCavalry_.get_quantity());
    quantity.push_back(knight_.get_quantity());
    quantity.push_back(lightCavalry_.get_quantity());
    quantity.push_back(spearman_.get_quantity());
    quantity.push_back(swordsman_.get_quantity());
    return quantity;
}

void HandleBarracks::set_units_quantity(std::array<int, 9> count){
    archer_.set_quantity(count[0]);
    axeman_.set_quantity(count[1]);
    billman_.set_quantity(count[2]);
    crossbowman_.set_quantity(count[3]);
    heavyCavalry_.set_quantity(count[4]);
    knight_.set_quantity(count[5]);
    lightCavalry_.set_quantity(count[6]);
    spearman_.set_quantity(count[7]);
    swordsman_.set_quantity(count[8]);
}
