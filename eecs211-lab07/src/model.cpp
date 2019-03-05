#include"model.h"

///
/// Constructors
///
Model::Model( ge211::Dimensions screen_dimensions, 
                       ge211::Random& random)
        : screen_dimensions_(screen_dimensions)
        , random_(random)
        , space_ship_({100,100})//(double)(screen_dimensions_.width/2),(double)(screen_dimensions_.height/2)})
{
    space_objects_.emplace_back(&space_ship_);
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

void Model::turn_right (bool state)
{
    space_ship_.control().right=state;
}

void Model::turn_left (bool state)
{
    space_ship_.control().left=state;
}

void Model::thrust (bool state)
{
    space_ship_.control().thrust=state;
}

void Model::launch_torpedo ()
{
}

std::vector<std::unique_ptr<Space_object>> &Model::space_objects()
{
    return space_objects_;
}

///
/// Private member functions
///