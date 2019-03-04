struct Object_spawner
{
    virtual void spawn(std::unique_ptr<class Space_object>) = 0;
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
        is_space_junk_ = true;
    }

    virtual Dimensions dimensions() const = 0;

    // Facing direction, may not match velocity
    virtual Angle heading() const = 0;

    virtual ~Space_object() = default;

private:
    Material material_;
    Position top_left_;
    bool space_junk_ = false;
};

void Inertial_space_object::integrate(double dt)
{
}

void Inertial_space_object::Angle heading()
{
}

void Inertial_space_object::set_angular_velocity(Angular_velocity)
{
    
}

void Space_ship::set_control(Control which, bool state)
{
}

void Space_ship::set_control(Control which, bool state)
{
}

void Space_ship::integrate(double dt) override
{
    // space ship has autobraking! when the thrust (space bar?) is
    // off (up), we set the acceleration to some fraction of the opposite
    // of the velocity.
    
    if (thrust_on_)
        set_acceleration(thrust_power_ * heading_dims_());
    else
        set_acceleration(space_friction_ * get_velocity());

    Inertial_space_object::intergrate(dt);
}