//
// Created by tosiek on 04.12.2021.
//

#include "../headers/needed.h"

using namespace sf;
//Prepare everything
void Application::create_load(){
    //creating return button
    returningButton_.create(40, 100, 5, 5, "Return");

    //creating load button
    loadButton_.create(40, 100, 45, 245, "Load Save");
    loadButton_.setActive(false);

    //creating remove button
    removeButton_.create(40, 100, 45, 305, "Remove");
    removeButton_.setActive(false);

    //preparing tablets
    prepare_tablets();

    //creating navigation arrows
    down_.create_element("Textures/down.png", Vector2f(670, 500));
    up_.create_element("Textures/up.png", Vector2f(670, 10));

    //creating error messege
    errorMessage_.create(DEFAULT_FONT, 250, 10, "", 20);
}

//Main thread of app
void Application::load(){
    //event_
    l_handle_event();

    //do sth
    l_stuff();

    //display
    display_load();
}

//Handling user input
void Application::l_handle_event(){
    while(screen_.pollEvent(e_)){
        //exit
        if(e_.type == Event::Closed) screen_.close();
        if((Keyboard::isKeyPressed(Keyboard::Escape))) exitWindow_.create(screen_, scene_);

        //events for pressing mouse
        if(Mouse::isButtonPressed(Mouse::Left)){
            //handling mouse pos
            int i=Mouse::getPosition(screen_).x;
            int j=Mouse::getPosition(screen_).y;

            //return button
            if(returningButton_.onClick(i, j)) scene_=buildings::Scene::MENU;

            //down_ button
            if(down_.onClick(i, j)){
                downLevel_++;
                focusedTablet_--;
                prepare_tablets();
                prepare_focused_tablets();
            }

            //up_ button
            if(up_.onClick(i, j)){
                if(downLevel_ > 0){
                    downLevel_--;
                    focusedTablet_++;
                }
                prepare_tablets();
                prepare_focused_tablets();
            }

            //remove button
            if(removeButton_.onClick(i, j)) remove_save();

            //load button
            if(loadButton_.onClick(i, j)){
                //create_game();
                gameWindow_.create(savePath_);
                scene_=buildings::Scene::GAME;
            }

            //tablets
            for(int a=0;a<5;a++){
                if(t_[a].onClick(i, j)){
                    focusedTablet_=a;
                    prepare_focused_tablets();
                }
            }
        }
    }
}

//Things to do with every frame
void Application::l_stuff(){
    bool a[10];
    //getting mouse _position
    int x=Mouse::getPosition(screen_).x;
    int y=Mouse::getPosition(screen_).y;

    //checking if any button is focussed
    a[8]=up_.onFocus(x, y);
    a[9]=down_.onFocus(x, y);
    a[5]=returningButton_.onFocus(x, y);
    a[6]=loadButton_.onFocus(x, y);
    a[7]=removeButton_.onFocus(x, y);
    for(int i=0;i<5;i++) //tablets
        a[i]=t_[i].TRIGGERED(x, y);

    //cursor_
    if(a[0] || a[1] || a[2] || a[3] || a[4] || a[5] || a[6] || a[7] || a[8] || a[9])
        cursor_.loadFromSystem(Cursor::Hand);
    else
        cursor_.loadFromSystem(Cursor::Arrow);
    screen_.setMouseCursor(cursor_);
}

//Frame drawing
void Application::display_load(){
    screen_.clear(Color::White);

    //background
    screen_.draw(backgroundMenuSprite_);

    //buttons
    returningButton_.show(screen_);
    loadButton_.show(screen_);
    removeButton_.show(screen_);

    //tablets
    for(int i=0;i<5;i++)
        t_[i].draw(screen_);

    errorMessage_.show(screen_);

    //controls
    down_.draw_it(screen_);
    up_.draw_it(screen_);

    screen_.display();
}

//Reading data to create tablets
void Application::prepare_tablets(){
    //setting _position
    Vector2f pp=Vector2f(200,40);//very soft

    for(auto & i:t_){
        i.create_tablet("-:-",pp);
        pp+=Vector2f(0,110);
    }

    //opening files and reading saves
    std::fstream plik;
    Vector2f pos=Vector2f(200,40);
    std::string save_name;
    plik.open("all_saves.txt",std::ios::in);
    int nr_line=0;
    while(!plik.eof()){

        //reading line
        std::getline(plik,save_name);

        //setting proper name_
        if(nr_line-downLevel_ >= 0 && nr_line - downLevel_ <= 4){
            if(!save_name.empty())
                t_[nr_line - downLevel_].create_tablet(save_name, pos);
            pos+=Vector2f(0,110);
        }

        //increase line number
        nr_line++;
    }
    plik.close();
}

//Changing focused tablet's texture_
void Application::prepare_focused_tablets(){
    //resetting focus_
    for(auto & i:t_) i.unfocused();

    //preparing to load
    if(focusedTablet_ >= 0 && focusedTablet_ < 5){
        t_[focusedTablet_].focussed();
        if(t_[focusedTablet_].return_name() != "-:-"){
            savePath_= t_[focusedTablet_].return_name() + ".txt";
            loadButton_.setActive(true);
            removeButton_.setActive(true);
        }
        else{
            loadButton_.setActive(false);
            removeButton_.setActive(false);
        }
    }
    else{
        loadButton_.setActive(false);
        removeButton_.setActive(false);
    }
}

//Removing save_
void Application::remove_save(){
    //preparing save_ to delete
    int removing=remove(savePath_.c_str());

    //updating all saves file
    if(removing==0){
        //copying saves names
        std::fstream original,copied;
        original.open("all_saves.txt",std::ios::in);
        copied.open("all_copies.txt",std::ios::out);
        std::string to_copy;
        while(!original.eof()){
            getline(original,to_copy);
            if(to_copy!=t_[focusedTablet_].return_name() && !to_copy.empty())
                copied << to_copy << std::endl;
        }
        original.close();
        copied.close();

        //reloading tablets
        original.open("all_saves.txt",std::ios::out);
        copied.open("all_copies.txt",std::ios::in);
        while(!copied.eof()){
            getline(copied,to_copy);
            if(to_copy.empty())
                original << to_copy << std::endl;
        }
        original.close();
        copied.close();

        prepare_tablets();
        errorMessage_.setCaption("File removed succesfully!");
    }
    else{
        errorMessage_.setCaption("Failed to remove file!"+ std::to_string(removing));
    }
}

