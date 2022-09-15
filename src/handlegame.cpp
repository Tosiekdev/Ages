//
// Created by tosiek on 16.02.2022.
//

#include "../headers/handlegame.h"

void HandleGame::create(std::string path){
    //assign path
    this->set_path(path);

    //buttons
    this->returnToMenu_.create(40, 100, 5, 5, "Return");
    this->save.create(40,100,130,5,"Save");

    //set clock to 0
    resourceClock_.restart();
    humanClock_.restart();

    //for town hall
    float y_position=205.f;
    for(int i=0; i<10; i++){
        this->thWindow_.crete_ub(&(this->building_[i]), sf::Vector2f(20, y_position), i);
        y_position+=100.f;
    }

    this->create_buildings();

    //resource plank
    resourcePlank_.create_obstacle(PLANK, sf::Vector2f(0.4, 0.43),
                                   sf::Vector2f(564,0));
    resourceMan_.create_obstacle("Textures/human.png", sf::Vector2f(0.16, 0.16),
                                 sf::Vector2f(570,5));
    resourceRock_.create_obstacle("Textures/rock.png", sf::Vector2f(0.25, 0.25),
                                  sf::Vector2f(570, 33));
    resourceWood_.create_obstacle("Textures/wood.png", sf::Vector2f(0.08, 0.08),
                                  sf::Vector2f(570, 61));
    resourceMoney_.create_obstacle("Textures/wood.png", sf::Vector2f(0.08, 0.08),
                                  sf::Vector2f(570, 89));
    resourceIron_.create_obstacle("Textures/wood.png", sf::Vector2f(0.08, 0.08),
                                   sf::Vector2f(570, 117));

    //resource numbers
    lHuman_.create(DEFAULT_FONT, 620, 5, std::to_string(human_), 20);
    lRock_.create(DEFAULT_FONT, 620, 33, std::to_string(rock_), 20);
    lWood_.create(DEFAULT_FONT, 620, 61, std::to_string(wood_), 20);
    lMoney_.create(DEFAULT_FONT, 620, 89, std::to_string(money_), 20);
    lIron_.create(DEFAULT_FONT, 620, 117, std::to_string(iron_), 20);
}

void HandleGame::main_loop(sf::RenderWindow &window, int &scene){
    this->handle_event(scene,window);
    this->do_stuff(window);
    this->display(window);
}

void HandleGame::handle_event(int &scene, sf::RenderWindow &window){
    while(window.pollEvent(this->e_)){
        //exit
        if (this->e_.type == sf::Event::Closed) window.close();
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) this->exitWindow.create(window, scene);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //getting mouse _position
            int i = sf::Mouse::getPosition(window).x;
            int j = sf::Mouse::getPosition(window).y;

            //Returning button event
            if(returnToMenu_.onClick(i, j)){
                this->deactivate_buildings();
                this->wsWindow.create(window,scene);
            }

            //Buildings events
            if(building_[6].isClicked(i, j)){
                thWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                                 &rock_,&wood_,&money_,&iron_, &levels_[6]);
                scene=5;
            }
            if(building_[3].isClicked(i, j)){
                farmWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                                   &rock_,&wood_,&money_,&iron_, &levels_[3]);
                scene=6;
            }
            if(building_[4].isClicked(i, j)){
                lmWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                                 &rock_,&wood_,&money_,&iron_, &levels_[4]);
                scene=7;
            }
            if(building_[5].isClicked(i, j)){
                spWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                                 &rock_,&wood_,&money_,&iron_, &levels_[5]);
                scene=8;
            }
            if(building_[7].isClicked(i, j)){
                whWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                                 &rock_,&wood_,&money_,&iron_, &levels_[7]);
                scene=9;
            }
            if(building_[0].isClicked(i, j)){
                academyWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                                      &rock_,&wood_,&money_,&iron_, &levels_[0]);
                scene=10;
            }
            if(this->building_[1].isClicked(i, j)){
                barracksWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                                       &rock_,&wood_,&money_,&iron_, &levels_[1]);
                scene=11;
            }
            if(this->building_[2].isClicked(i, j)){
                churchWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                                     &rock_,&wood_,&money_,&iron_, &levels_[2]);
                scene=12;
            }
            if(building_[8].isClicked(i,j)){
                bankWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                                   &rock_,&wood_,&money_,&iron_, &levels_[8]);
                scene=13;
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
    for(auto &i:building_)
        a.push_back(i.onFocus(x, y));

    //cool button animation
    a.push_back(this->returnToMenu_.onFocus(x, y));
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
    this->returnToMenu_.show(window);
    this->save.show(window);

    //resource plank_
    resourcePlank_.draw(window);
    resourceMan_.draw(window);
    resourceRock_.draw(window);
    resourceWood_.draw(window);
    resourceMoney_.draw(window);
    resourceIron_.draw(window);
    //resource numbers
    lHuman_.show(window);
    lRock_.show(window);
    lWood_.show(window);
    lMoney_.show(window);
    lIron_.show(window);

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
    saveSystem.load_save(savePath_, levels_, thWindow_, name_, human_, wood_, rock_, money_, iron_,
                         building_);

    //make everything done
    this->prepare_buildings();
}

