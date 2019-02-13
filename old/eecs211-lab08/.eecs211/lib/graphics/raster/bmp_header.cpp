#include "bmp_header.h"

namespace graphics
{
namespace bmp
{

template<typename T>
uint32_le_t::uint32_le_t(T value) noexcept
{
    operator=(value);
}

template<typename T>
uint32_le_t& uint32_le_t::operator=(T value) noexcept
{
    bytes_[0] = static_cast<byte>(value);
    bytes_[1] = static_cast<byte>(value >> 8);
    bytes_[2] = static_cast<byte>(value >> 16);
    bytes_[3] = static_cast<byte>(value >> 24);
    return *this;
}

uint32_le_t::operator uint32_t() noexcept
{
    return (uint32_t{bytes_[3]} << 24) |
           (uint32_t{bytes_[2]} << 16) |
           (uint32_t{bytes_[1]} <<  8) |
            uint32_t{bytes_[0]};
}

template<typename T>
uint16_le_t::uint16_le_t(T value) noexcept
{
operator=(value);
}

template<typename T>
uint16_le_t& uint16_le_t::operator=(T value) noexcept {
    bytes_[0] = static_cast<byte>(value);
    bytes_[1] = static_cast<byte>(value >> 8);
    return *this;
}

uint16_le_t::operator uint16_t() noexcept
{
    return (uint16_t{bytes_[1]} <<  8) |
           uint16_t{bytes_[0]};
}

// extra bytes to make each row a multiple of 4
size_t row_padding(size_t width) noexcept
{
    return (4 - (width * 3) % 4) % 4;
}

namespace {
size_t data_size(size_t width, size_t height) noexcept
{
    return (width * 3 + row_padding(width)) * height;
}
}

info_t::info_t(size_t w, size_t h) noexcept
{
    width      = w;
    height     = h;
    data_bytes = data_size(w, h);
}

file_t::file_t(size_t w, size_t h) noexcept
{
    auto offset = sizeof(info_t) + sizeof(file_t);
    auto size   = data_size(w, h) + offset;

    file_size = size;
    data_offset = offset;
}

} // end namespace bmp
} // end namespace graphics
