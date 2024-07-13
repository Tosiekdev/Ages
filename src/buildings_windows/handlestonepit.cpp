//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/buildings-windows/handlestonepit.h"

void HandleStonePit::handle_events(sf::Event &event,sf::RenderWindow &window, buildings::Scene &scene){
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed) window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int i=sf::Mouse::getPosition(window).x;
            int j=sf::Mouse::getPosition(window).y;

            if(returnToGame_.onClick(i, j)){
                return_to_village(scene);
            }
        }
    }
}

void HandleStonePit::do_stuff(sf::RenderWindow &window){
    bool a[1];
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a[0]=returnToGame_.onFocus(x, y);

    //changing cursor_
    if(a[0])
        cursor_.loadFromSystem(sf::Cursor::Hand);
    else
        cursor_.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor_);
}

void HandleStonePit::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    returnToGame_.show(window);

    //resource info_
    show_resources(window);

    //building_ info_
    info_.show(window);
    next.show(window);
    current.show(window);

    window.display();
}

void
HandleStonePit::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                       int *iron,
                       int *bld) {
    //for resource info_
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    resource_look();

    //info_
    crete_info();
    info_.setCaption("Stone Pit simply mine stone for upgrading buildings.\n"
                          "Higher level means, obviously, more stone!");
    int stone=*building_;
    current.create(DEFAULT_FONT,400,300,"",30);
    current.setCaption("Current stone growth: "+std::to_string(stone*60)+" rocks/minute");
    current.center();
    next.create(DEFAULT_FONT,400,350,"",30);
    next.setCaption("Next level_ stone growth: "+std::to_string((stone+1)*60)+" rocks/minute");
    next.center();

    //buttons
    create_return_button();
}
