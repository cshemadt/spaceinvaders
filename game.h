#include <SFML/Graphics.hpp>
#include "window.h"
#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

class Game {
private:
    Window m_window;
    sf::Clock clock;
    sf::Time m_elapsed;
public:
    Game();
    ~Game();
    void handleInput();
    void render();
    void update();
    Window *getWindow();
    sf::Time getElapsed();
    void restartClock();

};

#endif
