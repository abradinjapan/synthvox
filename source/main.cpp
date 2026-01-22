#include "synthvox.hpp"

int main() {
    // run game
    synthvox::game game = synthvox::game();
    game.run();

    // display error
    std::cout << game.error.json << std::endl;

    return 0;
}
