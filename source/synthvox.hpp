#pragma once

// synthvox
#include "basic.hpp"
#include "window.hpp"
#include "shaders.hpp"

/* Game Loop */
namespace synthvox {
    class game {
        // game state
        synthvox::graphics::window game_window;
        synthvox::boolean is_running;

    public:
        // error
        synthvox::error error;

        // game loop
        void run() {
            // game start
            std::cout << "Running new game!" << std::endl;

            // init SDL3
            if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
                // setup error
                error = synthvox::error(true, "\"error\": {\"reason\": \"SDL3 did not initialize.\"}");

                printf("%s", (const char*)SDL_GetError());
                printf("\n");

                return;
            }

            // start runner
            is_running = true;

            // open game window
            game_window = synthvox::graphics::window();
            error = game_window.open(synthvox::graphics::window_styling("Synthvox", 800, 600));
            if (error.occured) {
                return;
            }

            // temp event
            SDL_Event temp_event;

            // game loop
            while (is_running) {
                // check for quit
                while (SDL_PollEvent(&temp_event)) {
                    switch (temp_event.type) {
                    case SDL_EVENT_QUIT:
                        // stop game
                        is_running = false;

                        break;
                    default:
                        break;
                    }
                }

                // next frame
                game_window.next_frame();
            }

            // close game
            game_window.close();
            SDL_Quit();

            // thank player
            std::cout << "Thanks for playing Synthvox!" << std::endl;

            return;
        }
    };
}
