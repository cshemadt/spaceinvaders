#include <SFML/Graphics.hpp>
#include "window.h"
#include "game.h"

int main() {
    //Window window("TEST",sf::Vector2u(300,400));
    Game game{};
    while(!game.getWindow()->isClosed()) {
        //game.handleInput();
        game.update();
        game.render();
    }
}