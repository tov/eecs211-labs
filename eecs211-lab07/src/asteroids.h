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
    void integrate(double dt) override;
    void Angle heading() const override;    

protected:
    Acceleration acceleration() const;
    void set_acceleration(Acceleration);

    // Currently rotation control is instantaneous rather than
    // mediated by angular acceleration.
    void set_angular_velocity(Angular_velocity);

private:
    Velocity v_;
    Acceleration dv_ {0.0, 0.0};
    Angle deg_ = 0.0;
    Angular_velocity ddeg_;
};

class Asteroid : public Inertial_space_object
{
    

private:
    // divided up when splitting; rendered dimensions are
    // based on cube root of mass:
    double mass_;
    // Any children whose mass are below this are terminal:
    double terminal_threshold_;
};

class Photon_torpedo : public Inertial_space_object
{
    ...
};

class Space_ship : public Inertial_space_object
{
public:
    ...
    enum class Control
    {
        thrust,
        rotate_left,
        rotate_right,
        fire,
    };

    // How the player controls the ship.
    void set_control(Control which, bool state);

    // [THIS SHOULDN'T ACTUALLY BE INLINE]
    void integrate(double dt) override
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

private:
    Dimensions heading_dims_() const
    {
        double rads = 180 * (heading() + 90) / acos(-1);
        return {cos(rads), sin(rads)};
    }

    double thrust_power_ = ???;

    bool thrust_on_ = false;
    double space_friction_ = -0.1;

    // Controls button-held-down firing rate.
    ge211::Timer time_since_last_fire_;
    ge211::Duration fire_delay_;
    
    // Additional rate limiting.
    size_t reload_capacity_;
    size_t shots_before_reload_;
    ge211::Duration reload_delay_;
    // also maybe too complicated, or doing someone's
    // homework for them.
};