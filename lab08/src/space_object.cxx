#include"space_object.hxx"
#include <cmath>
#include <iostream>

static double
degrees_to_radian(double degrees)
{
    return acos(-1) * degrees / 180;
}

static double
distance(Space_object::Position a, Space_object::Position b)
{
    Space_object::Dimensions d = a - b;
    return sqrt(d.width * d.width + d.height * d.height);
}

Space_object::Space_object(Material material, Position position)
        : top_left_(position),
          material_(material)
{

}

bool
Space_object::check_collision(Space_object *so1, Space_object *so2)
{
    if (so1->is_space_junk() || so2->is_space_junk()) { return false; }
    double s1 = so1->size();
    double s2 = so1->size();
    Position p1 = so1->position();
    Position p2 = so2->position();
    if (distance(p1, p2) < (s1 + s2) / 2) {
        if (so1->material() != so2->material()) {
            so1->collide(so2);
            so2->collide(so1);
            return true;
        }
    }
    return false;
}

bool
Space_object::is_space_junk() const
{
    return space_junk_;
}

Space_object::Material
Space_object::material() const
{
    return material_;
}

Space_object::Position
Space_object::position() const
{
    return top_left_;
}

Control&
Space_ship::control()
{
    return control_;
}

Inertial_space_object::Inertial_space_object(
        Material material,
        Position position,
        Velocity velocity,
        Angular_velocity angular_velocity)
        : Space_object(material, position),
          dv_(velocity),
          ddeg_(angular_velocity)
{
}

Space_object::Angle
Space_object::heading() const
{
    return deg_;
}

void
Space_ship::integrate(double dt)
{
    if (control_.right) {
        deg_ += heading_change * dt;
    }
    if (control_.left) {
        deg_ -= heading_change * dt;
    }
    if (deg_ < 0) { deg_ += 360; }
    if (deg_ > 360) { deg_ -= 360; }
    if (control_.thrust) {
        v_
                +=
                {sin(degrees_to_radian(deg_)) * velocity_change * dt,
                 -cos(degrees_to_radian(deg_)) * velocity_change * dt};
    }
    Inertial_space_object::integrate(dt);
    if (top_left_.x < 0 ||
        top_left_.x > screen_dimensions_.width ||
        top_left_.y < 0 ||
        top_left_.y > screen_dimensions_.height) {
        exit(1);
    }
}

void
Inertial_space_object::integrate(double dt)
{
    top_left_.x += v_.width * dt;
    top_left_.y += v_.height * dt;
    v_ += dv_ * dt;
    deg_ += ddeg_ * dt;
}

void
Inertial_space_object::set_angular_velocity(Angular_velocity vel)
{
    ddeg_ = vel;
}

Inertial_space_object::Acceleration
Inertial_space_object::acceleration() const
{
    return dv_;
}

Asteroid::Asteroid(
        double mass,
        Position position,
        Dimensions speed,
        double as,
        Position top_left_margin,
        Position bottom_right_margin)
        : Inertial_space_object(Space_object::Material::rock,
                                position,
                                speed,
                                as),
          mass_(mass),
          tl_margin(top_left_margin),
          br_margin(bottom_right_margin)
{
}


void
Asteroid::integrate(double dt)
{
    Inertial_space_object::integrate(dt);
    if (top_left_.x < tl_margin.x) {
        top_left_.x = br_margin.x;
    }
    if (top_left_.x > br_margin.x) {
        top_left_.x = tl_margin.x;
    }
    if (top_left_.y < tl_margin.y) {
        top_left_.y = br_margin.y;
    }
    if (top_left_.y > br_margin.y) {
        top_left_.y = tl_margin.y;
    }
}

double
Asteroid::mass() const
{
    return mass_;
}

Torpedo::Torpedo(Position position, Angle heading, Dimensions screen_dimensions)
        : Inertial_space_object(Space_object::Material::light,
                                position,
                                {sin(degrees_to_radian(heading)) *
                                 torpedo_speed,
                                 -cos(degrees_to_radian(heading)) *
                                 torpedo_speed},
                                1440),
          screen_dimensions_(screen_dimensions)
{
}

void
Torpedo::integrate(double dt)
{
    Inertial_space_object::integrate(dt);
    if (top_left_.x < 0 ||
        top_left_.x > screen_dimensions_.width ||
        top_left_.y < 0 ||
        top_left_.y > screen_dimensions_.height) {
        space_junk_ = true;
    }
}

double
Space_ship::size()
{
    return 60;
}

double
Asteroid::size()
{
    return 80 * mass_;
}

double
Torpedo::size()
{
    return 8;
}

void
Asteroid::collide(Space_object const *other)
{
    if (other->material() == Material::light) {
        space_junk_ = true;
    }
}

void
Space_ship::collide(Space_object const *other)
{
    if (other->material() == Material::rock) {
        space_junk_ = true;
    }
}

void
Torpedo::collide(Space_object const *other)
{
    if (other->material() == Material::rock) {
        space_junk_ = true;
    }
}
