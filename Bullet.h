#ifndef SPACE_INVADERS_BULLET_H
#define SPACE_INVADERS_BULLET_H

#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Enemy.h"
#include <iostream>

class Bullet 
{
private:
    sf::RectangleShape m_bulletRect;
    bool m_isAlive;
    int m_speed;

public:
    Bullet();
    void move(sf::Time elapsed);
    bool checkCollisionWith(const Ship &ship);
    bool checkCollisionWith(const Enemy &enemy);

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
};

#endif