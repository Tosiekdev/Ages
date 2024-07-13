//
// Created by tosiek on 15.09.22.
//

#include "../../headers/buildings-windows/handlebank.h"

void HandleBank::handle_events(sf::Event &event, sf::RenderWindow &window, buildings::Scene &scene){
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

void HandleBank::do_stuff(sf::RenderWindow &window){
    bool a[1];
    int x=sf::Mouse::getPosition(window).x;
    int y=sf::Mouse::getPosition(window).y;

    //cool animation
    a[0]=returnToGame_.onFocus(x, y);

    if(a[0])
        cursor_.loadFromSystem(sf::Cursor::Hand);
    else
        cursor_.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor_);
}

void HandleBank::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    returnToGame_.show(window);

    //resource info_
    show_resources(window);

    //building_ info_
    info_.show(window);
    f_current.show(window);
    f_next.show(window);
    f_capacity.show(window);
    f_next_capacity.show(window);


    window.display();
}

void HandleBank::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                        int *iron,
                        int *bld) {
//for resource info_
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    resource_look();

    //info_
    crete_info();
    info_.setCaption("Bank is place where money are created. You can also\n"
                          "make deals with other villages here. Higher bank's level\n"
                          "gives you more money and better position_ at marketplace.");
    int bank=*building_;
    f_current.create(DEFAULT_FONT,400,300,"Current Money growth: "+
                                                std::to_string(bank*3*60)+"coins/minute",30);
    f_current.center();
    f_next.create(DEFAULT_FONT,400,350,"Next level money growth: "+
                                             std::to_string((bank+1)*3*60)+"coins/minute",30);
    f_next.center();
    f_capacity.create(DEFAULT_FONT,400,400,"Current safe capacity: "+
                                                 std::to_string(bank*2048)+" coins",30);
    f_capacity.center();
    f_next_capacity.create(DEFAULT_FONT,400,450,"Next level safe capacity: "+
                                                      std::to_string((bank+1)*2048)+" coins",30);
    f_next_capacity.center();

    //buttons
    create_return_button();
}
