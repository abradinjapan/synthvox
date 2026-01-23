#pragma once

/* Include */
// C++
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// external
#include <GL/glew.h>
#include <GL/gl.h>
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
    typedef void* address;
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

    // buffer defines
    typedef synthvox::u64 length;
    class buffer {
    public:
        synthvox::address start;
        synthvox::address end;

        buffer() {
            start = 0;
            end = 0;
        }
        buffer(synthvox::address _start, synthvox::address _end) {
            start = _start;
            end = _end;
        }

        // length of buffer
        synthvox::length length() {
            return (synthvox::length)((synthvox::u64)end - (synthvox::u64)start + 1);
        }
    };

    // file loader
    class file_loader {
    public:
        synthvox::error error;

        // load file into std::string
        std::string load_text_file(std::string _file_path) {
            // null init error
            error = synthvox::error();

            // open file stream
            std::ifstream file(_file_path);

            // check for error
            if (!file) {
                // setup error
                error = synthvox::error(true, "\"error\": {\n\t\"reason\": \"Text file could not be loaded / found.\",\n\t\"file_path\": \"" + _file_path + "\"\n}");

                return "";
            }

            // read file into string
            std::ostringstream stringstream;
            stringstream << file.rdbuf();
            return stringstream.str();
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
