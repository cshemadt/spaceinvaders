#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Enemy.h"
#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
    m_bulletRect=sf::RectangleShape(sf::Vector2f(5,5));
    m_bulletRect.setFillColor(sf::Color::Yellow);
    m_isAlive=true;
    m_speed=400;
}
void Bullet::move(sf::Time elapsed)
{
    switch(m_bulletType)
    {
        case BulletTypes::Ship:
        {
            setPosition(sf::Vector2f(getPosition().x, getPosition().y-m_speed*elapsed.asSeconds()));
        }
        break;
        case BulletTypes::Enemy:
        {
            setPosition(sf::Vector2f(getPosition().x, getPosition().y+m_speed*elapsed.asSeconds()));
        }
        break;
    }
    
}
void Bullet::render(sf::RenderWindow &renderWindow) { renderWindow.draw(m_bulletRect); }
bool Bullet::checkCollisionWith(const sf::FloatRect &rect)
{
    sf::FloatRect bulletRect=m_bulletRect.getGlobalBounds();
    // if(bulletRect.left < rect.left+rect.width && bulletRect.left+bulletRect.width > rect.left &&
    //     bulletRect.top<rect.top+rect.height && bulletRect.top+bulletRect.height > rect.top)
    // {
    //     m_isAlive = false;
    //     return true;
    // }
    if(bulletRect.intersects(rect))
    {
        m_isAlive = false;
        return true;
    }
    return false;
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
bool Bullet::isAlive() const
{
    return m_isAlive;
}
void Bullet::setBulletType(BulletTypes type)
{
    m_bulletType = type;
}
BulletTypes Bullet::getBulletType()
{
    return m_bulletType;
}
void Bullet::setSpeed(int speed)
{
    m_speed = speed;
}
int Bullet::getSpeed()
{
    return m_speed; 
}