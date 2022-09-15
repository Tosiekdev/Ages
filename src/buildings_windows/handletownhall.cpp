//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/buildings-windows/handletownhall.h"

void
HandleTownHall::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                       int *iron,
                       int *bld) {
    //for resource info
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    this->resource_look();

    //info
    this->crete_info();
    this->info.setCaption("In Town Hall you can upgrade your buildings.\n"
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
                buf_pos=u_buildings[9].Return_position();
                for(int i=9; i>0; i--){
                    this->u_buildings[i].set_position(this->u_buildings[i-1].Return_position());
                }
                this->u_buildings[0].set_position(buf_pos);
            }
            //scrolling up
            if(event.mouseWheelScroll.delta>0){
                sf::Vector2f buf_pos;
                buf_pos=u_buildings[0].Return_position();
                for(int i=0; i<9; i++){
                    this->u_buildings[i].set_position(this->u_buildings[i+1].Return_position());
                }
                this->u_buildings[9].set_position(buf_pos);
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int i=sf::Mouse::getPosition(window).x;
            int j=sf::Mouse::getPosition(window).y;
            sf::Vector2i mouse_pos=sf::Mouse::getPosition(window);

            if(this->return_to_game.onClick(i,j)){
                this->return_to_village(scene);
            }

            //upgrading buildings
            for(auto & u_building : this->u_buildings){
                if(u_building.button_clicked(mouse_pos)){
                    u_building.upgrade_building(*this->human_, *this->rock_, *this->wood_, *this->building_);
                    this->lHuman_->setCaption("People: " + std::to_string(*this->human_));
                    this->lRock_->setCaption("Stone: " + std::to_string(*this->rock_));
                    this->lWood_->setCaption("Wood: " + std::to_string(*this->wood_));
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
    a.push_back(return_to_game.onFocus(x,y));

    sf::Vector2i mouse_pos=sf::Mouse::getPosition(window);
    //upgrade box
    for(auto &i:u_buildings)
        a.push_back(i.button_animation(mouse_pos));

    if(std::count(a.begin(),a.end(),true))
        this->cursor.loadFromSystem(sf::Cursor::Hand);
    else
        this->cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(this->cursor);
}

void HandleTownHall::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    this->return_to_game.show(window);

    //resource info
    this->show_resources(window);

    //labels
    for(auto &u_building:this->u_buildings)
        u_building.show(window);

    //building_ info
    this->info.show(window);

    window.display();
}

void HandleTownHall::crete_ub(buildings *resp, sf::Vector2f pos, int index){
    this->u_buildings[index].create_upgrade(resp,this->num_to_names[index+1],pos);
}

void HandleTownHall::set_ub_left(int index, float time, float th){
    this->u_buildings[index].set_left(time,th);
}

float HandleTownHall::get_ub_left(int index){
    return this->u_buildings[index].get_left();
}

float HandleTownHall::ub_get_time(int index) {
    return this->u_buildings[index].get_time();
}

void HandleTownHall::ub_reset_timer(int index){
    this->u_buildings[index].reset_timer();
}

int HandleTownHall::ub_update_timer(int index, float time_passed) {
    return this->u_buildings[index].update_timer(time_passed);
}

void HandleTownHall::ub_update_level(int index){
    this->u_buildings[index].update_level();
}
