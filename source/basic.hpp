#pragma once

/* Include */
// C++
#include <stdint.h>
#include <iostream>
#include <vector>

// external
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>

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
    typedef bool boolean;

    // character defines
    typedef synthvox::u8 character;

    // error
    class error {
    public:
        bool occured;
        std::string json;

        // constructors
        error() {
            occured = false;
            json = "\"error\": {\n\t\"reason\": \"No problem was detected.\"\n}";
        }
        error(bool _occured, std::string _json) {
            occured = _occured;
            json = _json;
        }
    };

    // world data
    namespace world {
        typedef synthvox::f32 axis;
        typedef synthvox::world::axis x;
        typedef synthvox::world::axis y;
        typedef synthvox::world::axis z;
    }
}
