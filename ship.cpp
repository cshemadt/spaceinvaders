#include <SFML/Graphics.hpp>
#include "ship.h"
#include <iostream>

Ship::Ship(sf::Vector2u windowSize) : m_windowSize{windowSize} {
    spriteInit();
    reset();
}
Ship::~Ship() {}
void Ship::reset() {
    m_hp = 3;
    m_isAlive = true;
    m_score = 0;
    m_scoreIncrement = 10;
    setDirection(Direction::None);
    setPosition(m_windowSize.x/2, m_windowSize.y+50);
}
void Ship::spriteInit() {
    m_shipTexture.loadFromFile("../src/ship.png");
    m_sprite.setTexture(m_shipTexture);
    m_sprite.setOrigin(m_shipTexture.getSize().x, m_shipTexture.getSize().y);
}
void Ship::setPosition(sf::Vector2u &position) {
    m_position=position;
    m_sprite.setPosition(position.x,position.y);
}
void Ship::setPosition(unsigned int x, unsigned int y) {
    m_position=sf::Vector2u{x,y};
    m_sprite.setPosition(x,y);
}
void Ship::setDirection(Direction direction) {m_direction=direction; }
void Ship::render(sf::RenderWindow &renderWindow) {
    renderWindow.draw(m_sprite);
}
sf::Sprite* Ship::getSprite() { return &m_sprite; }
