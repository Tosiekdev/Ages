//
// Created by tosiek on 04.12.2021.
//

#include "needed.h"

using namespace sf;
using namespace std;

void Application::create_game(){
    //buttons
    this->return_to_menu.create(40,100,5,5,"Return");
    this->save.create(40,100,130,5,"Save");

    //set clock to 0
    this->resource_clock.restart();

    //for town hall
    float y_position=205.f;
    for(int i=0; i<8; i++){
        this->th_window.crete_ub(this->b_ptr[i],Vector2f(20,y_position),i);
        y_position+=100.f;
    }

    this->create_buildings();

    //resource plank
    this->resource_plank.create_obstacle(PLANK, Vector2f(0.4,0.4), Vector2f(564,0));
    this->resource_man.create_obstacle("Textures/human.png", Vector2f(0.25, 0.25), Vector2f(570,5));
    this->resource_rock.create_obstacle("Textures/rock.png", Vector2f(0.4, 0.4), Vector2f(570, 50));
    this->resource_wood.create_obstacle("Textures/wood.png", Vector2f(0.125,0.125), Vector2f(570, 95));
    //resource numbers
    this->l_human.create(DEFAULT_FONT,620,5,to_string(this->human),30);
    this->l_rock.create(DEFAULT_FONT,620,50,to_string(this->rock),30);
    this->l_wood.create(DEFAULT_FONT,620,95,to_string(this->wood),30);
}

//Start main loop
void Application::game(){
    //handle events
    this->g_handle_event();

    //do some stuff
    this->g_stuff();

    //draw
    this->display_game();
}

//Every frame stuff
void Application::g_stuff(){
    bool a[10];
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    //cool animation
    a[8]=this->return_to_menu.onFocus(x,y);
    a[9]=this->save.onFocus(x,y);

    //cool building animation
    a[0]=this->b_academy.onFocus(x,y);
    a[1]=this->b_barracks.onFocus(x,y);
    a[2]=this->b_church.onFocus(x,y);
    a[3]=this->b_farm.onFocus(x,y);
    a[4]=this->b_lumber.onFocus(x,y);
    a[5]=this->b_stone.onFocus(x,y);
    a[6]=this->b_town.onFocus(x,y);
    a[7]=this->b_magazine.onFocus(x,y);

    if(a[0] || a[1] || a[2] || a[3] || a[4] || a[5] || a[6] || a[7] || a[8] || a[9])
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    this->screen.setMouseCursor(this->cursor);

    this->activate_buildings();

    //increasing resources is handled by thread
}

//Handling events
void Application::g_handle_event(){
    while(this->screen.pollEvent(this->e)){
        //closing
        if(this->e.type==Event::Closed) this->screen.close();

        if(Mouse::isButtonPressed(Mouse::Left)){
            //getting mouse position
            int i=Mouse::getPosition(this->screen).x;
            int j=Mouse::getPosition(this->screen).y;

            //Returning button event
            if(this->return_to_menu.onClick(i,j)){
                this->disactivate_buildings();
                this->wsWindow.create(this->screen,this->scene);
            }

            //Buildings events
            if(this->b_town.isClicked(i,j)){
                this->th_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,&this->rock,&this->wood,&this->levels[6]);
                this->scene=5;
            }
            if(this->b_farm.isClicked(i,j)){
                this->farm_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,&this->rock,&this->wood,&this->levels[3]);
                this->scene=6;
            }
            if(this->b_lumber.isClicked(i,j)){
                this->lm_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,&this->rock,&this->wood,&this->levels[4]);
                this->scene=7;
            }
            if(this->b_stone.isClicked(i,j)){
                this->sp_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,&this->rock,&this->wood,&this->levels[5]);
                this->scene=8;
            }
            if(this->b_magazine.isClicked(i,j)){
                this->wh_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,&this->rock,&this->wood,&this->levels[7]);
                this->scene=9;
            }

            //saving game
            if(this->save.onClick(i,j)) this->save_game();
        }
    }
}

//Displaying game
void Application::display_game(){
    this->screen.clear(Color::Green);

    //buttons
    this->return_to_menu.show(this->screen);
    this->save.show(this->screen);

    //resource plank
    this->resource_plank.draw(this->screen);
    this->resource_man.draw(this->screen);
    this->resource_rock.draw(this->screen);
    this->resource_wood.draw(this->screen);
    //resource numbers
    this->l_human.show(this->screen);
    this->l_rock.show(this->screen);
    this->l_wood.show(this->screen);

    //buildings
    this->b_academy.show(this->screen);
    this->b_town.show(this->screen);
    this->b_lumber.show(this->screen);
    this->b_church.show(this->screen);
    this->b_barracks.show(this->screen);
    this->b_farm.show(this->screen);
    this->b_stone.show(this->screen);
    this->b_magazine.show(this->screen);

    this->screen.display();
}

