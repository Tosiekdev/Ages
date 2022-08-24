//
// Created by tosiek on 04.12.2021.
//

#include "../headers/needed.h"

using namespace sf;

//prepare everything
void Application::create_create(){
    //Buttons
    this->returnButton_.create(40, 100, 5, 5, "Return");
    this->cancelButton_.create(40, 100, 270, 310, "Cancel");
    this->okButton_.create(40, 100, 405, 310, "OK");

    //Space for input
    this->plank_.loadFromFile(PLANK);
    this->space_.setPosition(Vector2f(250, 200));
    this->space_.setTexture(this->plank_);
    this->space_.setScale(0.5, 0.5);

    //Caption
    this->label1_.create(DEFAULT_FONT, 320, 205, "Enter name:", 30);
    this->label2_.create(DEFAULT_FONT, 275, 275, "", 20);

    //Textbox
    this->t1_.set_position(320, 240);
    this->obstacleT_.loadFromFile("Textures/przeszkoda.png");
    this->obstacleS_.setTexture(this->obstacleT_);
    this->obstacleS_.setPosition(Vector2f(480, 245));
}

//Window
void Application::create(){
    //event
    this->c_handle_event();

    //do sth
    this->c_stuff();

    //display
    this->display_create();
}

//Event handling
void Application::c_handle_event(){
    while(this->screen_.pollEvent(this->e_)){
        //closing
        if(this->e_.type == Event::Closed) this->screen_.close();
        if((Keyboard::isKeyPressed(Keyboard::Escape))) this->exitWindow_.create(this->screen_, this->scene_);

        //starting game when proper name is entered
        if(Keyboard::isKeyPressed(Keyboard::Enter)){
            if(this->t1_.return_caption() != ""){
                string erro=this->create_city(this->t1_.return_caption());
                if(erro==""){
                    this->gameWindow_.create(this->savePath_);
                    this->scene_=4;
                }
                this->label2_.setCaption(erro);
            }
        }


        if(Mouse::isButtonPressed(Mouse::Left)){
            int i=Mouse::getPosition(this->screen_).x;
            int j=Mouse::getPosition(this->screen_).y;

            //doing nothing buttons
            if(this->returnButton_.onClick(i, j)) this->scene_=1;
            if(this->cancelButton_.onClick(i, j)) this->scene_=1;

            //same as when you hit enter
            if(this->okButton_.onClick(i, j)){
                if(this->t1_.return_caption() != ""){
                    string erro=this->create_city(this->t1_.return_caption());
                    if(erro==""){
                        this->gameWindow_.create(this->savePath_);
                        this->scene_=4;
                    }
                    this->label2_.setCaption(erro);
                }
            }
        }

        //making textbox working
        if(this->e_.type == Event::TextEntered){
            if((this->e_.text.unicode > 47 && this->e_.text.unicode < 58) || (this->e_.text.unicode > 64 && this->e_.text.unicode < 91) || (this->e_.text.unicode > 96 && this->e_.text.unicode < 123)){
                char a=static_cast<char>(this->e_.text.unicode);
                this->t1_.actualize(a);
            }
            if(this->e_.text.unicode == 8) this->t1_.erase();
        }
    }
}

//Stuff to do
void Application::c_stuff(){
    bool a[3];
    int x=Mouse::getPosition(this->screen_).x;
    int y=Mouse::getPosition(this->screen_).y;

    //cool animation
    a[0]=this->returnButton_.onFocus(x, y);
    a[1]=this->okButton_.onFocus(x, y);
    a[2]=this->cancelButton_.onFocus(x, y);

    //cursor_
    if(a[0] || a[1] || a[2])
        this->cursor_.loadFromSystem(Cursor::Hand);
    else
        this->cursor_.loadFromSystem(Cursor::Arrow);
    this->screen_.setMouseCursor(this->cursor_);

    //hiding extra text
    while(this->textbox_rect()){
        this->t1_.hide();
    }
}

//Display everything
void Application::display_create(){
    this->screen_.clear(Color::White);

    //back
    this->screen_.draw(this->backgroundMenuSprite_);
    this->screen_.draw(this->space_);

    //labels
    this->label1_.show(this->screen_);
    this->label2_.show(this->screen_);

    //textbox
    this->t1_.show(this->screen_);
    this->screen_.draw(this->obstacleS_);

    //buttons
    this->okButton_.show(this->screen_);
    this->cancelButton_.show(this->screen_);
    this->returnButton_.show(this->screen_);

    this->screen_.display();
}

//Checking if entered text is too long
bool Application::textbox_rect(){
    if(this->t1_.return_text().getGlobalBounds().intersects(this->obstacleS_.getGlobalBounds()))
        return true;
    return false;
}
