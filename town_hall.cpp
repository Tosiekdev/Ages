//
// Created by tosiek on 31.12.2021.
//

#include "needed.h"

using namespace sf;

//set up everything
void Application::create_townhall(){
    this->th_return_to_game.create(40,100,5,5,"Return");

    //buildings label inicialized in game.cpp

    //changing resource info position
    this->l_human.setPosition(Vector2f(200,5));
    this->l_rock.setPosition(Vector2f(400,5));
    this->l_wood.setPosition(Vector2f(600,5));

    //changing resource info text
    this->l_human.setCaption("People: "+to_string(this->human));
    this->l_rock.setCaption("Stone: "+to_string(this->rock));
    this->l_wood.setCaption("Wood: "+to_string(this->wood));

    //info label
    this->th_info.create(DEFAULT_FONT,10,100,"",30);
    this->th_info.setCaption("In Town Hall you can upgrade your buildings.\n"
                             "Upgrading Town Hall make upgrade's times shorter!");
}

//main loop
void Application::townhall(){
    //handle event
    this->th_handle_event();

    //do some stuff
    this->th_stuff();

    //draw everything
    this->display_townhall();
}

//event handling
void Application::th_handle_event(){
    while(this->screen.pollEvent(this->e)){
        //closing
        if(this->e.type==Event::Closed) this->screen.close();

        //tablets scrolling
        if(this->e.type==Event::MouseWheelScrolled){
            if(this->e.mouseWheelScroll.delta<0){
                Vector2f buf_pos;
                buf_pos=u_buildings[7].Return_position();
                for(int i=7; i>0; i--){
                    this->u_buildings[i].set_position(this->u_buildings[i-1].Return_position());
                }
                this->u_buildings[0].set_position(buf_pos);
            }
            if(this->e.mouseWheelScroll.delta>0){
                Vector2f buf_pos;
                buf_pos=u_buildings[0].Return_position();
                for(int i=0; i<7; i++){
                    this->u_buildings[i].set_position(this->u_buildings[i+1].Return_position());
                }
                this->u_buildings[7].set_position(buf_pos);
            }
        }

        //when you click on screen
        if(Mouse::isButtonPressed(Mouse::Left)){
            //getting mouse position
            int a=Mouse::getPosition(this->screen).x;
            int b=Mouse::getPosition(this->screen).y;
            Vector2i mouse_pos=Mouse::getPosition(this->screen);

            //button clicked
            if(this->th_return_to_game.onClick(a,b)){
                //default resource info position
                this->l_human.setPosition(Vector2f(620,5));
                this->l_rock.setPosition(Vector2f(620,50));
                this->l_wood.setPosition(Vector2f(620,95));

                //default resource info text
                this->l_human.setCaption(to_string(this->human));
                this->l_rock.setCaption(to_string(this->rock));
                this->l_wood.setCaption(to_string(this->wood));

                this->scene=4;
            }

            //upgrading buildings
            for(int i=0; i<8; i++){
                if(this->u_buildings[i].button_clicked(mouse_pos)){
                    this->u_buildings[i].upgrade_building(this->human,this->rock,this->wood,this->town_hall);
                    this->l_human.setCaption("People: "+to_string(this->human));
                    this->l_rock.setCaption("Stone: "+to_string(this->rock));
                    this->l_wood.setCaption("Wood: "+to_string(this->wood));
                }
            }
        }
    }
}

//every frame backend
void Application::th_stuff() {
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    //cool animation
    this->th_return_to_game.onFocus(x,y);
    Vector2i mouse_pos=Mouse::getPosition(this->screen);

    //upgrade box
    for(int i=0; i<8; i++)
        this->u_buildings[i].button_animation(mouse_pos);

    //increasing resources is handled by thread
}

//drawing everything
void Application::display_townhall() {
    this->screen.clear(Color::White);

    //buttons
    this->th_return_to_game.show(this->screen);

    //info
    this->th_info.show(this->screen);

    //labels
    for(auto &u_building:this->u_buildings)
        u_building.show(this->screen);

    //your resources
    this->l_human.show(this->screen);
    this->l_rock.show(this->screen);
    this->l_wood.show(this->screen);

    this->screen.display();
}
