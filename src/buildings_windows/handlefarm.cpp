//
// Created by tosiek on 09.02.2022.
//

#include "../../headers/buildings-windows/handlefarm.h"

void HandleFarm::handle_events(sf::Event &event, sf::RenderWindow &window, buildings::Scene &scene){
    while(window.pollEvent(event)){
        //closing window
        if(event.type==sf::Event::Closed){
            window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int i=sf::Mouse::getPosition(window).x;
            int j=sf::Mouse::getPosition(window).y;

            //returning to game's main window
            if(returnToGame_.onClick(i, j)){
                return_to_village(scene);
            }
        }
    }
}

void HandleFarm::do_stuff(sf::RenderWindow &window){
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

void HandleFarm::display(sf::RenderWindow &window){
    window.clear(sf::Color::White);

    //buttons
    returnToGame_.show(window);

    //resource info_
    show_resources(window);

    //building_ info_
    info_.show(window);
    fCurrent_.show(window);
    fNext_.show(window);
    fCapacity_.show(window);
    fNextCapacity_.show(window);


    window.display();
}

void HandleFarm::create(Label *lh, Label *lr, Label *lw, Label *lm, Label *li, int *hn, int *rk, int *wd, int *moni,
                        int *iron,
                        int *bld) {
    //for resource info
    assign_values(lh, lr, lw, lm, li, hn, rk, wd, bld, moni, iron);

    //change resource _look
    resource_look();

    //info_
    crete_info();
    info_.setCaption("Farm reproduces people. Higher level equals more\n"
                          "people per second. Also upgrading farm gives space for\n"
                          "more and more human_ beings!");
    int farm=*building_;
    fCurrent_.create(DEFAULT_FONT, 400, 300, "Current population growth: " +
                                                   std::to_string(((int)((float)farm*1.2))*6) + "ppl/minute", 30);
    fCurrent_.center();
    fNext_.create(DEFAULT_FONT, 400, 350, "Next level population growth: " +
                                                std::to_string(((int)((float)(farm+1)*1.2))*6) + "ppl/minute", 30);
    fNext_.center();
    fCapacity_.create(DEFAULT_FONT, 400, 400, "Current farm capacity: " +
                                                    std::to_string(farm*156) + " people", 30);
    fCapacity_.center();
    fNextCapacity_.create(DEFAULT_FONT, 400, 450, "Next level farm capacity: " +
                                                        std::to_string((farm+1)*156) + " people", 30);
    fNextCapacity_.center();

    //buttons
    create_return_button();
}
