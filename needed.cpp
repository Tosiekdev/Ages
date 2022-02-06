//
// Created by tosiek on 04.12.2021.
//

#include "needed.h"
#include "button.h"

using namespace sf;
using namespace std;

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
    this->possition.x=0;
    this->possition.y=0;
    this->screen.setPosition(this->possition);

    //Textures loading
    this->background_menu_texture.loadFromFile("Textures/background.png");
    this->background_menu_sprite.setTexture(this->background_menu_texture);
    this->background_menu_sprite.setPosition(0,0);

    //Buttons
    this->new_game.create(40,100,40,130,"New Game");
    this->load_game.create(40,100,40,190,"Load Game");
    this->exit.create(40,100,40,250,"Exit");

    //Captions
    this->ages.create(DEFAULT_FONT,330,0,"Ages",60);
    this->programmer.create(DEFAULT_FONT,500,395,"Programista:",40);
    this->tosiek.create(DEFAULT_FONT,500,440,"Tosiek",35);
    this->graphic.create(DEFAULT_FONT,500,485,"Grafika:",40);
    this->iwa.create(DEFAULT_FONT,500,530,"Iwa",35);

    //Tablets
    Vector2f pp=Vector2f(200,40);//very soft
    for(int i=0;i<5;i++){
        this->t[i].create_tablet("-:-",pp);
        pp+=Vector2f(0,110);
    }
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
                this->menu();
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
        }
    }
    for_clocks.join();
}

//Menu main thread
void Application::menu()
{
    //EVENT
    this->m_handle_event();

    //DO SOME STUFF
    this->m_stuff();

    //DISPLAY
    this->display_menu();
}

//Events handling
void Application::m_handle_event(){
    while(this->screen.pollEvent(this->e)){
        //Closing events
        if(this->e.type==Event::Closed) this->screen.close();
        if((Keyboard::isKeyPressed(Keyboard::Escape))) this->u_sure(this->screen);

        //Mouse pressed events
        if(Mouse::isButtonPressed(Mouse::Left)){
            //getting mouse position
            int a=Mouse::getPosition(this->screen).x;
            int b=Mouse::getPosition(this->screen).y;

            //new game button
            if(this->new_game.onClick(a,b)){
                this->create_create();
                this->scene=2;
            }

            //load game button
            if(this->load_game.onClick(a,b)){
                this->create_load();
                this->scene=3;
            }

            //exit button
            if(this->exit.onClick(a,b)){
                this->screen.close();
            }
        }
    }
}

//Drawing menu
void Application::display_menu(){
    this->screen.clear(Color::White);

    //Background
    this->screen.draw(this->background_menu_sprite);

    //Captions
    this->ages.show(this->screen);
    this->programmer.show(this->screen);
    this->tosiek.show(this->screen);
    this->graphic.show(this->screen);
    this->iwa.show(this->screen);

    //Buttons
    this->new_game.show(this->screen);
    this->load_game.show(this->screen);
    this->exit.show(this->screen);

    this->screen.display();
}

//Every frame stuff
void Application::m_stuff(){
    //getting mouse position
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    //checking buttons focus
    this->new_game.onFocus(x,y);
    this->load_game.onFocus(x,y);
    this->exit.onFocus(x,y);
}

//Checking if user really wants to exit
void Application::u_sure(RenderWindow &W){
    //creating window
    this->wexit.create(VideoMode(300,200),"Are you sure?",Style::Titlebar | Style::Close);
    this->wexit.setPosition(Vector2i(250+W.getPosition().x,200+W.getPosition().y));
    this->wexit.setMouseCursorGrabbed(true);

    //creating buttons
    this->yes.create(40,100,167,110,"Yes");
    this->no.create(40,100,33,110,"No");
    this->sure.create(DEFAULT_FONT,2,20,"Are sure you want exit?",28);

    //Event handling
    while(this->wexit.isOpen()){
        while(this->wexit.pollEvent(this->exit_e)){
            //Exit
            if(this->exit_e.type==Event::Closed) this->wexit.close();

            //Is button clicked?
            if(this->exit_e.type==Event::MouseButtonPressed){
                //Getting mouse position
                int x=Mouse::getPosition(this->wexit).x;
                int y=Mouse::getPosition(this->wexit).y;

                //yes button
                if(this->yes.onClick(x,y)){
                    W.close();
                    this->wexit.close();
                }

                //no button
                if(this->no.onClick(x,y)) this->wexit.close();
            }
        }

        //Button animation
        this->yes.onFocus(Mouse::getPosition(this->wexit).x,Mouse::getPosition(this->wexit).y);
        this->no.onFocus(Mouse::getPosition(this->wexit).x,Mouse::getPosition(this->wexit).y);

        //Drawing everything
        this->wexit.clear(Color::White);
        this->yes.show(this->wexit);
        this->no.show(this->wexit);
        this->sure.show(this->wexit);
        this->wexit.display();
    }
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

    file.close();

    return "";
}

