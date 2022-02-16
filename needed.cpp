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
                this->launch_game();
                //this->game();
                break;
            case 5:
                this->launch_th();
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
            case 9:
                this->launch_wh();
                break;
            case 10:
                this->launch_academy();
                break;
            case 11:
                this->launch_barracks();
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

    this->game_window.set_path(this->save_path);

    //checking if file already exists
    filecheck.open(this->save_path);
    if(filecheck) return "This village already exists!";

    //setting name
    this->name=calling;

    //setting levels
    this->game_window.set_levels();

    //setting resources
    this->game_window.set_resources();

   for(int i=0; i<8; i++)
       this->game_window.set_ub_left(i,0,1);

    //writing new name to all saves file
    file.open("all_saves.txt",ios::out | ios::app);
    file << calling << endl;
    file.close();

    //saving village properties
    //this->save_game();
    this->game_window.save_game();

    return "";
}
