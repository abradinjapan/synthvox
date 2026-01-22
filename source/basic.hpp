#pragma once

/* Include */
// C++
#include <stdint.h>
#include <iostream>

// graphics
#include <SDL3/SDL.h>

/* Basics */
namespace synthvox {
    // basic types
    typedef uint8_t u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;
    typedef int8_t s8;
    typedef int16_t s16;
    typedef int32_t s32;
    typedef int64_t s64;
    typedef float f32;
    typedef double f64;

    // world data
    namespace world {
        typedef synthvox::f32 axis;
        typedef synthvox::world::axis x;
        typedef synthvox::world::axis y;
        typedef synthvox::world::axis z;
    }
}