void HandleGame::prepare_buildings(){
    building_[0].create_building("Academy", "Textures/academy.png",levels_[0],
                                       sf::Vector2f(250,300), 100, 75, 10);
    building_[1].create_building("Barracks", "Textures/barracks.png",levels_[1],
                                       sf::Vector2f(50,300), 75, 75, 7);
    building_[2].create_building("Church", "Textures/church.png",levels_[2],
                                       sf::Vector2f(300,150), 50, 150, 10);
    building_[3].create_building("Farm", "Textures/farm.png",levels_[3],
                                       sf::Vector2f(600,450), 20, 60, 2);
    building_[4].create_building("Lumber mill", "Textures/lumbermill.png",levels_[4],
                                       sf::Vector2f(400,450), 65, 15, 2);
    building_[5].create_building("Stone pit", "Textures/default.png",levels_[5],
                                       sf::Vector2f(600,250), 15, 65, 2);
    building_[6].create_building("Town Hall", "Textures/town_hall.png",levels_[6],
                                       sf::Vector2f(100,100), 75, 75, 12);
    building_[7].create_building("Warehouse", "Textures/magazine.png",levels_[7],
                                       sf::Vector2f(75,450), 100, 50, 6);
    building_[8].create_building("Bank", "Textures/default.png",levels_[8],
                                       sf::Vector2f(465,150), 100, 50, 6);
    building_[9].create_building("Iron Mine", "Textures/default.png",levels_[9],
                                 sf::Vector2f(250,450), 100, 50, 6);
    for(int i=0; i<10; i++){
        this->thWindow_.ub_update_level(i);
    }
}

void HandleGame::save_game(){
    saveSystem.save_game(savePath_, levels_, thWindow_, name_, human_, wood_, rock_, money_, iron_);
}

void HandleGame::assign_levels(){
    for(int i=0; i<9; i++)
        levels_[i]=building_[i].get_level();
}

