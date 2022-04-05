#ifndef SPACE_INVADERS_BULLET_H
#define SPACE_INVADERS_BULLET_H

#include <SFML/Graphics.hpp>
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
    bool checkCollisionWith(const sf::FloatRect &rect);
    void render(sf::RenderWindow &renderWindow);

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    bool isAlive() const;
};

#endif