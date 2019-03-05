#pragma once
#include<memory>
#include <ge211.h>

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
    Angle heading();

protected:
    Acceleration acceleration() const;
    void set_acceleration(Acceleration);

    // Currently rotation control is instantaneous rather than
    // mediated by angular acceleration.
    void set_angular_velocity(Angular_velocity vel);
    Angle deg_ = 0.0;

private:
    Velocity v_;
    Acceleration dv_ {0.0, 0.0};
    Angular_velocity ddeg_=0;
};


class Space_ship : public Inertial_space_object
{
    public:
    Space_ship(Position position)
        : Inertial_space_object (Space_object::Material::metal, position)
    {
        
    }

    // Facing direction, may not match velocity
    Control &control();
    virtual void integrate(double dt) override;
    
    private:
        double const heading_change = 180 ;
        Control control_{false,false,false};
};

class Asteroid : public Inertial_space_object
{
    public:
    Asteroid(double mass, Position position)
        : Inertial_space_object (Space_object::Material::rock, position)
        , mass_(mass)
    {
        
    }
    private:
    double mass_;
};

class Torpedo : public Inertial_space_object
{
    public:
    Torpedo(Position position)
        : Inertial_space_object (Space_object::Material::light, position)
    {
        
    }
};


