#include "view.h"
#include <iostream>

///
/// Constructor
///

View::View(Model & model)
        : model_(model)
{
}

///
/// Member functions
///

void View::draw(ge211::Sprite_set& sprites) const
{
    std::vector<std::unique_ptr<Space_object>>  &space_objects = model_.space_objects();
    for(std::unique_ptr<Space_object> &so : space_objects) 
    {
        ge211::Position pos{0,0};
        pos.x=(int)so->position().x;
        pos.y=(int)so->position().y;
        ge211::Transform rotation = ge211::Transform::rotation(so->heading());
        switch (so->material())
        {
            case Space_object::Material::metal: // spaceship
            {
                rotation.set_scale(.3);
                pos.x -=space_ship_.dimensions().width*.3/2;
                pos.y -=space_ship_.dimensions().height*.3/2;
                sprites.add_sprite(space_ship_,pos,2,rotation);
            }
                break;
            case Space_object::Material::rock: // asteroid
                pos.x -=asteroid_.dimensions().width/2;
                pos.y -=asteroid_.dimensions().height*.3/2;
                sprites.add_sprite(asteroid_,pos,0,rotation);
                //std::cout << pos.x << "," << pos.y << "\n";
                break;
            case Space_object::Material::light: // light
                rotation.set_scale(.03);
                pos.x -=torpedo_.dimensions().width*.03/2;
                pos.y -=torpedo_.dimensions().height*.03/2;
                sprites.add_sprite(torpedo_, pos,1,rotation);
                break;
        }
    }
}
