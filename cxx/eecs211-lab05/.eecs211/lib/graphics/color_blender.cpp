#include "color_blender.h"

namespace graphics
{

color_blender::color_blender() noexcept
{ }

color_blender& color_blender::add(double weight, const color& color) noexcept
{
    double alpha = weight * double(color.alpha());

    red_    += alpha * double(color.red());
    green_  += alpha * double(color.green());
    blue_   += alpha * double(color.blue());
    alpha_  += alpha;
    weight_ += weight;

    return *this;
}

color_blender& operator<<(color_blender& cb, const color& color) noexcept
{
    cb.add(1, color);
    return cb;
}

color color_blender::get() const noexcept
{
    if (weight_ == 0)
        return color::transparent;
    else
        return color{red_ / alpha_, green_ / alpha_, blue_ / alpha_,
                       alpha_ / weight_};
}

} // end namespace graphics
