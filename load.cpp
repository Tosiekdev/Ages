//
// Created by tosiek on 04.12.2021.
//

#include "needed.h"

using namespace sf;
using namespace std;

//Prepare everything
void Application::create_load(){
    //creating return button
    this->returning_button.create(40,100,5,5,"Return");

    //creating load button
    this->load_button.create(40,100,45,245,"Load Save");
    this->load_button.setActive(false);

    //creating remove button
    this->remove_button.create(40,100,45,305,"Remove");
    this->remove_button.setActive(false);

    //preparing tablets
    this->prepare_tablets();

    //creating navigation arrows
    this->down.create_element("Textures/down.png",Vector2f(670,500));
    this->up.create_element("Textures/up.png",Vector2f(670,10));

    //creating error messege
    this->error_message.create(DEFAULT_FONT,250,10,"",20);
}

//Main thread of app
void Application::load(){
    //event
    this->l_handle_event();

    //do sth
    this->l_stuff();

    //display
    this->display_load();
}

//Handling user input
void Application::l_handle_event(){
    while(this->screen.pollEvent(this->e)){
        //exit
        if(this->e.type==Event::Closed) this->screen.close();
        if((Keyboard::isKeyPressed(Keyboard::Escape))) this->exitWindow.create(this->screen,this->scene);

        //events for pressing mouse
        if(Mouse::isButtonPressed(Mouse::Left)){
            //handling mouse pos
            int i=Mouse::getPosition(this->screen).x;
            int j=Mouse::getPosition(this->screen).y;

            //return button
            if(this->returning_button.onClick(i,j)) this->scene=1;

            //down button
            if(this->down.onClick(i,j)){
                this->down_level++;
                this->focused_tablet--;
                this->prepare_tablets();
                this->prepare_focused_tablets();
            }

            //up button
            if(this->up.onClick(i,j)){
                if(this->down_level>0){
                    this->down_level--;
                    this->focused_tablet++;
                }
                this->prepare_tablets();
                this->prepare_focused_tablets();
            }

            //remove button
            if(this->remove_button.onClick(i,j)) this->remove_save();

            //load button
            if(this->load_button.onClick(i,j)){
                this->create_game();
                this->scene=4;
            }

            //tablets
            for(int a=0;a<5;a++){
                if(this->t[a].onClick(i,j)){
                    this->focused_tablet=a;
                    this->prepare_focused_tablets();
                }
            }
        }
    }
}

//Things to do with every frame
void Application::l_stuff(){
    bool a[10];
    //getting mouse position
    int x=Mouse::getPosition(this->screen).x;
    int y=Mouse::getPosition(this->screen).y;

    //checking if any button is focussed
    a[8]=this->up.onFocus(x,y);
    a[9]=this->down.onFocus(x,y);
    a[5]=this->returning_button.onFocus(x,y);
    a[6]=this->load_button.onFocus(x,y);
    a[7]=this->remove_button.onFocus(x,y);
    for(int i=0;i<5;i++) //tablets
        a[i]=this->t[i].TRIGGERED(x,y);

    //cursor
    if(a[0] || a[1] || a[2] || a[3] || a[4] || a[5] || a[6] || a[7] || a[8] || a[9])
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    this->screen.setMouseCursor(this->cursor);
}

//Frame drawing
void Application::display_load(){
    this->screen.clear(Color::White);

    //background
    this->screen.draw(this->background_menu_sprite);

    //buttons
    this->returning_button.show(this->screen);
    this->load_button.show(this->screen);
    this->remove_button.show(this->screen);

    //tablets
    for(int i=0;i<5;i++)
        this->t[i].draw(this->screen);

    this->error_message.show(this->screen);

    //controls
    this->down.draw_it(this->screen);
    this->up.draw_it(this->screen);

    this->screen.display();
}

//Reading data to create tablets
void Application::prepare_tablets(){
    //setting position
    Vector2f pp=Vector2f(200,40);//very soft

    for(int i=0;i<5;i++){
        this->t[i].create_tablet("-:-",pp);
        pp+=Vector2f(0,110);
    }

    //opening files and reading saves
    fstream plik;
    Vector2f pos=Vector2f(200,40);
    string save_name;
    plik.open("all_saves.txt",ios::in);
    int nr_line=0;
    while(!plik.eof()){

        //reading line
        getline(plik,save_name);

        //setting proper name
        if(nr_line-this->down_level>=0 && nr_line-this->down_level<=4){
            if(save_name!="")
                this->t[nr_line-this->down_level].create_tablet(save_name,pos);
            pos+=Vector2f(0,110);
        }

        //increase line number
        nr_line++;
    }
    plik.close();
}

//Changing focused tablet's texture
void Application::prepare_focused_tablets(){
    //resetting focus
    for(int i=0;i<5;i++) this->t[i].notfocussed();

    //preparing to load
    if(this->focused_tablet>=0 && this->focused_tablet<5){
        this->t[this->focused_tablet].focussed();
        if(this->t[this->focused_tablet].return_name()!="-:-"){
            this->save_path=this->t[this->focused_tablet].return_name()+".txt";
            this->load_button.setActive(true);
            this->remove_button.setActive(true);
        }
        else{
            this->load_button.setActive(false);
            this->remove_button.setActive(false);
        }
    }
    else{
        this->load_button.setActive(false);
        this->remove_button.setActive(false);
    }
}

//Removing save
void Application::remove_save(){
    //preparing save to delete
    int b=this->save_path.length()+1;
    char a[b]={0};
    for(int z=0;z<b;z++) a[z]=this->save_path[z];
    int removing=remove(a);

    //updating all saves file
    if(removing==0){
        //copying saves names
        fstream original,copied;
        original.open("all_saves.txt",ios::in);
        copied.open("all_copies.txt",ios::out);
        string to_copy;
        while(!original.eof()){
            getline(original,to_copy);
            if(to_copy!=this->t[this->focused_tablet].return_name()&&to_copy!="")
                copied << to_copy << endl;
        }
        original.close();
        copied.close();

        //reloading tablets
        original.open("all_saves.txt",ios::out);
        copied.open("all_copies.txt",ios::in);
        while(!copied.eof()){
            getline(copied,to_copy);
            if(to_copy!="")
                original << to_copy << endl;
        }
        original.close();
        copied.close();

        this->prepare_tablets();
        this->error_message.setCaption("File removed succesfully!");
    }
    else{
        this->error_message.setCaption("Failed to remove file!");
    }
}

