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
    sf::Clock m_enemyShootingIntervalClock;
    sf::Time m_elapsed;
    sf::Time m_enemyElapsed;
    sf::Time m_enemyShootingIntervalElapsed;
    float m_frameTime;
    float m_shootingInterval;
    int m_enemyBulletsLimit;
    int m_currentEnemyBullets;
    bool m_isEdge;
    void initEnemies();
    void tick();
public:
    Game();
    ~Game();
    void handleInput();
    void render();
    void update();
    void reset();
    void updateBullets();
    void updateEnemies();
    Window *getWindow();
    Ship *getShip();
    sf::Time getElapsed();
    sf::Time getEnemyElapsed();
    sf::Time getEnemyShootingIntervalElapsed();
    void restartClock();
    void restartEnemyClock();
    void restartEnemyShootingIntervalClock();
    void moveEnemiesDown();
    void setDirectionToEnemies(Direction);
    bool isLost();
    void lose();
    int getShipBullets();
};

#endif
