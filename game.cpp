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

    //for town hall
    float y_position=100.f;
    for(int i=0; i<8; i++){
        this->u_buildings[i].create_upgrade(this->b_ptr[i],this->num_to_names[i+1],Vector2f(20,y_position));
        y_position+=100.f;
    }
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
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    //cool animation
    this->return_to_menu.onFocus(x,y);
    this->save.onFocus(x,y);

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
            if(this->return_to_menu.onClick(i,j)) this->wo_saving();

            //Buildings events
            if(this->b_town.isClicked(i,j)){
                this->create_townhall();
                this->scene=5;
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
    fstream s_path;
    s_path.open(this->save_path,ios::in);
    string input;
    int line_nr=0;
    while(!s_path.eof()){
        getline(s_path, input);

        //assigning value to the right variable
        switch(line_nr){
            case 0:
                this->name=input;
                break;
            case 1:
                this->academy=stoi(input);
                break;
            case 2:
                this->barracks=stoi(input);
                break;
            case 3:
                this->church=stoi(input);
                break;
            case 4:
                this->farm=stoi(input);
                break;
            case 5:
                this->lumber_mill=stoi(input);
                break;
            case 6:
                this->stone_pit=stoi(input);
                break;
            case 7:
                this->town_hall=stoi(input);
                break;
            case 8:
                this->magazine=stoi(input);
            //resources
            case 9:
                this->human=stoi(input);
                break;
            case 10:
                this->wood=stoi(input);
                break;
            case 11:
                this->rock=stoi(input);
                break;
        }
        line_nr++;
    }
    s_path.close();

    //make everything done
    this->prepare_buildings();
}

//assign values to proper building
void Application::prepare_buildings(){
    this->b_academy.create_building("Academy", "Textures/academy.png", this->academy, Vector2f(600,450), 100, 75, 10);
    this->b_barracks.create_building("Barracks", "Textures/barracks.png", this->barracks, Vector2f(100,100), 75, 75, 7);
    this->b_church.create_building("Church", "Textures/church.png", this->church, Vector2f(200,200), 50, 150, 10);
    this->b_farm.create_building("Farm", "Textures/farm.png", this->farm, Vector2f(300,300), 20, 60, 2);
    this->b_lumber.create_building("Lumber mill", "Textures/default.png", this->lumber_mill, Vector2f(400,30), 65, 15, 2);
    this->b_stone.create_building("Stone pit", "Textures/default.png", this->stone_pit, Vector2f(500,300), 15, 65, 2);
    this->b_town.create_building("Town Hall", "Textures/town_hall.png", this->town_hall, Vector2f(0,300), 75, 75, 12);
    this->b_magazine.create_building("Magazine", "Textures/magazine.png", this->magazine, Vector2f(0,450), 100, 50, 6);
}

//saving game
void Application::save_game(){
    //opening save
    fstream file;
    file.open(this->save_path, ios::out);

    //save all data
    //levels
    file << this->name << endl;
    file << this->academy << endl;
    file << this->barracks << endl;
    file << this->church << endl;
    file << this->farm << endl;
    file << this->lumber_mill << endl;
    file << this->stone_pit << endl;
    file << this->town_hall << endl;
    file << this->magazine << endl;

    //resources;
    file << this->human << endl;
    file << this->wood << endl;
    file << this->rock << endl;

    file.close();
}

//handle window which makes sure that player want to exit
void Application::wo_saving(){
    //creating window
    this->wsaving.create(VideoMode(300,200),"Are you sure?",Style::Titlebar | Style::Close);
    this->wsaving.setPosition(Vector2i(250+this->screen.getPosition().x,200+this->screen.getPosition().y));
    this->wsaving.setMouseCursorGrabbed(true);

    //creating buttons
    this->am_sure.create(40,100,167,110,"Yes");
    this->not_sure.create(40,100,33,110,"No");
    this->no_save.create(DEFAULT_FONT,2,20,"Are sure you want exit?",28);
    this->ns_pt2.create(DEFAULT_FONT,15,55,"All unsaved progress will be lost.",18);

    //Event handling
    while(this->wsaving.isOpen()){
        while(this->wsaving.pollEvent(this->e_save)){
            //Exit
            if(this->e_save.type==Event::Closed) this->wsaving.close();

            //Is button clicked?
            if(this->e_save.type==Event::MouseButtonPressed){
                //Getting mouse position
                int x=Mouse::getPosition(this->wsaving).x;
                int y=Mouse::getPosition(this->wsaving).y;

                //yes button
                if(this->am_sure.onClick(x,y)){
                    this->scene=1;
                    this->wsaving.close();
                }

                //no button
                if(this->not_sure.onClick(x,y)) this->wsaving.close();
            }
        }

        //Button animation
        this->am_sure.onFocus(Mouse::getPosition(this->wsaving).x,Mouse::getPosition(this->wsaving).y);
        this->not_sure.onFocus(Mouse::getPosition(this->wsaving).x,Mouse::getPosition(this->wsaving).y);

        //Drawing everything
        this->wsaving.clear(Color::White);
        this->am_sure.show(this->wsaving);
        this->not_sure.show(this->wsaving);
        this->no_save.show(this->wsaving);
        this->ns_pt2.show(this->wsaving);

        this->wsaving.display();
    }
}

//thread to count time
void Application::clocks(){
    while(this->screen.isOpen()){
        if(this->scene>3){
            //increasing resources
            if (this->resource_clock.getElapsedTime().asSeconds() >= 1) {
                int time_passed = (int)this->resource_clock.getElapsedTime().asSeconds();
                this->human += time_passed * farm;
                this->rock += time_passed * 10 * stone_pit;
                this->wood += time_passed * 10 * lumber_mill;

                //full magazine
                if(this->rock>pow(this->magazine,5/3)*1000){
                    this->rock=pow(this->magazine,5/3)*1000;
                    this->l_rock.setColor(Color::Red);
                }else
                    this->l_rock.setColor(Color::Black);

                if(this->wood>pow(this->magazine,5/3)*1000){
                    this->wood=pow(this->magazine,5/3)*1000;
                    this->l_wood.setColor(Color::Red);
                }else
                    this->l_wood.setColor(Color::Black);

                switch(scene){
                    case 4:
                        this->l_human.setCaption(to_string(this->human));
                        this->l_rock.setCaption(to_string(this->rock));
                        this->l_wood.setCaption(to_string(this->wood));
                        break;
                    case 5:
                        this->l_human.setCaption("People: "+to_string(this->human));
                        this->l_rock.setCaption("Stone: "+to_string(this->rock));
                        this->l_wood.setCaption("Wood: "+to_string(this->wood));
                        break;
                }
                this->resource_clock.restart();
            }
            for(int i=0; i<8; i++){
                if(this->u_buildings[i].get_time()>=1){
                    if(this->u_buildings[i].update_timer(this->u_buildings[i].get_time())==3)
                        this->assign_levels();
                    this->u_buildings[i].reset_timer();
                }
            }
        }
    }
}

//assigns levels from buildings
void Application::assign_levels(){
    this->academy=this->b_academy.get_level();
    this->barracks=this->b_barracks.get_level();
    this->church=this->b_church.get_level();
    this->farm=this->b_farm.get_level();
    this->lumber_mill=this->b_lumber.get_level();
    this->stone_pit=this->b_stone.get_level();
    this->town_hall=this->b_town.get_level();
    this->magazine=this->b_magazine.get_level();
}


