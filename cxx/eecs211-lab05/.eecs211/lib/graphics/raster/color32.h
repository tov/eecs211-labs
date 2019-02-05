#pragma once

#include <cstdint>

namespace graphics
{

struct color32
{
    uint32_t value;

    using byte = unsigned char;

    static constexpr byte BYTE_MAX = 255;

    color32(byte red, byte green, byte blue, byte alpha = BYTE_MAX) noexcept;
    // color(const fcolor&) noexcept;

    // constructs transparent by default
    color32() noexcept;

    explicit color32(uint32_t argb) noexcept;

    static color32 const transparent;
    static color32 const white;
    static color32 const black;

    byte red()   const noexcept;
    byte green() const noexcept;
    byte blue()  const noexcept;
    byte alpha() const noexcept;
};

} // end namespace graphics
