//
// Created by tosiek on 04.12.2021.
//

#include "../headers/needed.h"

using namespace sf;

//prepare everything
void Application::create_create(){
    //Buttons
    returnButton_.create(40, 100, 5, 5, "Return");
    cancelButton_.create(40, 100, 270, 310, "Cancel");
    okButton_.create(40, 100, 405, 310, "OK");

    //Space for input
    plank_.loadFromFile(PLANK);
    space_.setPosition(Vector2f(250, 200));
    space_.setTexture(plank_);
    space_.setScale(0.5, 0.5);

    //Caption
    label1_.create(DEFAULT_FONT, 320, 205, "Enter name_:", 30);
    label2_.create(DEFAULT_FONT, 275, 275, "", 20);

    //Textbox
    t1_.set_position(320, 240);
    obstacleT_.loadFromFile("Textures/przeszkoda.png");
    obstacleS_.setTexture(obstacleT_);
    obstacleS_.setPosition(Vector2f(480, 245));
}

//Window
void Application::create(){
    //event_
    c_handle_event();

    //do sth
    c_stuff();

    //display
    display_create();
}

//Event handling
void Application::c_handle_event(){
    while(screen_.pollEvent(e_)){
        //closing
        if(e_.type == Event::Closed) screen_.close();
        if((Keyboard::isKeyPressed(Keyboard::Escape))) exitWindow_.create(screen_, scene_);

        //starting game when proper name_ is entered
        if(Keyboard::isKeyPressed(Keyboard::Enter)){
            if(t1_.return_caption().empty()){
                std::string erro = create_city(t1_.return_caption());
                if(erro.empty()){
                    gameWindow_.create(savePath_);
                    scene_=buildings::Scene::GAME;
                }
                label2_.setCaption(erro);
            }
        }


        if(Mouse::isButtonPressed(Mouse::Left)){
            int i=Mouse::getPosition(screen_).x;
            int j=Mouse::getPosition(screen_).y;

            //doing nothing buttons
            if(returnButton_.onClick(i, j)) scene_=buildings::Scene::MENU;
            if(cancelButton_.onClick(i, j)) scene_=buildings::Scene::MENU;

            //same as when you hit enter
            if(okButton_.onClick(i, j)){
                if(t1_.return_caption().empty()){
                    std::string erro=create_city(t1_.return_caption());
                    if(erro.empty()){
                        gameWindow_.create(savePath_);
                        scene_=buildings::Scene::GAME;
                    }
                    label2_.setCaption(erro);
                }
            }
        }

        //making textbox working
        if(e_.type == Event::TextEntered){
            if((e_.text.unicode > 47 && e_.text.unicode < 58) || (e_.text.unicode > 64 && e_.text.unicode < 91) || (e_.text.unicode > 96 && e_.text.unicode < 123)){
                char a=static_cast<char>(e_.text.unicode);
                t1_.actualize(a);
            }
            if(e_.text.unicode == 8) t1_.erase();
        }
    }
}

//Stuff to do
void Application::c_stuff(){
    bool a[3];
    int x=Mouse::getPosition(screen_).x;
    int y=Mouse::getPosition(screen_).y;

    //cool animation
    a[0]=returnButton_.onFocus(x, y);
    a[1]=okButton_.onFocus(x, y);
    a[2]=cancelButton_.onFocus(x, y);

    //cursor_
    if(a[0] || a[1] || a[2])
        cursor_.loadFromSystem(Cursor::Hand);
    else
        cursor_.loadFromSystem(Cursor::Arrow);
    screen_.setMouseCursor(cursor_);

    //hiding extra text
    while(textbox_rect()){
        t1_.hide();
    }
}

//Display everything
void Application::display_create(){
    screen_.clear(Color::White);

    //back
    screen_.draw(backgroundMenuSprite_);
    screen_.draw(space_);

    //labels
    label1_.show(screen_);
    label2_.show(screen_);

    //textbox
    t1_.show(screen_);
    screen_.draw(obstacleS_);

    //buttons
    okButton_.show(screen_);
    cancelButton_.show(screen_);
    returnButton_.show(screen_);

    screen_.display();
}

//Checking if entered text is too long
bool Application::textbox_rect(){
    if(t1_.return_text().getGlobalBounds().intersects(obstacleS_.getGlobalBounds()))
        return true;
    return false;
}
