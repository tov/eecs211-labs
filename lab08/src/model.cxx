#include"model.hxx"

double const initial_asteroid_mass = 1;
double const min_asteroid_mass = 0.1;

///
/// Constructors
///
Model::Model(ge211::Dims<int> screen_dimensions)
        : screen_dimensions_(screen_dimensions),
          space_ship_(screen_dimensions_.into<double>()),
          random_x_coor_(0, screen_dimensions_.width),
          random_y_coor_(0, screen_dimensions_.height),
          random_velocity_(-5, 5),
          random_angular_velocity_(10, 100)
{
    // use .stub_with(...) here on random sources if you want non-random
    // results while developing

    space_objects_.emplace_back(&space_ship_);
    for (int i = 0; i < 10; i++) {
        new_asteroid_(initial_asteroid_mass, {-1, -1});
    }
}

///
/// Public member functions
///

void
Model::new_asteroid_(double mass, Space_object::Position pos)
{
    if (pos.x == -1) {
        pos.x = random_x_coor_.next();
        pos.y = random_y_coor_.next();
    }
    int xs = random_velocity_.next();
    int ys = random_velocity_.next();
    double as = random_angular_velocity_.next();
    space_objects_.push_back(
            std::make_unique<Asteroid>(
                    mass,
                    pos,
                    Space_object::Dimensions {(double) xs, (double) ys},
                    as,
                    Space_object::Position {-200, -200},
                    Space_object::Position {
                            (double) screen_dimensions_.width + 200,
                            (double) screen_dimensions_.height + 200}));
}

void
Model::update(double ft)
{
    for (std::unique_ptr<Space_object>& so : space_objects_) {
        so->integrate(ft);
    }

    for (std::size_t i = 0; i < space_objects_.size(); i++) {
        for (std::size_t j = i + 1; j < space_objects_.size(); j++) {
            Space_object *so1 = space_objects_[i].get();
            Space_object *so2 = space_objects_[j].get();

            if (Space_object::check_collision(so1, so2)) {
                Asteroid *a = nullptr;

                if (so1->material() == Space_object::Material::rock) {
                    a = dynamic_cast<Asteroid *>(so1);
                } else if (so2->material() == Space_object::Material::rock) {
                    a = dynamic_cast<Asteroid *>(so2);
                }

                if (a && a->is_space_junk() && a->mass() > min_asteroid_mass) {
                    new_asteroid_(a->mass() / 2, a->position());
                    new_asteroid_(a->mass() / 2, a->position());
                }
            }
        }
    }

    if (space_ship_.is_space_junk()) {
        exit(1);
    }
}

void
Model::turn_right(bool state)
{
    space_ship_.control().right = state;
}

void
Model::turn_left(bool state)
{
    space_ship_.control().left = state;
}

void
Model::thrust(bool state)
{
    space_ship_.control().thrust = state;
}

void
Model::fire_torpedo()
{
    space_objects_.emplace_back(new Torpedo(space_ship_.position(),
                                            space_ship_.heading(),
                                            screen_dimensions_.into<double>()));
}

std::vector<std::unique_ptr<Space_object>>&
Model::space_objects()
{
    return space_objects_;
}

///
/// Private member functions
///
