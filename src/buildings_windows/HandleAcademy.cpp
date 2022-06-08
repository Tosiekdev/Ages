//
// Created by tosiek on 16.02.2022.
//

#include "../../headers/HandleAcademy.h"

void HandleAcademy::create(Label *lh, Label *lr, Label *lw, int *hn, int *rk, int *wd, int *bld){
    //for resource info
    this->assign_values(lh,lr,lw,hn,rk,wd,bld);

    //change resource look
    this->resource_look();

    //info
    this->crete_info();
    this->info.setCaption("In Academy you discover new technologies which can\n"
                          "improve yours army strength, or increase your resource\n"
                          "production. Upgrading Academy helps you to discover\n"
                          "more technologies!");

    //buttons
    this->create_return_button();
}

void HandleAcademy::handle_events(Event &event, RenderWindow &window, int &scene){
    while(window.pollEvent(event)) {
        if (event.type == Event::Closed) window.close();

        if(Mouse::isButtonPressed(Mouse::Left)) {
            int i = Mouse::getPosition(window).x;
            int j = Mouse::getPosition(window).y;

            if(this->return_to_game.onClick(i,j)){
                this->return_to_village(scene);
            }
        }
    }
}

void HandleAcademy::do_stuff(RenderWindow &window){
    std::vector<bool> a;
    int x=Mouse::getPosition(window).x;
    int y=Mouse::getPosition(window).y;

    //cool animation
    a.push_back(this->return_to_game.onFocus(x,y));

    Vector2i mouse_pos=Mouse::getPosition(window);

    if(std::any_of(a.begin(),a.end(),[](bool i){return i;}))
        this->cursor.loadFromSystem(Cursor::Hand);
    else
        this->cursor.loadFromSystem(Cursor::Arrow);
    window.setMouseCursor(this->cursor);
}

void HandleAcademy::display(RenderWindow &window){
    window.clear(Color::White);

    //buttons
    this->return_to_game.show(window);

    //resource info
    this->show_resources(window);

    //info
    this->info.show(window);

    window.display();
}
