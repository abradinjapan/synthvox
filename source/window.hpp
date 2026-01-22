#pragma once

/* Include */
// synthvox
#include "basic.hpp"

/* Window */
namespace synthvox::graphics {
    // window defines
    typedef synthvox::u64 window_width;
    typedef synthvox::u64 window_height;

    // window appearance data (NOT including inner window, opengl takes care of that)
    class window_styling {
    public:
        // window about
        std::string title;
        synthvox::graphics::window_width width;
        synthvox::graphics::window_height height;

        // constructors
        window_styling() {
            title = "Default Window";
            width = 800;
            height = 600;
        }
        window_styling(std::string _title, synthvox::graphics::window_width _width, synthvox::graphics::window_height _height) {
            title = _title;
            width = _width;
            height = _height;
        }
    };

    // window
    class window {
    public:
        SDL_Window* window_context;
        SDL_GLContext sdl3_opengl_context;
        synthvox::graphics::window_styling window_styling;

        window() {
            window_context = 0;
            sdl3_opengl_context = 0;
            window_styling = synthvox::graphics::window_styling();
        }

        // open window
        synthvox::error open(synthvox::graphics::window_styling style) {
            // setup no error
            synthvox::error output = synthvox::error();

            // set styling
            window_styling = style;

            // setup opengl expectations
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

            // initalize window
            window_context = SDL_CreateWindow((const char*)style.title.c_str(), style.width, style.height, SDL_WINDOW_OPENGL /*| SDL_WINDOW_RESIZABLE*/);
            if (window_context == 0) {
                // return error
                return synthvox::error(true, "\"error\": {\"reason\": \"Failed to create SDL3 window context.\"}");
            }

            // initalize opengl context
            sdl3_opengl_context = SDL_GL_CreateContext(window_context);
            if (sdl3_opengl_context == 0) {
                // quit cleanly
                SDL_DestroyWindow(window_context);

                // return error
                return synthvox::error(true, "\"error\": {\"reason\": \"Failed to create OpenGL context.\"}");
            }

            // initalize glew
            glewExperimental = GL_TRUE;
            GLenum glew_error = glewInit();
            if (glew_error != GLEW_OK) {
                // quit cleanly
                SDL_GL_DestroyContext(sdl3_opengl_context);
                SDL_DestroyWindow(window_context);

                // return error
                return synthvox::error(true, "\"error\": {\"reason\": \"GLEW did not initialize.\"}");
            }

            // setup clear color
            glClearColor(0.0f, 0.5f, 1.0f, 1.0f);

            // window initilaized
            return output;
        }

        // close window
        void close() {
            // close graphics
            SDL_GL_DestroyContext(sdl3_opengl_context);
            SDL_DestroyWindow(window_context);
        }

        // setup at loop end to setup next frame
        void next_frame() {
            // clear buffer
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // display window data
            SDL_GL_SwapWindow(window_context);
        }
    };
}
