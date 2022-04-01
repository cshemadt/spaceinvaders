#include <SFML/Graphics.hpp>
#include "ship.h"
#include <iostream>

//---------------------------- CONSTRUCTORS ----------------------------

Ship::Ship(sf::Vector2u windowSize) : m_windowSize{windowSize} {
    spriteInit();
    reset();
}

//---------------------------- INITIALIZING METHODS ----------------------------

void Ship::reset() {
    m_hp = 3;
    m_isAlive = true;
    m_score = 0;
    m_direction = Direction::None;
    m_scoreIncrement = 10;
    setPosition(m_windowSize.x/2.0f, m_windowSize.y-50);
}
void Ship::spriteInit() {
    m_shipTexture.loadFromFile("../src/enemy4_2x_2.png");
    m_sprite.setTexture(m_shipTexture);
    m_sprite.setTextureRect(sf::IntRect(sf::Vector2i(0.f, 0.f), sf::Vector2i(64,64)));
    m_sprite.setOrigin(m_shipTexture.getSize().x/2.0f, m_shipTexture.getSize().y/2.0f);
}

//---------------------------- MAIN METHODS ----------------------------

void Ship::render(sf::RenderWindow &renderWindow) { renderWindow.draw(m_sprite); }
void Ship::move(const Direction &direction) {
    switch(direction){
        case Direction::Left:
            setPosition(m_position.x-0.05f, m_position.y);
            std::cout<<m_position.x<<std::endl;
            break;

        case Direction::Right:
            setPosition(m_position.x+0.05f, m_position.y);
            std::cout<<m_position.x<<std::endl;
            break;

    }
}

//---------------------------- GETTERS AND SETTERS ----------------------------
void Ship::setPosition(sf::Vector2f &position) {
    m_position=position;
    m_sprite.setPosition(position.x,position.y);
}

void Ship::setPosition(float x, float y) {
    m_position=sf::Vector2f{x,y};
    m_sprite.setPosition(x,y);
}
void Ship::setDirection(Direction direction) { m_direction=direction; }
sf::Sprite* Ship::getSprite() { return &m_sprite; }
