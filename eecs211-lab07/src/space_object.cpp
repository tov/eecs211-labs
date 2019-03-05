 #include"space_object.h"
#include <iostream> 
Space_object::Space_object(Material material, Position position)
    : top_left_(position)
    , material_(material)
{
    
}
 
bool Space_object::is_space_junk() const
{
    return space_junk_;
}
Space_object::Material Space_object::material() const
{
    return material_;
}

Space_object::Position Space_object::position() const
{
    return top_left_;
}

Control &Space_ship::control()
{
    return control_;
}

Inertial_space_object::Inertial_space_object( Material material, Position position, Velocity velocity, Angular_velocity angular_velocity)
    : Space_object(material, position)
    , ddeg_(angular_velocity)
    ,dv_(velocity)
{
}

Space_object::Angle Space_object::heading() const
{
    return deg_;
}

void Space_ship::integrate(double dt) 
{
    if (control_.right)
        deg_+=heading_change * dt;
    if (control_.left)
        deg_-=heading_change * dt;
    if (deg_<0) deg_+=360;
    if (deg_>360) deg_-=360;
    if (control_.thrust)
        v_+= {sin(deg_/360*6.28)* velocity_change*dt,-cos(deg_/360*6.28)* velocity_change*dt} ;
    Inertial_space_object::integrate(dt);
    if (top_left_.x<0 || 
        top_left_.x>screen_dimensions_.width ||
        top_left_.y<0 ||  
        top_left_.y>screen_dimensions_.height)
        exit (1);
}

void Inertial_space_object::integrate(double dt)
{
    top_left_.x+=v_.width * dt;
    top_left_.y+=v_.height * dt;
    v_+=dv_ * dt;
    deg_+=ddeg_*dt;
}

void Inertial_space_object::set_angular_velocity(Angular_velocity vel)
{
    ddeg_=  vel;
}

Inertial_space_object::Acceleration Inertial_space_object::acceleration() const
{
    return dv_ ;
}

void Asteroid::integrate(double dt) 
{
    Inertial_space_object::integrate(dt);
    if (top_left_.x<tl_margin.x)
        top_left_.x=br_margin.x;
    if (top_left_.x>br_margin.x)
        top_left_.x=tl_margin.x;
    if (top_left_.y<tl_margin.y)
        top_left_.y=br_margin.y;
    if (top_left_.y>br_margin.y)
        top_left_.y=tl_margin.y;
}
