#ifndef SPACE_INVADERS_BULLET_H
#define SPACE_INVADERS_BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>
enum class BulletTypes
{
    Enemy,
    Ship
};
class Bullet 
{
private:
    
    sf::RectangleShape m_bulletRect;
    bool m_isAlive;
    int m_speed;
    BulletTypes m_bulletType;

public:
    Bullet();
    void move(sf::Time elapsed);
    bool checkCollisionWith(const sf::FloatRect &rect);
    void render(sf::RenderWindow &renderWindow);

    void setPosition(sf::Vector2f position);
    void setBulletType(BulletTypes type);
    void setSpeed(int speed);
    int getSpeed();
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    BulletTypes getBulletType();
    bool isAlive() const;
};

#endif