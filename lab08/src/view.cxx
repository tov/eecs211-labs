#include "view.hxx"
#include <iostream>

///
/// Constructor
///

View::View(Model& model)
        : model_(model)
{
}

///
/// Member functions
///

void
View::draw(ge211::Sprite_set& sprites) const
{
    std::vector<std::unique_ptr<Space_object>>
            & space_objects = model_.space_objects();
    for (std::unique_ptr<Space_object>& so : space_objects) {
        if (!so->is_space_junk()) {
            ge211::Posn<int> pos {0, 0};
            pos.x = (int) so->position().x;
            pos.y = (int) so->position().y;
            ge211::Transform
                    rotation = ge211::Transform::rotation(so->heading());
            switch (so->material()) {
            case Space_object::Material::metal: // spaceship
                rotation.set_scale(space_ship_scale_);
                pos.x -= space_ship_.dimensions().width * space_ship_scale_ / 2;
                pos.y
                        -=
                        space_ship_.dimensions().height * space_ship_scale_ / 2;
                sprites.add_sprite(space_ship_, pos, 2, rotation);
                break;
            case Space_object::Material::rock: // asteroid
            {
                Asteroid *ss = dynamic_cast<Asteroid *> (so.get());
                rotation.set_scale(asteroid_scale_ * ss->mass());
                pos.x
                        -=
                        asteroid_.dimensions().width * asteroid_scale_ *
                        ss->mass() / 2;
                pos.y
                        -=
                        asteroid_.dimensions().height * asteroid_scale_ *
                        ss->mass() / 2;
                sprites.add_sprite(asteroid_, pos, 0, rotation);
            }
                break;
            case Space_object::Material::light: // light
                rotation.set_scale(torpedo_scale_);
                pos.x -= torpedo_.dimensions().width * torpedo_scale_ / 2;
                pos.y -= torpedo_.dimensions().height * torpedo_scale_ / 2;
                sprites.add_sprite(torpedo_, pos, 1, rotation);
                break;
            }
        }
    }
}
