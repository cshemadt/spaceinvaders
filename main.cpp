#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Game.h"
#include <iostream>
int main() 
{
    Game game{};
    while(!game.getWindow()->isClosed()) 
    {
        game.handleInput();
        game.update();
        game.render();
    }
}