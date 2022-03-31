#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "window.h"
#include "ship.h"

class Game {
private:
    Window m_window;
    Ship m_ship;
    sf::Clock clock;
    sf::Time m_elapsed;
public:
    Game();
    ~Game();
    void handleInput();
    void render();
    void update();
    Window *getWindow();
    Ship *getShip();
    sf::Time getElapsed() const;
    void restartClock();

};

#endif
