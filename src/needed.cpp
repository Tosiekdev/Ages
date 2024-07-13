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
    screen_.create(VideoMode(width_,height_),"Ages",Style::Titlebar | Style::Close);
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
    scene_=buildings::Scene::MENU;
}

//Main thread of whole app
void Application::main_window(){
    //start clock thread
    std::thread forClocks(&Application::clocks, this);
    //scenes switching
    while(screen_.isOpen()){
        switch(scene_){
            case buildings::Scene::MENU:
                menu_.main_loop(screen_, scene_);
                break;
            case buildings::Scene::CREATE:
                create();
                break;
            case buildings::Scene::LOAD:
                load();
                break;
            case buildings::Scene::GAME:
                launch_game();
                break;
            case buildings::Scene::TOWN_HALL:
                launch_th();
                break;
            case buildings::Scene::FARM:
                launch_farm();
                break;
            case buildings::Scene::LUMBER_MILL:
                launch_lm();
                break;
            case buildings::Scene::STONE_PIT:
                launch_sp();
                break;
            case buildings::Scene::WAREHOUSE:
                launch_wh();
                break;
            case buildings::Scene::ACADEMY:
                launch_academy();
                break;
            case buildings::Scene::BARRACKS:
                launch_barracks();
                break;
            case buildings::Scene::CHURCH:
                launch_church();
                break;
            case buildings::Scene::BANK:
                launch_bank();
                break;
            case buildings::Scene::IRON_MINE:
                launch_irmine();
                break;
            case buildings::Scene::MAP:
                launch_map();
                break;
        }
    }
    forClocks.join();
}

//Creating city a' ka loading save_
std::string Application::create_city(const std::string& calling){

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

   for(int i=0; i<10; i++)
       gameWindow_.set_ub_left(i, 0, 1);

    //writing new name_ to all saves file
    file.open("all_saves.txt",std::ios::out | std::ios::app);
    file << calling << std::endl;
    file.close();

    //saving village properties
    gameWindow_.save_game();

    return "";
}
