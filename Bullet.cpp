#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Enemy.h"
#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
    m_bulletRect=sf::RectangleShape(sf::Vector2f(5,5));
    m_isAlive=true;
    m_speed=400;
}
void Bullet::move(sf::Time elapsed)
{
    setPosition(sf::Vector2f(getPosition().x, getPosition().y-m_speed*elapsed.asSeconds()));
}
void Bullet::setPosition(sf::Vector2f position)
{
    m_bulletRect.setPosition(position);
}
sf::Vector2f Bullet::getPosition() const 
{
    return m_bulletRect.getPosition();
}
sf::Vector2f Bullet::getSize() const
{
    return m_bulletRect.getSize();
}