#include "color32.h"

#include <algorithm>

namespace graphics
{

using byte = color32::byte;
auto constexpr BYTE_MAX = color32::BYTE_MAX;

static size_t constexpr
    RED_SHIFT   = 16,
    GREEN_SHIFT = 8,
    BLUE_SHIFT  = 0,
    ALPHA_SHIFT = 24;

color32::color32(byte red, byte green, byte blue, byte alpha) noexcept
    : value{static_cast<uint32_t>((red   << RED_SHIFT)
                                | (green << GREEN_SHIFT)
                                | (blue  << BLUE_SHIFT)
                                | (alpha << ALPHA_SHIFT))}
{
    if (alpha == 0) value = 0;
}

color32::color32(uint32_t argb) noexcept : value{argb}
{}

color32::color32() noexcept : color32{0, 0, 0, 0} {}

color32 const color32::transparent{0, 0, 0, 0};
color32 const color32::white{BYTE_MAX, BYTE_MAX, BYTE_MAX};
color32 const color32::black{0, 0, 0};

byte color32::red()   const noexcept
{
    return static_cast<byte>((value >> RED_SHIFT) & 0xFF);
}

byte color32::green() const noexcept
{
    return static_cast<byte>((value >> GREEN_SHIFT) & 0xFF);
}

byte color32::blue()  const noexcept
{
    return static_cast<byte>((value >> BLUE_SHIFT) & 0xFF);
}

byte color32::alpha() const noexcept
{
    return static_cast<byte>((value >> ALPHA_SHIFT) & 0xFF);
}

} // namespace graphics
