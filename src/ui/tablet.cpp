//
// Created by tosiek on 04.12.2021.
//

#include "../../headers/ui/tablet.h"

using namespace std;
using namespace sf;

//Constructor
tablet::tablet()
{
    plank_.loadFromFile("Textures/plank.png");
    look_.setTexture(plank_);
    look_.setScale(0.4,0.3);
    font_.loadFromFile(DEFAULT_FONT);
    text_.setFont(font_);
}

//This does constructor job
void tablet::create_tablet(string label, Vector2f possition)
{
    pos_=possition;
    sting_pos_=pos_+Vector2f(40,10);
    name_=label;
    text_.setString("Nazwa: " + name_);
    text_.setPosition(sting_pos_);
    look_.setPosition(pos_);
}

//This draws everything
void tablet::draw(RenderWindow &W)
{
    W.draw(look_);
    W.draw(text_);
}

//cool animation background
bool tablet::TRIGGERED(int mposx, int mposy)
{
    if(look_.getGlobalBounds().contains(mposx,mposy))
    {
        plank_.loadFromFile("Textures/plank1.png");
        look_.setTexture(this->plank_);
        look_.setScale(0.4,0.3);
        return true;
    }

    if(!focus_)
    {
        plank_.loadFromFile("Textures/plank.png");
        look_.setTexture(this->plank_);
        look_.setScale(0.4,0.3);
        return false;
    }

    return true;
}

//check if tablet is clicked
bool tablet::onClick(int mposx,int mposy)
{
    if(look_.getGlobalBounds().contains(mposx,mposy))
        return true;
    else
        return false;
}

//changing texture_ if tablet has been clicked
void tablet::focussed()
{
    focus_=true;
    plank_.loadFromFile("Textures/plank1.png");
    look_.setTexture(plank_);
    look_.setScale(0.4,0.3);
}


//oposite of focussed
void tablet::unfocused()
{
    focus_=false;
    plank_.loadFromFile("Textures/plank.png");
    look_.setTexture(this->plank_);
    look_.setScale(0.4,0.3);
}

//Returns name_ (wow)
string tablet::return_name()
{
    return name_;
}

