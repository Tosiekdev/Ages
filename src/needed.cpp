//
// Created by tosiek on 04.12.2021.
//

#include "../headers/needed.h"
#include "../headers/ui/button.h"

//Constructor
Application::Application(){
    //settings
    height_=600;
    width_=800;
    maxFps_=60;

    //Preparing window
    screen_.create(VideoMode(width_,this->height_),"Ages",Style::Titlebar | Style::Close);
    screen_.setFramerateLimit(maxFps_);
    cursor_.loadFromSystem(Cursor::Arrow);
    screen_.setMouseCursor(cursor_);
    position_.x=0;
    position_.y=0;
    screen_.setPosition(position_);

    backgroundMenuTexture_.loadFromFile("Textures/background.png");
    backgroundMenuSprite_.setTexture(backgroundMenuTexture_);
    backgroundMenuSprite_.setPosition(0, 0);

    //preparing menu_
    menu_.create();

    //preparing create screen_
    //Tablets
    Vector2f pp=Vector2f(200,40);//very soft
    for(auto & i:t_){
        i.create_tablet("-:-",pp);
        pp+=Vector2f(0,110);
    }
    create_create();

    //preparing load screen_
    create_load();

    //Scenes
    scene_=1;
}

//Main thread of whole app
void Application::main_window(){
    //start clock thread
    thread forClocks(&Application::clocks, this);
    //scenes switching
    while(screen_.isOpen()){
        switch(scene_){
            case 1:
                menu_.main_loop(screen_, scene_);
                break;
            case 2:
                create();
                break;
            case 3:
                load();
                break;
            case 4:
                launch_game();
                break;
            case 5:
                launch_th();
                break;
            case 6:
                launch_farm();
                break;
            case 7:
                launch_lm();
                break;
            case 8:
                launch_sp();
                break;
            case 9:
                launch_wh();
                break;
            case 10:
                launch_academy();
                break;
            case 11:
                launch_barracks();
                break;
            case 12:
                launch_church();
                break;
            case 13:
                launch_bank();
                break;
        }
    }
    forClocks.join();
}

//Creating city a' ka loading save
string Application::create_city(const string& calling){

    //creating needed variables
    std::fstream file;
    std::ifstream fileCheck;
    std::string line;
    savePath_= calling + ".txt";

    gameWindow_.set_path(savePath_);

    //checking if file already exists
    fileCheck.open(savePath_);
    if(fileCheck) return "This village already exists!";

    //setting name_
    name=calling;

    //setting levels_
    gameWindow_.set_levels();

    //setting resources
    gameWindow_.set_resources();

   for(int i=0; i<8; i++)
       gameWindow_.set_ub_left(i, 0, 1);

    //writing new name_ to all saves file
    file.open("all_saves.txt",ios::out | ios::app);
    file << calling << std::endl;
    file.close();

    //saving village properties
    gameWindow_.save_game();

    return "";
}
