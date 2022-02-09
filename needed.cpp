//
// Created by tosiek on 04.12.2021.
//

#include "needed.h"
#include "button.h"

using namespace sf;
using namespace std;


//Constructor
Application::Application(){
    //assigning pointers
    this->b_ptr[0]=&(this->b_academy);
    this->b_ptr[1]=&(this->b_barracks);
    this->b_ptr[2]=&(this->b_church);
    this->b_ptr[3]=&(this->b_farm);
    this->b_ptr[4]=&(this->b_lumber);
    this->b_ptr[5]=&(this->b_stone);
    this->b_ptr[6]=&(this->b_town);
    this->b_ptr[7]=&(this->b_magazine);

    //settings
    this->height=600;
    this->width=800;
    this->max_fps=60;

    //Preparing window
    this->screen.create(VideoMode(this->width,this->height),"Ages",Style::Titlebar | Style::Close);
    this->screen.setFramerateLimit(this->max_fps);
    this->cursor.loadFromSystem(Cursor::Arrow);
    this->screen.setMouseCursor(this->cursor);
    this->possition.x=0;
    this->possition.y=0;
    this->screen.setPosition(this->possition);

    this->background_menu_texture.loadFromFile("Textures/background.png");
    this->background_menu_sprite.setTexture(this->background_menu_texture);
    this->background_menu_sprite.setPosition(0,0);

    //preparing menu
    this->menu.create();

    //preparing create screen
    //Tablets
    Vector2f pp=Vector2f(200,40);//very soft
    for(int i=0;i<5;i++){
        this->t[i].create_tablet("-:-",pp);
        pp+=Vector2f(0,110);
    }
    this->create_create();

    //preparing load screen
    this->create_load();

    //Scenes
    this->scene=1;
}

//Main thread of whole app
void Application::main_window(){
    //start clock thread
    thread for_clocks(&Application::clocks, this);
    //scenes switching
    while(this->screen.isOpen()){
        switch(this->scene){
            case 1:
                this->menu.main_loop(this->screen,this->scene);
                break;
            case 2:
                this->create();
                break;
            case 3:
                this->load();
                break;
            case 4:
                this->game();
                break;
            case 5:
                this->townhall();
                break;
            case 6:
                this->launch_farm();
                break;
            case 7:
                this->launch_lm();
                break;
            case 8:
                this->launch_sp();
                break;
        }
    }
    for_clocks.join();
}

//Creating city a' ka loading save
string Application::create_city(string calling){

    //creating needed variables
    fstream file;
    ifstream filecheck;
    string line;
    this->save_path=calling+".txt";

    //checking if file already exists
    filecheck.open(this->save_path);
    if(filecheck) return "This village already exists!";

    //setting name
    this->name=calling;

    //setting levels
    this->academy=0;
    this->barracks=0;
    this->church=0;
    this->farm=1;
    this->lumber_mill=1;
    this->stone_pit=1;
    this->town_hall=1;
    this->magazine=1;

    //setting resources
    this->human=10;
    this->wood=100;
    this->rock=100;

    //setting time left
    for(int i=0; i<8; i++)
        this->u_buildings[i].set_left(0,1);

    //writing new name to all saves file
    file.open("all_saves.txt",ios::out | ios::app);
    file << calling << endl;
    file.close();

    //saving village properties
    file.open(save_path,ios::out);

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

    //upgrades time left
    for(int i=0; i<8; i++)
        file << this->u_buildings[i].get_left() << endl;

    file.close();

    return "";
}

//default returning to game
void Application::return_to_village(){
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
