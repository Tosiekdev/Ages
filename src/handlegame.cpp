//
// Created by tosiek on 16.02.2022.
//

#include <utility>

#include "../headers/handlegame.h"

void HandleGame::create(std::string path){
    //assign path
    set_path(std::move(path));

    //buttons
    returnToMenu_.create(40, 100, 5, 5, "Return");
    save_.create(40, 100, 130, 5, "Save");

    //set clock to 0
    resourceClock_.restart();
    humanClock_.restart();

    //for town hall
    float y_position=205.f;
    for(int i=0; i<10; i++){
        thWindow_.crete_ub(&(building_[i]), sf::Vector2f(20, y_position), i);
        y_position+=100.f;
    }

    create_buildings();

    //resource plank
    resourcePlank_.create_obstacle(PLANK, sf::Vector2f(0.4, 0.43),
                                   sf::Vector2f(564,0));
    resourceMan_.create_obstacle("Textures/human.png", sf::Vector2f(0.16, 0.16),
                                 sf::Vector2f(570,5));
    resourceRock_.create_obstacle("Textures/rock.png", sf::Vector2f(0.25, 0.25),
                                  sf::Vector2f(570, 33));
    resourceWood_.create_obstacle("Textures/wood.png", sf::Vector2f(0.08, 0.08),
                                  sf::Vector2f(570, 61));
    resourceMoney_.create_obstacle("Textures/coin.png", sf::Vector2f(0.08, 0.08),
                                  sf::Vector2f(570, 87));
    resourceIron_.create_obstacle("Textures/iron.png", sf::Vector2f(0.1, 0.1),
                                   sf::Vector2f(572, 109));

    //resource numbers
    lHuman_.create(DEFAULT_FONT, 620, 5, std::to_string(human_), 20);
    lRock_.create(DEFAULT_FONT, 620, 33, std::to_string(rock_), 20);
    lWood_.create(DEFAULT_FONT, 620, 61, std::to_string(wood_), 20);
    lMoney_.create(DEFAULT_FONT, 620, 89, std::to_string(money_), 20);
    lIron_.create(DEFAULT_FONT, 620, 117, std::to_string(iron_), 20);

    //map
    mapIcon_.create_element("Textures/default.png",sf::Vector2f(500,5));
}

void HandleGame::main_loop(sf::RenderWindow &window, int &scene){
    handle_event(scene,window);
    do_stuff(window);
    display(window);
}

void HandleGame::handle_event(int &scene, sf::RenderWindow &window){
    while(window.pollEvent(e_)){
        //exit
        if(e_.type == sf::Event::Closed){
            window.close();
        }
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))){
            exitWindow.create(window, scene);
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //getting mouse _position
            int i = sf::Mouse::getPosition(window).x;
            int j = sf::Mouse::getPosition(window).y;

            //Returning button event_
            if(returnToMenu_.onClick(i, j)){
                deactivate_buildings();
                wsWindow_.create(window, scene);
            }

            //map
            if(mapIcon_.onClick(i,j)){
                world_.create();
                scene=15;
            }

            //Checking if entered building
            check_building_clicked(scene,i,j);

            //saving game
            if(save_.onClick(i, j)) save_game();
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
    a.push_back(returnToMenu_.onFocus(x, y));
    a.push_back(save_.onFocus(x, y));

    //other cool animations
    a.push_back(mapIcon_.onFocus(x,y));

    //cursor_ change
    if(std::any_of(a.begin(),a.end(),[](bool i){return i;}))
        cursor_.loadFromSystem(sf::Cursor::Hand);
    else
        cursor_.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor_);

    this->activate_buildings();
}

void HandleGame::display(sf::RenderWindow &window){
    window.clear(sf::Color::Green);

    //buttons
    returnToMenu_.show(window);
    save_.show(window);

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

    //map
    mapIcon_.draw_it(window);

    //buildings
    for(auto &i:building_)
        i.show(window);

    window.display();
}

void HandleGame::deactivate_buildings(){
    for(auto &i:building_)
        i.deactivate();
}

void HandleGame::activate_buildings(){
    for(auto &i:building_)
        i.activate();
}

void HandleGame::create_buildings(){
    //load data
    saveSystem_.load_save(savePath_, levels_, thWindow_, name_, human_, wood_, rock_, money_, iron_,
                          building_, barracksWindow_);

    //make everything done
    prepare_buildings();
}

