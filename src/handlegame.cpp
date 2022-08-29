//
// Created by tosiek on 16.02.2022.
//

#include "../headers/handlegame.h"

void HandleGame::create(std::string path){
    //assign path
    this->set_path(path);

    //buttons
    this->return_to_menu.create(40,100,5,5,"Return");
    this->save.create(40,100,130,5,"Save");

    //set clock to 0
    this->resource_clock.restart();

    //for town hall
    float y_position=205.f;
    for(int i=0; i<8; i++){
        this->th_window.crete_ub(&(this->building_[i]), sf::Vector2f(20, y_position), i);
        y_position+=100.f;
    }

    this->create_buildings();

    //resource plank_
    this->resource_plank.create_obstacle(PLANK, sf::Vector2f(0.4,0.4),
                                         sf::Vector2f(564,0));
    this->resource_man.create_obstacle("Textures/human.png",sf::Vector2f(0.25, 0.25),
                                       sf::Vector2f(570,5));
    this->resource_rock.create_obstacle("Textures/rock.png",sf::Vector2f(0.4, 0.4),
                                        sf::Vector2f(570, 50));
    this->resource_wood.create_obstacle("Textures/wood.png",sf::Vector2f(0.125,0.125),
                                        sf::Vector2f(570, 95));
    //resource numbers
    this->l_human.create(DEFAULT_FONT,620,5,std::to_string(this->human),30);
    this->l_rock.create(DEFAULT_FONT,620,50,std::to_string(this->rock),30);
    this->l_wood.create(DEFAULT_FONT,620,95,std::to_string(this->wood),30);
}

void HandleGame::main_loop(sf::RenderWindow &window, int &scene){
    this->handle_event(scene,window);
    this->do_stuff(window);
    this->display(window);
}

void HandleGame::handle_event(int &scene, sf::RenderWindow &window){
    while(window.pollEvent(this->e)){
        //exit
        if (this->e.type==sf::Event::Closed) window.close();
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) this->exitWindow.create(window, scene);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //getting mouse _position
            int i = sf::Mouse::getPosition(window).x;
            int j = sf::Mouse::getPosition(window).y;

            //Returning button event
            if(this->return_to_menu.onClick(i,j)){
                this->deactivate_buildings();
                this->wsWindow.create(window,scene);
            }

            //Buildings events
            if(this->building_[6].isClicked(i, j)){
                this->th_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,
                                       &this->rock,&this->wood,&this->levels_[6]);
                scene=5;
            }
            if(this->building_[3].isClicked(i, j)){
                this->farm_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,
                                         &this->rock,&this->wood,&this->levels_[3]);
                scene=6;
            }
            if(this->building_[4].isClicked(i, j)){
                this->lm_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,
                                       &this->rock,&this->wood,&this->levels_[4]);
                scene=7;
            }
            if(this->building_[5].isClicked(i, j)){
                this->sp_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,
                                       &this->rock,&this->wood,&this->levels_[5]);
                scene=8;
            }
            if(this->building_[7].isClicked(i, j)){
                this->wh_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,
                                       &this->rock,&this->wood,&this->levels_[7]);
                scene=9;
            }
            if(this->building_[0].isClicked(i, j)){
                this->academy_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,
                                            &this->rock,&this->wood,&this->levels_[0]);
                scene=10;
            }
            if(this->building_[1].isClicked(i, j)){
                this->barracks_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,
                                             &this->rock,&this->wood,&this->levels_[1]);
                scene=11;
            }
            if(this->building_[2].isClicked(i, j)){
                this->church_window.create(&this->l_human,&this->l_rock,&this->l_wood,&this->human,
                                           &this->rock,&this->wood,&this->levels_[2]);
                scene=12;
            }

            //saving game
            if(this->save.onClick(i,j)) this->save_game();
        }
    }
}

void HandleGame::do_stuff(sf::RenderWindow &window){
    std::vector<bool> a;
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool building_ animation
    for(int i=0; i<8; i++)
        a.push_back(this->building_[i].onFocus(x, y));

    //cool button animation
    a.push_back(this->return_to_menu.onFocus(x,y));
    a.push_back(this->save.onFocus(x,y));

    //cursor_ change
    if(std::any_of(a.begin(),a.end(),[](bool i){return i;}))
        this->cursor.loadFromSystem(sf::Cursor::Hand);
    else
        this->cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(this->cursor);

    this->activate_buildings();
}

void HandleGame::display(sf::RenderWindow &window){
    window.clear(sf::Color::Green);

    //buttons
    this->return_to_menu.show(window);
    this->save.show(window);

    //resource plank_
    this->resource_plank.draw(window);
    this->resource_man.draw(window);
    this->resource_rock.draw(window);
    this->resource_wood.draw(window);
    //resource numbers
    this->l_human.show(window);
    this->l_rock.show(window);
    this->l_wood.show(window);

    //buildings
    for(auto &i:building_)
        i.show(window);

    window.display();
}

void HandleGame::deactivate_buildings(){
    for(auto &i:this->building_)
        i.deactivate();
}