//Create buildings
void Application::create_buildings(){
    //preparing needed files
    this->save_system.load_save(this->save_path,this->levels,this->th_window,this->name,this->human,this->wood,this->rock);

    //make everything done
    this->prepare_buildings();
}

//assign values to proper building
void Application::prepare_buildings(){
    this->b_academy.create_building("Academy","Textures/academy.png",this->levels[0],Vector2f(600,450),100,75,10);
    this->b_barracks.create_building("Barracks","Textures/barracks.png",this->levels[1],Vector2f(100,100),75,75,7);
    this->b_church.create_building("Church","Textures/church.png", this->levels[2],Vector2f(200,200),50,150,10);
    this->b_farm.create_building("Farm","Textures/farm.png", this->levels[3],Vector2f(300,300),20,60,2);
    this->b_lumber.create_building("Lumber mill","Textures/default.png",this->levels[4],Vector2f(400,30),65,15,2);
    this->b_stone.create_building("Stone pit","Textures/default.png",this->levels[5],Vector2f(500,300),15,65,2);
    this->b_town.create_building("Town Hall","Textures/town_hall.png",this->levels[6],Vector2f(0,300),75,75,12);
    this->b_magazine.create_building("Warehouse","Textures/magazine.png",this->levels[7],Vector2f(0,450),100,50,6);
    for(int i=0; i<8; i++){
        this->th_window.ub_update_level(i);
    }
}

//saving game
void Application::save_game(){
    this->save_system.save_game(this->save_path,this->levels,this->th_window,this->name,this->human,this->wood,this->rock);
}

//thread to count time
void Application::clocks(){
    while(this->screen.isOpen()){
        if(this->scene>3){
            //increasing resources
            if (this->resource_clock.getElapsedTime().asSeconds() >= 1) {
                int time_passed = (int)this->resource_clock.getElapsedTime().asSeconds();
                this->human+=time_passed*1.2*this->levels[3];
                this->rock+=time_passed*10*this->levels[5];
                this->wood+=time_passed*10*this->levels[4];

                //full magazine
                if(this->rock>=this->levels[7]*1296){
                    this->rock=this->levels[7]*1296;
                    this->l_rock.setColor(Color::Red);
                }else
                    this->l_rock.setColor(Color::Black);

                if(this->wood>=this->levels[7]*1296){
                    this->wood=this->levels[7]*1296;
                    this->l_wood.setColor(Color::Red);
                }else
                    this->l_wood.setColor(Color::Black);

                //full farm
                if(this->human>=this->levels[3]*83){
                    this->human=this->levels[3]*83;
                    this->l_human.setColor(Color::Red);
                }else
                    this->l_human.setColor(Color::Black);

                switch(scene){
                    case 4:
                        this->l_human.setCaption(to_string(this->human));
                        this->l_rock.setCaption(to_string(this->rock));
                        this->l_wood.setCaption(to_string(this->wood));
                        break;
                    default:
                        this->l_human.setCaption("People: "+to_string(this->human));
                        this->l_rock.setCaption("Stone: "+to_string(this->rock));
                        this->l_wood.setCaption("Wood: "+to_string(this->wood));
                        break;
                }
                this->resource_clock.restart();
            }
            for(int i=0; i<8; i++){
                if(this->th_window.ub_get_time(i)>=1){
                    if(this->th_window.ub_update_timer(i,this->th_window.ub_get_time(i))==3)
                        this->assign_levels();
                    this->th_window.ub_reset_timer(i);
                }
            }
        }
    }
}

//assigns levels from buildings
void Application::assign_levels(){
    this->levels[0]=this->b_academy.get_level();
    this->levels[1]=this->b_barracks.get_level();
    this->levels[2]=this->b_church.get_level();
    this->levels[3]=this->b_farm.get_level();
    this->levels[4]=this->b_lumber.get_level();
    this->levels[5]=this->b_stone.get_level();
    this->levels[6]=this->b_town.get_level();
    this->levels[7]=this->b_magazine.get_level();
}

void Application::disactivate_buildings(){
    this->b_academy.disactivate();
    this->b_barracks.disactivate();
    this->b_church.disactivate();
    this->b_lumber.disactivate();
    this->b_magazine.disactivate();
    this->b_farm.disactivate();
    this->b_stone.disactivate();
    this->b_town.disactivate();
}

void Application::activate_buildings(){
    this->b_academy.activate();
    this->b_barracks.activate();
    this->b_church.activate();
    this->b_lumber.activate();
    this->b_magazine.activate();
    this->b_farm.activate();
    this->b_stone.activate();
    this->b_town.activate();
}
