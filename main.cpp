#include <SFML/Graphics.hpp>
#include "window.h"
#include "game.h"

int main() {
    Game game{};
    while(!game.getWindow()->isClosed()) {
        //game.handleInput();
        game.update();
        game.render();
    }
}