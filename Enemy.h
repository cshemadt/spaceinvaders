#ifndef SPACE_INVADERS_ENEMY_H
#define SPACE_INVADERS_ENEMY_H

#include <SFML/Graphics.hpp>
#include "Ship.h"

class Enemy 
{
protected:
    sf::Vector2u m_size;
    sf::Vector2u m_windowSize;
    Direction m_direction;
    sf::Sprite m_enemySprite;
    sf::FloatRect m_enemyCollisionRect;
    sf::Texture m_enemyTexture;
    int m_speed;
    bool m_isAlive;
    int m_currentTextureIndex;
public:
    Enemy(sf::Vector2u windowSize);
    ~Enemy()=default;
    void setPosition(const sf::Vector2f &position);
    void setPosition(unsigned int x,unsigned int y);
    void setDirection(Direction);
    void setSpeed(int speed);

    void spriteInit(int index);
    void die();
    void move();
    void fire(std::vector<Bullet> &bullets);
    void reset();
    void updateCollisionRect();
    void update();
    void render(sf::RenderWindow &renderWindow);

    sf::Vector2f getPosition();
    Direction getDirection();
    sf::Sprite *getSprite();
    sf::Vector2u getSize();
    sf::FloatRect getEnemyCollisionRect();
    bool isAlive() const;
    int getSpeed() const;
};

#endif
