#pragma once

#include<memory>
#include <ge211.hxx>
#include<iostream>

struct Control
{
    bool left = false;
    bool right = false;
    bool thrust = false;
};

class Space_object
{
public:
    static bool check_collision(Space_object *so1, Space_object *so2);

    using Dimensions = ge211::Dims<double>;
    using Position = ge211::Posn<double>;
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

    virtual double size() = 0;


    // Just updates the position (no collision checking).
    virtual void integrate(double dt) = 0;

    // Object just dies by default; override to survive, delegate to die.
    virtual void collide(Space_object const *other)
    {
        space_junk_ = true;
    }

    // Facing direction, may not match velocity
    virtual ~Space_object() = default;

    Position top_left_;
protected:
    Angle deg_ = 0.0;
    bool space_junk_ = false;
private:
    Material material_;
};


class Inertial_space_object : public Space_object
{
public:
    using Velocity = ge211::Dims<double>;
    using Acceleration = ge211::Dims<double>;
    using Angular_velocity = double;

    Inertial_space_object(
            Material,
            Position,
            Velocity = {0.0, 0.0},
            Angular_velocity = 0.0);

    void integrate(double dt) override;

protected:
    Acceleration acceleration() const;

    // Currently rotation control is instantaneous rather than
    // mediated by angular acceleration.
    void set_angular_velocity(Angular_velocity vel);

    Velocity v_ = {0, 0};


private:
    Acceleration dv_ {0.0, 0.0};
    Angular_velocity ddeg_ = 0;
};


class Space_ship : public Inertial_space_object
{
public:
    explicit Space_ship(Dimensions screen_dimensions)
            : Inertial_space_object(Space_object::Material::metal,
                                    {screen_dimensions.width / 2,
                                     screen_dimensions.height / 2}),
              screen_dimensions_(screen_dimensions)
    { }

    // Facing direction, may not match velocity
    Control& control();

    void integrate(double dt) override;

    double size() override;

    void collide(Space_object const *other) override;

private:
    double const heading_change = 180;
    double const velocity_change = 100;
    Control control_ {false, false, false};
    Dimensions screen_dimensions_;
};

class Asteroid : public Inertial_space_object
{
public:
    Asteroid(
            double mass,
            Position position,
            Dimensions speed,
            double as,
            Position top_left_margin,
            Position bottom_right_margin);

    void integrate(double dt) override;

    double mass() const;

    double size() override;

    void collide(Space_object const *other) override;

private:
    double mass_;
    Position tl_margin;
    Position br_margin;
};


double const torpedo_speed = 400.0;

class Torpedo : public Inertial_space_object
{
public:
    Torpedo(Position position, Angle heading, Dimensions screen_dimensions);

    void integrate(double dt) override;

    double size() override;

    void collide(Space_object const *other) override;

private:
    Dimensions screen_dimensions_;

};


