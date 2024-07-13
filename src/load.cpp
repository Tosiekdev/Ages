//
// Created by tosiek on 04.12.2021.
//

#include "../headers/needed.h"

using namespace sf;
//Prepare everything
void Application::create_load(){
    //creating return button
    this->returningButton_.create(40, 100, 5, 5, "Return");

    //creating load button
    this->loadButton_.create(40, 100, 45, 245, "Load Save");
    this->loadButton_.setActive(false);

    //creating remove button
    this->removeButton_.create(40, 100, 45, 305, "Remove");
    this->removeButton_.setActive(false);

    //preparing tablets
    this->prepare_tablets();

    //creating navigation arrows
    this->down_.create_element("Textures/down.png", Vector2f(670, 500));
    this->up_.create_element("Textures/up.png", Vector2f(670, 10));

    //creating error messege
    this->errorMessage_.create(DEFAULT_FONT, 250, 10, "", 20);
}

//Main thread of app
void Application::load(){
    //event_
    this->l_handle_event();

    //do sth
    this->l_stuff();

    //display
    this->display_load();
}

//Handling user input
void Application::l_handle_event(){
    while(this->screen_.pollEvent(this->e_)){
        //exit
        if(this->e_.type == Event::Closed) this->screen_.close();
        if((Keyboard::isKeyPressed(Keyboard::Escape))) this->exitWindow_.create(this->screen_, this->scene_);

        //events for pressing mouse
        if(Mouse::isButtonPressed(Mouse::Left)){
            //handling mouse pos
            int i=Mouse::getPosition(this->screen_).x;
            int j=Mouse::getPosition(this->screen_).y;

            //return button
            if(this->returningButton_.onClick(i, j)) scene_=buildings::Scene::MENU;

            //down_ button
            if(this->down_.onClick(i, j)){
                this->downLevel_++;
                this->focusedTablet_--;
                this->prepare_tablets();
                this->prepare_focused_tablets();
            }

            //up_ button
            if(this->up_.onClick(i, j)){
                if(this->downLevel_ > 0){
                    this->downLevel_--;
                    this->focusedTablet_++;
                }
                this->prepare_tablets();
                this->prepare_focused_tablets();
            }

            //remove button
            if(this->removeButton_.onClick(i, j)) this->remove_save();

            //load button
            if(this->loadButton_.onClick(i, j)){
                //this->create_game();
                gameWindow_.create(this->savePath_);
                scene_=buildings::Scene::GAME;
            }

            //tablets
            for(int a=0;a<5;a++){
                if(this->t_[a].onClick(i, j)){
                    this->focusedTablet_=a;
                    this->prepare_focused_tablets();
                }
            }
        }
    }
}

//Things to do with every frame
void Application::l_stuff(){
    bool a[10];
    //getting mouse _position
    int x=Mouse::getPosition(this->screen_).x;
    int y=Mouse::getPosition(this->screen_).y;

    //checking if any button is focussed
    a[8]=this->up_.onFocus(x, y);
    a[9]=this->down_.onFocus(x, y);
    a[5]=this->returningButton_.onFocus(x, y);
    a[6]=this->loadButton_.onFocus(x, y);
    a[7]=this->removeButton_.onFocus(x, y);
    for(int i=0;i<5;i++) //tablets
        a[i]=this->t_[i].TRIGGERED(x, y);

    //cursor_
    if(a[0] || a[1] || a[2] || a[3] || a[4] || a[5] || a[6] || a[7] || a[8] || a[9])
        this->cursor_.loadFromSystem(Cursor::Hand);
    else
        this->cursor_.loadFromSystem(Cursor::Arrow);
    this->screen_.setMouseCursor(this->cursor_);
}

//Frame drawing
void Application::display_load(){
    this->screen_.clear(Color::White);

    //background
    this->screen_.draw(this->backgroundMenuSprite_);

    //buttons
    this->returningButton_.show(this->screen_);
    this->loadButton_.show(this->screen_);
    this->removeButton_.show(this->screen_);

    //tablets
    for(int i=0;i<5;i++)
        this->t_[i].draw(this->screen_);

    this->errorMessage_.show(this->screen_);

    //controls
    this->down_.draw_it(this->screen_);
    this->up_.draw_it(this->screen_);

    this->screen_.display();
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
        if(nr_line-this->downLevel_ >= 0 && nr_line - this->downLevel_ <= 4){
            if(!save_name.empty())
                this->t_[nr_line - this->downLevel_].create_tablet(save_name, pos);
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
    if(this->focusedTablet_ >= 0 && this->focusedTablet_ < 5){
        this->t_[this->focusedTablet_].focussed();
        if(this->t_[this->focusedTablet_].return_name() != "-:-"){
            this->savePath_= this->t_[this->focusedTablet_].return_name() + ".txt";
            this->loadButton_.setActive(true);
            this->removeButton_.setActive(true);
        }
        else{
            this->loadButton_.setActive(false);
            this->removeButton_.setActive(false);
        }
    }
    else{
        this->loadButton_.setActive(false);
        this->removeButton_.setActive(false);
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
            if(to_copy!=this->t_[this->focusedTablet_].return_name() && !to_copy.empty())
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

        this->prepare_tablets();
        this->errorMessage_.setCaption("File removed succesfully!");
    }
    else{
        this->errorMessage_.setCaption("Failed to remove file!"+ std::to_string(removing));
    }
}

