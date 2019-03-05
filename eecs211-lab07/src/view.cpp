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
        switch (so->material())
        {
            case Space_object::Material::metal: // spaceship
            {
                Space_object *soo=so.get();
                Space_ship *ss = dynamic_cast<Space_ship*> (soo);
                double angle = ss->heading();
                std::cout << angle << "\n";
                ge211::Transform rotation = ge211::Transform::rotation(angle);
                rotation.set_scale(.3);
                sprites.add_sprite(space_ship_,pos,0,rotation);
            }
                break;
            case Space_object::Material::rock: // asteroid
                break;
            case Space_object::Material::light: // light
                sprites.add_sprite(torpedo_, pos,0);
                break;
        }
    }
}
