//
// Created by tosiek on 04.12.2021.
//

#include "tablet.h"

using namespace std;
using namespace sf;

//Constructor
tablet::tablet()
{
    this->plank.loadFromFile("Textures/plank.png");
    this->look.setTexture(this->plank);
    this->look.setScale(0.4,0.3);
    this->font.loadFromFile(DEFAULT_FONT);
    this->text.setFont(this->font);
}

//This does constructor job
void tablet::create_tablet(string label, Vector2f possition)
{
    this->pos=possition;
    this->sting_pos=this->pos+Vector2f(40,10);
    this->name=label;
    this->text.setString("Nazwa: "+this->name);
    this->text.setPosition(this->sting_pos);
    this->look.setPosition(this->pos);
}

//This draws everything
void tablet::draw(RenderWindow &W)
{
    W.draw(this->look);
    W.draw(this->text);
}

//cool animation background
bool tablet::TRIGGERED(int mposx, int mposy)
{
    if(this->look.getGlobalBounds().contains(mposx,mposy))
    {
        this->plank.loadFromFile("Textures/plank1.png");
        this->look.setTexture(this->plank);
        this->look.setScale(0.4,0.3);
        return true;
    }
    else
    {
        if(!this->focuss)
        {
            this->plank.loadFromFile("Textures/plank.png");
            this->look.setTexture(this->plank);
            this->look.setScale(0.4,0.3);
            return false;
        }
    }
}

//check if tablet is clicked
bool tablet::onClick(int mposx,int mposy)
{
    if(this->look.getGlobalBounds().contains(mposx,mposy))
        return true;
    else
        return false;
}

//changing texture if tablet has been clicked
void tablet::focussed()
{
    this->focuss=true;
    this->plank.loadFromFile("Textures/plank1.png");
    this->look.setTexture(this->plank);
    this->look.setScale(0.4,0.3);
}


//oposite of focussed
void tablet::notfocussed()
{
    this->focuss=false;
    this->plank.loadFromFile("Textures/plank.png");
    this->look.setTexture(this->plank);
    this->look.setScale(0.4,0.3);
}

//Returns name (wow)
string tablet::return_name()
{
    return this->name;
}
