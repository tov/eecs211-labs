#pragma once

#include "color32.h"

#include <string>
#include <vector>

namespace graphics
{

class raster
{
public:
    raster(size_t width, size_t height);
    raster(size_t width, size_t height, color32 fill);

    color32      & at(size_t x, size_t y);
    const color32& at(size_t x, size_t y) const;

    size_t width() const noexcept { return width_; }
    size_t height() const noexcept { return height_; }

    bool in_bounds(size_t x, size_t y) const noexcept;

    void write_ppm(const std::string& filename) const;
    void write_bmp(const std::string& filename) const;

private:
    size_t               width_, height_;
    std::vector<color32> pixels_;
};

} // namespace graphics
