#include "raster.h"
#include "bmp_header.h"

#include <cassert>
#include <fstream>

namespace graphics
{

raster::raster(size_t width, size_t height)
    : raster{width, height, color32::black}
{ }

raster::raster(size_t width, size_t height, color32 fill)
    : width_{width}
    , height_{height}
    , pixels_(width * height, fill)
{ }

color32& raster::at(size_t x, size_t y)
{
    assert(in_bounds(x, y));
    return pixels_[width() * y + x];
}

const color32& raster::at(size_t x, size_t y) const
{
    assert(in_bounds(x, y));
    return pixels_[width() * y + x];
}

bool raster::in_bounds(size_t x, size_t y) const noexcept
{
    return x < width() && y < height();
}

void raster::write_ppm(const std::string& filename) const
{
    std::ofstream of{filename};
    of << "P6\n";       // magic number
    of << width() << ' ' << height() << " 255\n";

    for (const auto& pixel : pixels_) {
        of << pixel.red() << pixel.green() << pixel.blue();
    }
}

void raster::write_bmp(const std::string& filename) const
{
    std::ofstream of{filename};
    bmp::info_t info{width(), height()};
    bmp::file_t file{width(), height()};

    of.write((char *)&file, sizeof(file));
    of.write((char *)&info, sizeof(info));

    for (size_t y = height(); y > 0; --y) {
        for (size_t x = 0; x < width(); ++x) {
            auto pixel = at(x, y - 1);
            of << pixel.blue() << pixel.green() << pixel.red();
        }

        for (size_t x = 0; x < bmp::row_padding(width()); ++x) {
            of << '\0';
        }
    }
}

} // namespace graphics
