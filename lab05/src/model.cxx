#include "model.hxx"

#include <cmath>

typedef ge211::Posn<int> Position;
typedef ge211::Dims<int> Dimensions;

void
Model::move_large_circle_left()
{
    large_center.x += 10;
}

void
Model::move_large_circle_right()
{
    large_center.x -= 10;
}

void
Model::move_small_circle_to(Position pos)
{
    small_center = pos;
}

// Returns the square of the distance between two points.
static double
sqr_distance(Position p, Position q)
{
    int dx = p.x - q.x;
    int dy = p.y - q.y;
    return dx * dx + dy * dy;
}

bool
Model::overlapped() const
{
    double radii = large_radius + small_radius;
    return sqr_distance(small_center, large_center) <= radii * radii;
}

Position
Model::large_upper_left() const
{
    return large_center.up_left_by({large_radius, large_radius});
}

Position
Model::small_upper_left() const
{
    Position p = small_center;
    p.x -= small_radius;
    p.y -= small_radius;
    return p;
}
