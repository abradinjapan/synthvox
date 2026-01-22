#include "synthvox.hpp"

int main() {
    // force x11 over wayland
    setenv("SDL_VIDEODRIVER", "x11", 1);

    // run game
    synthvox::game game = synthvox::game();
    game.run();

    // display error
    std::cout << game.error.json << std::endl;

    return 0;
}
