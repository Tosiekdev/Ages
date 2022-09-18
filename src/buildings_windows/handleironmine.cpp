//
// Created by tosiek on 18.09.22.
//

#include "../../headers/buildings-windows/handleironmine.h"

void HandleIronMine::handle_events(sf::Event &event, sf::RenderWindow &window, int &scene){
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed) window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int i=sf::Mouse::getPosition(window).x;
            int j=sf::Mouse::getPosition(window).y;

            if(returnToGame_.onClick(i, j)){
                this->return_to_village(scene);
            }
        }
    }
}

void HandleIronMine::do_stuff(sf::RenderWindow &window){
    bool a[1];
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a[0]=returnToGame_.onFocus(x, y);

    if(a[0]){
        cursor_.loadFromSystem(sf::Cursor::Hand);
    }else{
        cursor_.loadFromSystem(sf::Cursor::Arrow);
    }
    window.setMouseCursor(cursor_);
}

void HandleIronMine::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    returnToGame_.show(window);

    //resource info_
    show_resources(window);

    //building_ info_
    info_.show(window);
    current_.show(window);
    next_.show(window);

    window.display();
}

void HandleIronMine::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                            int *iron, int *bld){
//for resource info
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    resource_look();

    //info_
    crete_info();
    info_.setCaption("In Iron Mine humans simply digging the hole, seeking for iron.\n"
                     "Higher gives you more iron!");
    int lvl=*building_;
    current_.create(DEFAULT_FONT, 400, 300, "Current iron growth: " +
                                             std::to_string(lvl*60) + " iron/minute", 30);
    current_.center();
    next_.create(DEFAULT_FONT, 400, 350, "Next level population growth: " +
                                          std::to_string((lvl+1)*60) + " iron/minute", 30);
    next_.center();

    //buttons
    create_return_button();
}
