#pragma once

#include "posn.h"

#include <algorithm>
#include <exception>

namespace graphics
{

template <typename T>
class bbox
{
public:
    class invalid_exception : public std::exception
    {
        virtual const char* what() const throw() override
        {
            return "Invalid bounding box (type does not have infinity)";
        }
    };

    constexpr bbox()
    {
        top_    = left_   = infinity();
        bottom_ = right_  = -infinity();
    }

    constexpr static bbox nothing()
    {
        return bbox{};
    }

    constexpr static bbox everything()
    {
        auto inf = infinity();
        return bbox(-inf, inf, inf, -inf);
    }

    constexpr bbox(const T& top, const T& right, const T& bottom, const T& left) noexcept
    {
        if (top > bottom || left > right) {
            bbox();
        } else {
            top_    = top;
            right_  = right;
            bottom_ = bottom;
            left_   = left;
        }
    }

    template <typename Boundable>
    constexpr bbox(std::initializer_list<Boundable*> boundables) : bbox()
    {
        for (const auto& boundable : boundables)
            *this = *this + boundable->get_bbox();
    }

    template <typename Boundable>
    constexpr bbox(std::initializer_list<Boundable> boundables) : bbox()
    {
        for (const auto& boundable : boundables)
            *this = *this + boundable.get_bbox();
    }

    template <typename Collection>
    constexpr bbox(const Collection& collection) : bbox()
    {
        for (const auto& each : collection)
            *this = *this + each.get_bbox();
    }

    constexpr const T& top()    const noexcept { return top_; }
    constexpr const T& right()  const noexcept { return right_; }
    constexpr const T& bottom() const noexcept { return bottom_; }
    constexpr const T& left()   const noexcept { return left_; }

    constexpr posn<T> top_left()     const noexcept { return {left(), top()}; }
    constexpr posn<T> top_right()    const noexcept { return {right(), top()}; }
    constexpr posn<T> bottom_left()  const noexcept { return {left(), bottom()}; }
    constexpr posn<T> bottom_right() const noexcept { return {right(), bottom()}; }

    constexpr T height() const noexcept { return bottom() - top(); }
    constexpr T width()  const noexcept { return right() - left(); }

    constexpr bool contains(const posn<T>& p) const noexcept
    {
        return p.x >= left() && p.x < right() && p.y >= top() && p.y < bottom();
    }

    constexpr const bbox& get_bbox() const
    {
        return *this;
    }

private:
    T top_, right_, bottom_, left_;

    static constexpr T infinity()
    {
        if (std::numeric_limits<T>::has_infinity)
            return std::numeric_limits<T>::infinity();
        else
            throw invalid_exception{};
    }
};

// Union
template <typename T>
constexpr bbox<T>
operator+(const bbox<T>& bb1, const bbox<T>& bb2)
{
    return bbox<T>(std::min(bb1.top(), bb2.top()),
                   std::max(bb1.right(), bb2.right()),
                   std::max(bb1.bottom(), bb2.bottom()),
                   std::min(bb1.left(), bb2.left()));
}

// Intersection
template <typename T>
constexpr bbox<T>
operator*(const bbox<T>& bb1, const bbox<T>& bb2)
{
    return bbox<T>(std::max(bb1.top(), bb2.top()),
                   std::min(bb1.right(), bb2.right()),
                   std::min(bb1.bottom(), bb2.bottom()),
                   std::max(bb1.left(), bb2.left()));
}

} // namespace graphics
