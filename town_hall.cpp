//
// Created by tosiek on 31.12.2021.
//

#include "needed.h"

using namespace sf;

//set up everything
void Application::create_townhall(){
    this->create_return_button();

    //buildings label inicialized in game.cpp

    //changing resource info look
    this->resources_1();

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
            this->return_button_clicked(a,b);

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
void Application::th_stuff(){
    bool a[9];
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    //cool animation
    a[8]=this->return_button_focused(x,y);
    Vector2i mouse_pos=Mouse::getPosition(this->screen);

    //upgrade box
    for(int i=0; i<8; i++)
        a[i]=this->u_buildings[i].button_animation(mouse_pos);

    //increasing resources is handled by thread

    //cursor
    if(a[0] || a[1] || a[2] || a[3] || a[4] || a[5] || a[6] || a[7] || a[8])
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    this->screen.setMouseCursor(this->cursor);
}

//drawing everything
void Application::display_townhall(){
    this->screen.clear(Color::White);

    //buttons
    this->show_return_button();

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
