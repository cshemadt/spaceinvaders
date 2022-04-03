#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Window.h"
#include "Ship.h"
#include <vector>

class Game 
{
private:
    Window m_window;
    Ship m_ship;
    std::vector<std::vector<Enemy>> m_enemies;
    std::vector<sf::RectangleShape> m_bullets;
    int m_enemiesRows;
    int m_enemiesColumns;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    void initEnemies();
    void tick();
public:
    Game();
    ~Game();
    void handleInput();
    void render();
    void update();
    Window *getWindow();
    Ship *getShip();
    sf::Time getElapsed();
    void restartClock();

};

#endif