void HandleGame::clocks(int scene){
    if(scene>3){
        //increasing resources
        if(humanClock_.getElapsedTime().asSeconds()>=10){
            float time_passed = (float)humanClock_.getElapsedTime().asSeconds();
            human_+=static_cast<int>(time_passed * 0.12 * levels_[3]);
            humanClock_.restart();
        }
        if (resourceClock_.getElapsedTime().asSeconds() >= 1) {
            int time_passed = (int)resourceClock_.getElapsedTime().asSeconds();
            rock_+=time_passed*levels_[5];
            wood_+=time_passed*levels_[4];
            money_+=time_passed*3*levels_[8];
            iron_+=time_passed;

            //full magazine
            if(rock_ >= levels_[7] * 1296){
                rock_= levels_[7] * 1296;
                lRock_.setColor(sf::Color::Red);
            }else{
                lRock_.setColor(sf::Color::Black);
            }

            if(wood_ >= levels_[7] * 1296){
                wood_= levels_[7] * 1296;
                lWood_.setColor(sf::Color::Red);
            }else
                lWood_.setColor(sf::Color::Black);

            if(iron_>=levels_[7]*1296){
                iron_=levels_[7]*1296;
                lIron_.setColor(sf::Color::Red);
            }else{
                lIron_.setColor(sf::Color::Black);
            }

            //full farm
            if(human_ >= levels_[3] * 156){
                human_= levels_[3] * 156;
                lHuman_.setColor(sf::Color::Red);
            }else
                lHuman_.setColor(sf::Color::Black);

            //full safe
            if(money_>=levels_[8]*2048){
                money_=levels_[8]*2048;
                lMoney_.setColor(sf::Color::Red);
            }else{
                lMoney_.setColor(sf::Color::Black);
            }

            switch(scene){
                case 4:
                    lHuman_.setCaption(std::to_string(human_));
                    lRock_.setCaption(std::to_string(rock_));
                    lWood_.setCaption(std::to_string(wood_));
                    lMoney_.setCaption(std::to_string(money_));
                    lIron_.setCaption(std::to_string(iron_));
                    break;
                default:
                    lHuman_.setCaption("People: " + std::to_string(human_));
                    lRock_.setCaption("Stone: " + std::to_string(rock_));
                    lWood_.setCaption("Wood: " + std::to_string(wood_));
                    lMoney_.setCaption("Money: "+std::to_string(money_));
                    lIron_.setCaption("Iron: "+std::to_string(iron_));
                    break;
            }
            this->resourceClock_.restart();
        }
        //upgrading buildings in town hall
        for(int i=0; i<9; i++){
            if(thWindow_.ub_get_time(i) >= 1){
                if(thWindow_.ub_update_timer(i, this->thWindow_.ub_get_time(i)) == 3)
                    assign_levels();
                thWindow_.ub_reset_timer(i);
            }
        }
    }
}

void HandleGame::launch_th(sf::RenderWindow &window, int &scene){
    thWindow_.main_loop(this->e_, window, scene);
}

void HandleGame::launch_farm(sf::RenderWindow &window, int &scene){
    farmWindow_.main_loop(e_, window, scene);
}

void HandleGame::launch_lm(sf::RenderWindow &window, int &scene){
    lmWindow_.main_loop(e_, window, scene);
}

void HandleGame::launch_sp(sf::RenderWindow &window, int &scene){
    spWindow_.main_loop(e_, window, scene);
}

void HandleGame::launch_wh(sf::RenderWindow &window, int &scene){
    whWindow_.main_loop(e_, window, scene);
}

void HandleGame::launch_academy(sf::RenderWindow &window, int &scene){
    academyWindow_.main_loop(e_, window, scene);
}

void HandleGame::launch_barracks(sf::RenderWindow &window, int &scene){
    barracksWindow_.main_loop(e_, window, scene);
}

void HandleGame::launch_church(sf::RenderWindow &window, int &scene){
    churchWindow_.main_loop(e_, window, scene);
}

void HandleGame::launch_bank(sf::RenderWindow &window, int &scene){
    bankWindow_.main_loop(e_, window, scene);
}

void HandleGame::set_ub_left(int index, float time, float th){
    thWindow_.set_ub_left(index, time, th);
}

void HandleGame::set_levels(){
    for(int i=0; i<3; i++) levels_[i]=0;
    for(int i=3; i<9; i++) levels_[i]=1;
}

void HandleGame::set_resources(){
    human_=10;
    wood_=100;
    rock_=100;
    money_=200;
    iron_=50;
}

void HandleGame::set_path(std::string path){
    savePath_=std::move(path);
}
