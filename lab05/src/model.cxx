#include "model.hxx"
#include <cmath>

void Model::move_large_circle_left()
{
    large_center_.x += 10;
}

void Model::move_large_circle_right()
{
    large_center_.x -= 10;
}

void Model::move_small_circle_to(ge211::Position pos)
{
    small_center_ = pos;
}

static double distance(ge211::Position pos1, ge211::Position pos2)
{
    int dx = pos1.x - pos2.x;
    int dy = pos1.y - pos2.y;
    return sqrt(dx * dx + dy * dy);
}

static const ge211::Dimensions small_dims{2 * small_radius, 2 * small_radius};
static const ge211::Dimensions large_dims{2 * large_radius, 2 * large_radius};

bool Model::is_touching() const
{
    double dist = distance(small_center_, large_center_);
    return dist <= large_radius + small_radius;
}

ge211::Position Model::large_upper_left() const
{
    return {large_center_.x - large_radius, large_center_.y - large_radius};

}

ge211::Position Model::small_upper_left() const
{
    return {small_center_.x - small_radius, small_center_.y - small_radius};
}

