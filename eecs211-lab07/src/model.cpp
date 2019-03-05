#include"model.h"

///
/// Constructors
///
Model::Model( ge211::Dimensions screen_dimensions, 
                       ge211::Random& random)
        : screen_dimensions_(screen_dimensions)
        , random_(random)
        , space_ship_(screen_dimensions_.into<double>())
{
    space_objects_.emplace_back(&space_ship_);
    for (int i=0;i<10;i++)
    {
        int x = random.between(0,screen_dimensions.width);
        int y = random.between(0,screen_dimensions.height);
        int xs = random.between(-5,5);
        int ys = random.between(-5,5);
        double as = random.between(10,100);
       std::cout << "xy = (" << x <<" ,"<<y << ")\n";
        space_objects_.emplace_back(new Asteroid(1.0,{(double)x,(double)y},{(double)xs,(double)ys},as,{-200,-200},{(double)screen_dimensions.width+200,(double)screen_dimensions.height+200}));
    }
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

void Model::fire_torpedo ()
{
    double angle = space_ship_.heading();
    ge211::Basic_dimensions<double> speed {sin(angle/360*6.28)* torpedo_speed_,-cos(angle/360*6.28)* torpedo_speed_} ;
    space_objects_.emplace_back(new Torpedo (space_ship_.position(),speed,1440)); 
}

std::vector<std::unique_ptr<Space_object>> &Model::space_objects()
{
    return space_objects_;
}

///
/// Private member functions
///