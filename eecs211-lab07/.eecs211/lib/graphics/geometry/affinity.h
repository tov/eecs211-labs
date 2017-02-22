// affine transformations

#pragma once

#include "bbox.h"
#include "posn.h"

#include <cmath>

namespace graphics
{

class affinity
{
public:
    constexpr affinity(double a, double b, double dx,
                       double c, double d, double dy) noexcept;
                       //     0,        0,         1

    static constexpr affinity translation(double dx, double dy) noexcept;
    static constexpr affinity dilation(double cx, double cy) noexcept;
    static constexpr affinity dilation(double c) noexcept;
    static inline    affinity rotation(double radians) noexcept;

    constexpr affinity inverse() const noexcept;
    constexpr affinity under(affinity) const noexcept;
    constexpr affinity centered_on(double x, double y) const noexcept;

    constexpr posn<double>
    operator()(posn<double>) const noexcept;

    constexpr bbox<double>
    operator()(const bbox<double>&) const noexcept;

    constexpr affinity
    operator()(const affinity&) const noexcept;

    template <typename T>
    constexpr T operator()(const T& t) const
    {
        return t.transform(*this);
    }

    template <typename T>
    constexpr T apply(const T& obj) const noexcept
    {
        return operator()(obj);
    }

private:
    double a_, b_, dx_,
           c_, d_, dy_;
        //  0   0   1
};

constexpr affinity::affinity(double a, double b, double dx,
                             double c, double d, double dy) noexcept
    : a_{a}, b_{b}, dx_{dx}, c_{c}, d_{d}, dy_{dy}
{ }

constexpr affinity
affinity::translation(double dx, double dy) noexcept
{
    return affinity{ 1.0, 0.0, dx, 0.0, 1.0, dy };
}

constexpr affinity
affinity::dilation(double cx, double cy) noexcept
{
    return affinity{ cx, 0.0, 0.0, 0.0, cy, 0.0 };
}

constexpr affinity
affinity::dilation(double c) noexcept
{
    return dilation(c, c);
}

inline affinity
affinity::rotation(double radians) noexcept
{
    return affinity{ cos(radians), -sin(radians), 0.0,
                     sin(radians),  cos(radians), 0.0 };
}

constexpr affinity
affinity::inverse() const noexcept
{
    auto det = a_ * d_ - b_ * c_;

    auto a =  d_ / det;
    auto b = -b_ / det;
    auto c = -c_ / det;
    auto d =  a_ / det;

    return affinity{a, b, -(a * dx_ + b * dy_),
                    c, d, -(c * dx_ + d * dy_)};
}

constexpr affinity
affinity::under(affinity other) const noexcept
{
    return other(apply(other.inverse()));
}

constexpr affinity
affinity::centered_on(double x, double y) const noexcept
{
    return under(translation(x, y));
}

constexpr posn<double>
affinity::operator()(posn<double> point) const noexcept
{
    return {a_ * point.x + b_ * point.y + dx_, c_ * point.x + d_ * point.y + dy_};
}

constexpr bbox<double>
affinity::operator()(const bbox<double>& bb) const noexcept
{
    return bbox<double>{apply(bb.top_left()),
                        apply(bb.top_right()),
                        apply(bb.bottom_left()),
                        apply(bb.bottom_right())};
}

constexpr affinity
affinity::operator()(const affinity& t) const noexcept
{
    return affinity{a_ * t.a_  + b_ * t.c_,
                    a_ * t.b_  + b_ * t.d_,
                    a_ * t.dx_ + b_ * t.dy_ + dx_,
                    c_ * t.a_  + d_ * t.c_,
                    c_ * t.b_  + d_ * t.d_,
                    c_ * t.dx_ + d_ * t.dy_ + dy_};
}

} // namespace graphics
