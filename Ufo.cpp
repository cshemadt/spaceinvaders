#include "Ufo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Ufo::Ufo(sf::Vector2u windowSize) : m_windowSize(windowSize)
{
    spriteInit();
    reset();
}
Ufo::~Ufo() {};
void Ufo::reset()
{
    isAlive=false;
    m_startLocationOffset = 10;
    m_speed=200;
    setPosition(sf::Vector2f(m_windowSize.x+m_size.x*m_sprite.getScale().x-m_startLocationOffset, 0+m_startLocationOffset));
}
void Ufo::spriteInit()
{
    m_size = sf::Vector2u(32,16);
    if(!m_texture.loadFromFile("../assets/Ufo.png"))
    {
        std::cout<<"Ufo texture not found! \n";
        return;
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,m_size.x, m_size.y));
    m_sprite.setScale(1.3f, 1.3f);
}
void Ufo::render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(m_sprite);
}
void Ufo::move(float elapsed)
{
    setPosition(sf::Vector2f(getPosition().x-m_speed*elapsed, getPosition().y));
}
void Ufo::die() 
{
    isAlive=false; 
    setPosition(sf::Vector2f(m_windowSize.x+m_size.x*m_sprite.getScale().x-m_startLocationOffset, 0+m_startLocationOffset));
}
void Ufo::setPosition(const sf::Vector2f &position){ m_sprite.setPosition(position); }
void Ufo::setSpeed(int speed) { m_speed=speed; }
sf::Vector2f Ufo::getPosition(){ return m_sprite.getPosition(); }
sf::Vector2u Ufo::getSize() { return m_size; }
sf::Sprite* Ufo::getSprite(){ return &m_sprite; }
bool Ufo::getIsAlive() const { return isAlive; }
int Ufo::getSpeed() const { return m_speed; }