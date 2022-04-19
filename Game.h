#pragma once
#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Window.h"
#include "Ship.h"
#include "Bullet.h"
#include <vector>
#include "Textbox.h"
#include "Ufo.h"
#include "Pause.h"
#include "GameOver.h"
#include "Win.h"
#include "Animation.h"
enum class GameStates
{
    Game,
    Pause,
    GameOver,
    Win,
};
class Game 
{
private:
    Window m_window;
    Ship m_ship;
    Textbox m_scoreTextBox;
    std::vector<std::vector<Enemy>> m_enemies;
    std::vector<Bullet> m_bullets;
    Ufo m_ufo;
    GameOver m_gameOver;
    Pause m_pause;
    Win m_win;
    GameStates m_state;
    sf::Sprite m_background_sprite;
    sf::Texture m_background_texture;
    sf::Texture m_explosionTexture;
    sf::Sprite m_explosionSprite;
    int m_enemiesRows;
    int m_enemiesColumns;
    int m_gapBetweenEnemies;
    sf::Clock m_clock;
    sf::Clock m_enemyClock;
    sf::Clock m_enemyShootingIntervalClock;
    sf::Clock m_ufoClock;
    sf::Clock m_ufoMoveClock;
    sf::Clock explosionClock;
    sf::Time m_explosionElapsed;
    sf::Time m_elapsed;
    sf::Time m_enemyElapsed;
    sf::Time m_enemyShootingIntervalElapsed;
    sf::Time m_ufoElapsed;
    sf::Time m_ufoMoveElapsed;
    Animation explosionAnimation;
    float m_frameTime;
    float m_ufoSpeed;
    float deltaTime;
    float m_shootingInterval;
    float m_ufoInterval;
    float totalExplosionTime;
    int m_enemyBulletsLimit;
    int m_currentEnemyBullets;
    int m_score;
    int m_bestScore;
    int m_lastScore;
    int m_scoreIncrement;
    bool m_isEdge;
    bool m_isWin;
    void initEnemies();
    void tick();
    void drawGame();
    void drawGameOver();
    void drawPause();
    void drawWin();
public:
    Game();
    ~Game();
    void handleInput();
    void render();
    void update();
    void reset();
    void updateBullets();
    void updateEnemies();
    void updateLabels();
    void updateUfo();
    Window *getWindow();
    Ship *getShip();
    sf::Time getElapsed();
    sf::Time getEnemyElapsed();
    sf::Time getEnemyShootingIntervalElapsed();
    sf::Time getUfoElapsed();
    sf::Time getUfoMoveElapsed();
    void restartClock();
    void restartEnemyClock();
    void restartEnemyShootingIntervalClock();
    void restartUfoClock();
    void restartUfoMoveClock();
    void restartExplosionClock();
    void moveEnemiesDown();
    void restartAllClocks();
    void setDirectionToEnemies(Direction);
    bool isLost();
    bool isWin();
    bool isAllDead();
    void gameOver();
    int getShipBullets();
    std::vector<Enemy> getAliveEnemies();
    void increaseScore();
    int getScore();
    void setScoreIncrement();
    int getScoreIncrement();
    GameStates getCurrentGameState();

};

#endif
