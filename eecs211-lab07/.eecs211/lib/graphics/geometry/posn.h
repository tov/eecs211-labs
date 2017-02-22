#pragma once

#include <cmath>

namespace graphics
{

// forward declaration
template <typename T>
class bbox;

template <typename T>
struct posn
{
    T x, y;

    constexpr bbox<T> get_bbox() const noexcept;
};

template <typename T>
constexpr bbox<T>
posn<T>::get_bbox() const noexcept
{
    return bbox<T>(y, x, y, x);
}

template <typename T>
constexpr posn<T>
operator+(const posn<T>& p1, const posn<T>& p2)
    noexcept(noexcept(p1.x + p2.x))
{
    return { p1.x + p2.x, p1.y + p2.y };
}

template <typename T>
constexpr posn<T>
operator-(const posn<T>& p1, const posn<T>& p2)
    noexcept(noexcept(p1.x - p2.x))
{
    return { p1.x - p2.x, p1.y - p2.y };
}

template <typename T>
constexpr posn<T>
operator*(const T& c, const posn<T>& p)
    noexcept(noexcept(c * p.x))
{
    return { c * p.x, c * p.y };
}

template <typename T>
constexpr posn<T>
operator/(const posn<T>& p, const T& c)
    noexcept(noexcept(p.x / c))
{
    return { p.x / c, p.y / c };
}

template <typename T>
constexpr T
interpolate(const T& t1, double weight, const T& t2)
{
    return static_cast<T>((1 - weight) * static_cast<double>(t1) +
                          weight * static_cast<double>(t2));
}

template <typename T>
constexpr posn<T>
interpolate(const posn<T>& p1, double weight, const posn<T>& p2)
{
    return {interpolate(p1.x, weight, p2.x), interpolate(p1.y, weight, p2.y)};
}

template <typename T>
inline double magnitude(const posn<T>& p)
{
    auto x = static_cast<double>(p.x);
    auto y = static_cast<double>(p.y);
    return sqrt(x * x + y * y);
}

template <typename T>
constexpr double distance(const posn<T>& p1, const posn<T>& p2)
{
    return magnitude(p1 - p2);
}

} // namespace graphics
