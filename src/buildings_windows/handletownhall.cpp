//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/buildings-windows/handletownhall.h"

void HandleTownHall::create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //for resource info
    this->assign_values(lh,lr,lw,hn,rk,wd,bld);

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
            if(event.mouseWheelScroll.delta<0){
                sf::Vector2f buf_pos;
                buf_pos=u_buildings[7].Return_position();
                for(int i=7; i>0; i--){
                    this->u_buildings[i].set_position(this->u_buildings[i-1].Return_position());
                }
                this->u_buildings[0].set_position(buf_pos);
            }
            if(event.mouseWheelScroll.delta>0){
                sf::Vector2f buf_pos;
                buf_pos=u_buildings[0].Return_position();
                for(int i=0; i<7; i++){
                    this->u_buildings[i].set_position(this->u_buildings[i+1].Return_position());
                }
                this->u_buildings[7].set_position(buf_pos);
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
            for(int a=0; a<8; a++){
                if(this->u_buildings[a].button_clicked(mouse_pos)){
                    this->u_buildings[a].upgrade_building(*this->human,*this->rock,*this->wood,*this->building);
                    this->l_human->setCaption("People: "+std::to_string(*this->human));
                    this->l_rock->setCaption("Stone: "+std::to_string(*this->rock));
                    this->l_wood->setCaption("Wood: "+std::to_string(*this->wood));
                }
            }
        }
    }
}

void HandleTownHall::do_stuff(sf::RenderWindow &window){
    bool a[9];
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a[0]=this->return_to_game.onFocus(x,y);

    sf::Vector2i mouse_pos=sf::Mouse::getPosition(window);
    //upgrade box
    for(int i=0; i<8; i++)
        a[i+1]=this->u_buildings[i].button_animation(mouse_pos);

    if(a[0] || a[1] || a[2] || a[3] || a[4] || a[5] || a[6] || a[7] || a[8])
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
