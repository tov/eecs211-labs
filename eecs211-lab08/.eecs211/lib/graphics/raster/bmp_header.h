#pragma once

#include <cstdint>
#include <cstddef>

namespace graphics
{
namespace bmp
{

using byte = unsigned char;

size_t row_padding(size_t width) noexcept;

class uint32_le_t {
    byte bytes_[4] = {0};

public:
    uint32_le_t() = default;

    template<typename T>
    uint32_le_t(T) noexcept;

    template<typename T>
    uint32_le_t& operator=(T) noexcept;

    operator uint32_t() noexcept;
};

class uint16_le_t {
    byte bytes_[2] = {0};

public:
    uint16_le_t() = default;

    template<typename T>
    uint16_le_t(T) noexcept;

    template<typename T>
    uint16_le_t& operator=(T) noexcept;

    operator uint16_t() noexcept;
};
struct info_t {
    info_t(size_t w, size_t h) noexcept;

    uint32_le_t size             = sizeof(info_t);
    uint32_le_t width;
    uint32_le_t height;
    uint16_le_t color_planes     = 1;
    uint16_le_t bpp              = 24;
    uint32_le_t compression;
    uint32_le_t data_bytes;
    uint32_le_t horiz_resolution = 0x0B13;
    uint32_le_t vert_resolution  = 0x0B13;
    uint32_le_t palette_size;
    uint32_le_t important_colors;
};

struct file_t {
    file_t(size_t w, size_t h) noexcept;

    char magic_[2] = {'B', 'M'};
    uint32_le_t file_size;
    uint16_le_t app_data1;
    uint16_le_t app_data2;
    uint32_le_t data_offset;
};

//void write_bmp(const Raster& raster, const std::string& filename) const
//{
//    std::ofstream stream{filename};
//    info_t info(raster.width(), raster.height());
//    file_t file(raster.width(), raster.height());
//
//}
//
//int main()
//{
//    int w = 800;
//    int h = 600;
//
//    std::ofstream stream{"out.bmp"};
//
//    stream.write(reinterpret_cast<const char*>(&file), sizeof(file));
//    stream.write(reinterpret_cast<const char*>(&info), sizeof(info));
//
//    unsigned char pad[3] = {0, 0, 0};
//
//    for (size_t y = 0; y < h; y++) {
//        for (size_t x = 0; x < w; x++) {
//            unsigned char r = 0, g = 0, b = 0;
//
//            size_t dx = x - w/2;
//            size_t dy = y - h/2;
//            size_t d = static_cast<size_t>(sqrt(dx*dx + dy*dy));
//            if ((d / 20) % 2 == 0) {
//                r = 255;
//            } else {
//                r = g = b = 255;
//            }
//
//            stream << b << g << r;
//        }
//        stream.write((char*) pad, padding(w));
//    }
//}

} // end namespace bmp
} // end namespace graphics
