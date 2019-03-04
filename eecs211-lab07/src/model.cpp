#include"model.h"

///
/// Constructors
///
Model::Model( ge211::Dimensions screen_dimensions, 
                       ge211::Random& random)
        : screen_dimensions_(screen_dimensions)
        , random_(random)
{
    std::unique_ptr<Space_object> ship(new Space_ship());
    space_objects_.emplace_back(new Space_ship());
}

///
/// Public member functions
///

void Model::update ( double ft )
{
    for(std::unique_ptr<Space_object> &so : space_objects_) 
    {
        so->integrate(ft);
    }
}

void Model::control_space_ship ( Control control )
{
}

void Model::launch_torpedo ()
{
}

///
/// Private member functions
///