void HandleGame::prepare_buildings(){
    //creating every building
    building_[0].create_building("Academy", "Textures/Buildings/academy.png",levels_[0],
                                       sf::Vector2f(250,300), 100, 75, 10);
    building_[1].create_building("Barracks", "Textures/Buildings/barracks.png",levels_[1],
                                       sf::Vector2f(50,300), 75, 75, 7);
    building_[2].create_building("Church", "Textures/Buildings/church.png",levels_[2],
                                       sf::Vector2f(300,150), 50, 150, 10);
    building_[3].create_building("Farm", "Textures/Buildings/farm.png",levels_[3],
                                       sf::Vector2f(600,450), 20, 60, 2);
    building_[4].create_building("Lumber mill", "Textures/Buildings/lumbermill.png",levels_[4],
                                       sf::Vector2f(400,450), 65, 15, 2);
    building_[5].create_building("Stone pit", "Textures/default.png",levels_[5],
                                       sf::Vector2f(600,250), 15, 65, 2);
    building_[6].create_building("Town Hall", "Textures/Buildings/town_hall.png",levels_[6],
                                       sf::Vector2f(100,100), 75, 75, 12);
    building_[7].create_building("Warehouse", "Textures/Buildings/magazine.png",levels_[7],
                                       sf::Vector2f(75,450), 100, 50, 6);
    building_[8].create_building("Bank", "Textures/default.png",levels_[8],
                                       sf::Vector2f(465,150), 100, 50, 6);
    building_[9].create_building("Iron Mine", "Textures/default.png",levels_[9],
                                 sf::Vector2f(250,450), 100, 50, 6);

    //updating building levels in town hall
    for(int i=0; i<10; i++){
        thWindow_.ub_update_level(i);
    }
}

void HandleGame::save_game(){
    saveSystem_.save_game(savePath_, levels_, thWindow_, name_, human_, wood_, rock_, money_, iron_, barracksWindow_);
}

void HandleGame::assign_levels(){
    for(int i=0; i<10; i++)
        levels_[i]=building_[i].get_level();
}

void HandleGame::clocks(int scene){
    if(scene>3){
        if(humanClock_.getElapsedTime().asSeconds()>=10){
            //increasing amount of people
            float time_passed = (float)humanClock_.getElapsedTime().asSeconds();
            human_+=static_cast<int>(time_passed * 0.12 * levels_[3]);
            humanClock_.restart();
        }
        if(resourceClock_.getElapsedTime().asSeconds() >= 1){
            //increasing resources
            int time_passed = (int)resourceClock_.getElapsedTime().asSeconds();
            rock_+=time_passed*levels_[5];
            wood_+=time_passed*levels_[4];
            money_+=time_passed*3*levels_[8];
            iron_+=time_passed*levels_[9];

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
            }else{
                lWood_.setColor(sf::Color::Black);
            }

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
            }else{
                lHuman_.setColor(sf::Color::Black);
            }

            //full safe
            if(money_>=levels_[8]*2048){
                money_=levels_[8]*2048;
                lMoney_.setColor(sf::Color::Red);
            }else{
                lMoney_.setColor(sf::Color::Black);
            }

            //setting look_ of resource info
            if(scene==4){
                lHuman_.setCaption(std::to_string(human_));
                lRock_.setCaption(std::to_string(rock_));
                lWood_.setCaption(std::to_string(wood_));
                lMoney_.setCaption(std::to_string(money_));
                lIron_.setCaption(std::to_string(iron_));
            }else{
                lHuman_.setCaption("People: " + std::to_string(human_));
                lRock_.setCaption("Stone: " + std::to_string(rock_));
                lWood_.setCaption("Wood: " + std::to_string(wood_));
                lMoney_.setCaption("Money: "+std::to_string(money_));
                lIron_.setCaption("Iron: "+std::to_string(iron_));
            }

            //restarting counter
            resourceClock_.restart();
        }

        //upgrading buildings in town hall
        for(int i=0; i<10; i++){
            if(thWindow_.ub_get_time(i) >= 1){
                if(thWindow_.ub_update_timer(i,thWindow_.ub_get_time(i)) == 3)
                    assign_levels();
                thWindow_.ub_reset_timer(i);
            }
        }

        //training units
        barracksWindow_.update_timer();
    }
}

void HandleGame::set_ub_left(int index, float time, float th){
    thWindow_.set_ub_left(index, time, th);
}

void HandleGame::set_levels(){
    for(int i=0; i<3; i++) levels_[i]=0;
    for(int i=3; i<10; i++) levels_[i]=1;
}

void HandleGame::set_resources(){
    //set default resources (for new game)
    human_=10;
    wood_=100;
    rock_=100;
    money_=200;
    iron_=50;

    //set quantity of all units to 0
    std::array<int,9> levels{};
    barracksWindow_.set_units_quantity(levels);
}

void HandleGame::set_path(std::string path){
    savePath_=std::move(path);
}

void HandleGame::check_building_clicked(int &scene, int i, int j){
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
    if(building_[1].isClicked(i, j)){
        barracksWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                               &rock_,&wood_,&money_,&iron_, &levels_[1]);
        scene=11;
    }
    if(building_[2].isClicked(i, j)){
        churchWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                             &rock_,&wood_,&money_,&iron_, &levels_[2]);
        scene=12;
    }
    if(building_[8].isClicked(i,j)){
        bankWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                           &rock_,&wood_,&money_,&iron_, &levels_[8]);
        scene=13;
    }
    if(building_[9].isClicked(i,j)){
        ironMineWindow_.create(&lHuman_,&lRock_,&lWood_,&lMoney_,&lIron_,&human_,
                               &rock_,&wood_,&money_,&iron_, &levels_[8]);
        scene=14;
    }
}