void HandleGame::activate_buildings(){
    for(auto &i:this->building_)
        i.activate();
}

void HandleGame::create_buildings(){
    //load data
    this->saveSystem.load_save(this->save_path, this->levels_, this->th_window, this->name, this->human,
                               this->wood, this->rock, this->building_);

    //make everything done
    this->prepare_buildings();
}

void HandleGame::prepare_buildings(){
    this->building_[0].create_building("Academy", "Textures/academy.png", this->levels_[0],
                                       sf::Vector2f(250,300), 100, 75, 10);
    this->building_[1].create_building("Barracks", "Textures/barracks.png", this->levels_[1],
                                       sf::Vector2f(50,300), 75, 75, 7);
    this->building_[2].create_building("Church", "Textures/church.png", this->levels_[2],
                                       sf::Vector2f(300,150), 50, 150, 10);
    this->building_[3].create_building("Farm", "Textures/farm.png", this->levels_[3],
                                       sf::Vector2f(600,450), 20, 60, 2);
    this->building_[4].create_building("Lumber mill", "Textures/default.png", this->levels_[4],
                                       sf::Vector2f(400,450), 65, 15, 2);
    this->building_[5].create_building("Stone pit", "Textures/default.png", this->levels_[5],
                                       sf::Vector2f(600,250), 15, 65, 2);
    this->building_[6].create_building("Town Hall", "Textures/town_hall.png", this->levels_[6],
                                       sf::Vector2f(100,100), 75, 75, 12);
    this->building_[7].create_building("Warehouse", "Textures/magazine.png", this->levels_[7],
                                       sf::Vector2f(150,450), 100, 50, 6);
    for(int i=0; i<8; i++){
        this->th_window.ub_update_level(i);
    }
}

void HandleGame::save_game(){
    this->saveSystem.save_game(this->save_path, this->levels_, this->th_window, this->name,
                               this->human, this->wood, this->rock);
}

void HandleGame::assign_levels(){
    for(int i=0; i<8; i++)
        this->levels_[i]=this->building_[i].get_level();
}

void HandleGame::clocks(int scene){
    if(scene>3){
        //increasing resources
        if (resource_clock.getElapsedTime().asSeconds() >= 1) {
            int time_passed = (int)resource_clock.getElapsedTime().asSeconds();
            human+=static_cast<int>(time_passed * 1.2 * levels_[3]);
            rock+= time_passed * 10 * levels_[5];
            wood+= time_passed * 10 * levels_[4];

            //full magazine
            if(rock >= levels_[7] * 1296){
                rock= levels_[7] * 1296;
                l_rock.setColor(sf::Color::Red);
            }else{
                l_rock.setColor(sf::Color::Black);
            }

            if(wood >= levels_[7] * 1296){
                wood= levels_[7] * 1296;
                l_wood.setColor(sf::Color::Red);
            }else
                l_wood.setColor(sf::Color::Black);

            //full farm
            if(human >= levels_[3] * 156){
                human= levels_[3] * 156;
                l_human.setColor(sf::Color::Red);
            }else
                l_human.setColor(sf::Color::Black);

            switch(scene){
                case 4:
                    l_human.setCaption(std::to_string(human));
                    l_rock.setCaption(std::to_string(rock));
                    l_wood.setCaption(std::to_string(wood));
                    break;
                default:
                    l_human.setCaption("People: "+std::to_string(human));
                    l_rock.setCaption("Stone: "+std::to_string(rock));
                    l_wood.setCaption("Wood: "+std::to_string(wood));
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

void HandleGame::launch_th(sf::RenderWindow &window, int &scene){
    this->th_window.main_loop(this->e,window,scene);
}

void HandleGame::launch_farm(sf::RenderWindow &window, int &scene){
    this->farm_window.main_loop(this->e,window,scene);
}

void HandleGame::launch_lm(sf::RenderWindow &window, int &scene){
    this->lm_window.main_loop(this->e,window,scene);
}

void HandleGame::launch_sp(sf::RenderWindow &window, int &scene){
    this->sp_window.main_loop(this->e,window,scene);
}

void HandleGame::launch_wh(sf::RenderWindow &window, int &scene){
    this->wh_window.main_loop(this->e,window,scene);
}

void HandleGame::launch_academy(sf::RenderWindow &window, int &scene){
    this->academy_window.main_loop(this->e,window,scene);
}

void HandleGame::launch_barracks(sf::RenderWindow &window, int &scene){
    this->barracks_window.main_loop(this->e,window,scene);
}

void HandleGame::launch_church(sf::RenderWindow &window, int &scene){
    this->church_window.main_loop(this->e,window,scene);
}

void HandleGame::set_ub_left(int index, float time, float th){
    this->th_window.set_ub_left(index,time, th);
}

void HandleGame::set_levels(){
    for(int i=0; i<3; i++) this->levels_[i]=0;
    for(int i=3; i<8; i++) this->levels_[i]=1;
}

void HandleGame::set_resources(){
    this->human=10;
    this->wood=100;
    this->rock=100;
}

void HandleGame::set_path(std::string path){
    this->save_path=std::move(path);
}
