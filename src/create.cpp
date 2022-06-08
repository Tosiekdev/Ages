//
// Created by tosiek on 04.12.2021.
//

#include "../headers/needed.h"

using namespace sf;

//prepare everything
void Application::create_create(){
    //Buttons
    this->return_button.create(40,100,5,5,"Return");
    this->cancel_button.create(40,100,270,310,"Cancel");
    this->ok_button.create(40,100,405,310,"OK");

    //Space for input
    this->plank.loadFromFile(PLANK);
    this->space.setPosition(Vector2f(250,200));
    this->space.setTexture(this->plank);
    this->space.setScale(0.5,0.5);

    //Caption
    this->label1.create(DEFAULT_FONT,320,205,"Enter name:",30);
    this->label2.create(DEFAULT_FONT,275,275,"",20);

    //Textbox
    this->t1.set_position(320,240);
    this->obstacle_t.loadFromFile("Textures/przeszkoda.png");
    this->obstacle_s.setTexture(this->obstacle_t);
    this->obstacle_s.setPosition(Vector2f(480,245));
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
    while(this->screen.pollEvent(this->e)){
        //closing
        if(this->e.type==Event::Closed) this->screen.close();
        if((Keyboard::isKeyPressed(Keyboard::Escape))) this->exitWindow.create(this->screen,this->scene);

        //starting game when proper name is entered
        if(Keyboard::isKeyPressed(Keyboard::Enter)){
            if(this->t1.return_caption()!=""){
                string erro=this->create_city(this->t1.return_caption());
                if(erro==""){
                    this->game_window.create(this->save_path);
                    this->scene=4;
                }
                this->label2.setCaption(erro);
            }
        }


        if(Mouse::isButtonPressed(Mouse::Left)){
            int i=Mouse::getPosition(this->screen).x;
            int j=Mouse::getPosition(this->screen).y;

            //doing nothing buttons
            if(this->return_button.onClick(i,j)) this->scene=1;
            if(this->cancel_button.onClick(i,j)) this->scene=1;

            //same as when you hit enter
            if(this->ok_button.onClick(i,j)){
                if(this->t1.return_caption()!=""){
                    string erro=this->create_city(this->t1.return_caption());
                    if(erro==""){
                        this->game_window.create(this->save_path);
                        this->scene=4;
                    }
                    this->label2.setCaption(erro);
                }
            }
        }

        //making textbox working
        if(this->e.type==Event::TextEntered){
            if((this->e.text.unicode>47 && this->e.text.unicode<58) || (this->e.text.unicode>64 && this->e.text.unicode<91) || (this->e.text.unicode>96 && this->e.text.unicode<123)){
                char a=static_cast<char>(this->e.text.unicode);
                this->t1.actualize(a);
            }
            if(this->e.text.unicode==8) this->t1.erease();
        }
    }
}

//Stuff to do
void Application::c_stuff(){
    bool a[3];
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    //cool animation
    a[0]=this->return_button.onFocus(x,y);
    a[1]=this->ok_button.onFocus(x,y);
    a[2]=this->cancel_button.onFocus(x,y);

    //cursor
    if(a[0] || a[1] || a[2])
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    this->screen.setMouseCursor(this->cursor);

    //hiding extra text
    while(this->textbox_rect()){
        this->t1.hide();
    }
}

//Display everything
void Application::display_create(){
    this->screen.clear(Color::White);

    //back
    this->screen.draw(this->background_menu_sprite);
    this->screen.draw(this->space);

    //labels
    this->label1.show(this->screen);
    this->label2.show(this->screen);

    //textbox
    this->t1.show(this->screen);
    this->screen.draw(this->obstacle_s);

    //buttons
    this->ok_button.show(this->screen);
    this->cancel_button.show(this->screen);
    this->return_button.show(this->screen);

    this->screen.display();
}

//Checking if entered text is too long
bool Application::textbox_rect(){
    if(this->t1.return_text().getGlobalBounds().intersects(this->obstacle_s.getGlobalBounds()))
        return true;
    return false;
}
