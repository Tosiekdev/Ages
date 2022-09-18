//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/buildings-windows/handletownhall.h"

void
HandleTownHall::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                       int *iron,
                       int *bld) {
    //for resource info_
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    this->resource_look();

    //info_
    this->crete_info();
    this->info_.setCaption("In Town Hall you can upgrade your buildings.\n"
                          "Upgrading Town Hall make upgrade's times shorter!");

    //buttons
    this->create_return_button();
}

void HandleTownHall::handle_events(sf::Event &event, sf::RenderWindow &window, int &scene){
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed) window.close();

        //tablets scrolling
        if(event.type==sf::Event::MouseWheelScrolled){
            //scrolling down
            if(event.mouseWheelScroll.delta<0){
                sf::Vector2f buf_pos;
                buf_pos=upgrBuildings_[9].Return_position();
                for(int i=9; i>0; i--){
                    this->upgrBuildings_[i].set_position(this->upgrBuildings_[i - 1].Return_position());
                }
                this->upgrBuildings_[0].set_position(buf_pos);
            }
            //scrolling up
            if(event.mouseWheelScroll.delta>0){
                sf::Vector2f buf_pos;
                buf_pos=upgrBuildings_[0].Return_position();
                for(int i=0; i<9; i++){
                    this->upgrBuildings_[i].set_position(this->upgrBuildings_[i + 1].Return_position());
                }
                this->upgrBuildings_[9].set_position(buf_pos);
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int i=sf::Mouse::getPosition(window).x;
            int j=sf::Mouse::getPosition(window).y;
            sf::Vector2i mouse_pos=sf::Mouse::getPosition(window);

            if(this->returnToGame_.onClick(i, j)){
                this->return_to_village(scene);
            }

            //upgrading buildings
            for(auto & u_building : upgrBuildings_){
                if(u_building.button_clicked(mouse_pos)){
                    u_building.upgrade_building(*human_,*rock_,*wood_,*building_);
                    lHuman_->setCaption("People: " + std::to_string(*human_));
                    lRock_->setCaption("Stone: " + std::to_string(*rock_));
                    lWood_->setCaption("Wood: " + std::to_string(*wood_));
                }
            }
        }
    }
}

void HandleTownHall::do_stuff(sf::RenderWindow &window){
    std::vector<bool> a;
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a.push_back(returnToGame_.onFocus(x, y));

    sf::Vector2i mouse_pos=sf::Mouse::getPosition(window);
    //upgrade box
    for(auto &i:upgrBuildings_)
        a.push_back(i.button_animation(mouse_pos));

    if(std::count(a.begin(),a.end(),true))
        this->cursor_.loadFromSystem(sf::Cursor::Hand);
    else
        this->cursor_.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(this->cursor_);
}

void HandleTownHall::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    this->returnToGame_.show(window);

    //resource info_
    this->show_resources(window);

    //labels
    for(auto &u_building:this->upgrBuildings_)
        u_building.show(window);

    //building_ info_
    this->info_.show(window);

    window.display();
}

void HandleTownHall::crete_ub(buildings *resp, sf::Vector2f pos, int index){
    this->upgrBuildings_[index].create_upgrade(resp, this->num_to_names[index + 1], pos);
}

void HandleTownHall::set_ub_left(int index, float time, float th){
    this->upgrBuildings_[index].set_left(time, th);
}

float HandleTownHall::get_ub_left(int index){
    return this->upgrBuildings_[index].get_left();
}

float HandleTownHall::ub_get_time(int index) {
    return this->upgrBuildings_[index].get_time();
}

void HandleTownHall::ub_reset_timer(int index){
    this->upgrBuildings_[index].reset_timer();
}

int HandleTownHall::ub_update_timer(int index, float time_passed) {
    return this->upgrBuildings_[index].update_timer(time_passed);
}

void HandleTownHall::ub_update_level(int index){
    this->upgrBuildings_[index].update_level();
}
