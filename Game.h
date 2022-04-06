#pragma once
#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Window.h"
#include "Ship.h"
#include "Bullet.h"
#include <vector>

class Game 
{
private:
    Window m_window;
    Ship m_ship;
    std::vector<std::vector<Enemy>> m_enemies;
    std::vector<Bullet> m_bullets;
    int m_enemiesRows;
    int m_enemiesColumns;
    int m_gapBetweenEnemies;
    sf::Clock m_clock;
    sf::Clock m_enemyClock;
    sf::Time m_elapsed;
    sf::Time m_enemyElapsed;
    float m_frameTime;
    bool m_isEdge;
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
    sf::Time getEnemyElapsed();
    void restartClock();
    void restartEnemyClock();
    void moveEnemiesDown();
    bool checkOutOfBounds();
    void setDirectionToEnemies(Direction);

};

#endif
