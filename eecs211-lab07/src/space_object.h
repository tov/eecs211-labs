#pragma once
#include<memory>
#include <ge211.h>
#include<iostream>

struct Object_spawner
{
    virtual void spawn(std::unique_ptr<class Space_object>) = 0;
};

struct Control
{
    bool left = false;
    bool right = false;
    bool thrust = false;
};

class Space_object
{
public:
    using Dimensions = ge211::Basic_dimensions<double>;
    using Position = ge211::Basic_position<double>;
    using Angle = double; // in ° counterclockwise from N

    enum class Material
    {
        rock,    // asteroid
        metal,  // the space ship
        light,    // photon torpedos
    };

    Space_object(Material, Position);
  
    bool is_space_junk() const;
    Material material() const;
    Position position() const;
    Angle heading() const;

    // Just updates the position (no collision checking).
    virtual void integrate(double dt) = 0;

    // Object just dies by default; override to survive, delegate to die.
    virtual void collide(
        Space_object const& other,
        Object_spawner&)
    {
        space_junk_ = true;
    }

//    virtual Dimensions dimensions() const = 0;

    // Facing direction, may not match velocity

    virtual ~Space_object() = default;

    Position top_left_;
protected:    
    Angle deg_ = 0.0;
private:
    Material material_;
    bool space_junk_ = false;
};


class Inertial_space_object : public Space_object
{
public:
    using Velocity = ge211::Basic_dimensions<double>;
    using Acceleration = ge211::Basic_dimensions<double>;
    using Angular_velocity = double;
    Inertial_space_object(Material, Position, Velocity = {0.0, 0.0}, Angular_velocity = 0.0);
    virtual void integrate(double dt) override;

protected:
    Acceleration acceleration() const;
    void set_acceleration(Acceleration);

    // Currently rotation control is instantaneous rather than
    // mediated by angular acceleration.
    void set_angular_velocity(Angular_velocity vel);
    Velocity v_ = {0,0};

private:
    Acceleration dv_ {0.0, 0.0};
    Angular_velocity ddeg_=0;
};


class Space_ship : public Inertial_space_object
{
    public:
    Space_ship(Dimensions screen_dimensions)
: Inertial_space_object (Space_object::Material::metal, {screen_dimensions.width/2, screen_dimensions.height/2})
        , screen_dimensions_ (screen_dimensions)
    {
        
    }

    // Facing direction, may not match velocity
    Control &control();
    virtual void integrate(double dt) override;
    
    private:
        double const heading_change = 180 ;
        double const velocity_change = 100 ;
        Control control_{false,false,false};
        Dimensions screen_dimensions_;
};

class Asteroid : public Inertial_space_object
{
    public:
    Asteroid(double mass, Position position, Dimensions speed, double as, Position top_left_margin, Position bottom_right_margin)
        : Inertial_space_object (Space_object::Material::rock, position,speed,as)
        , mass_(mass)
        ,tl_margin(top_left_margin)
        ,br_margin(bottom_right_margin)
    {
    }
    virtual void integrate(double dt) override;

    private:
    double mass_;
    Position tl_margin;
    Position br_margin;
};

class Torpedo : public Inertial_space_object
{
    public:
    Torpedo(Position position, Dimensions speed, double as)
        : Inertial_space_object (Space_object::Material::light, position,speed,as)
    {
        
    }
};

