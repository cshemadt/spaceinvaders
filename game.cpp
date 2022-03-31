#include <SFML/Graphics.hpp>
#include "game.h"
Game::Game() : m_window{"Space Invaders",sf::Vector2u {900,650}}, m_ship{getWindow()->getWindowSize()} {}
Game::~Game() = default;

void Game::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_ship.move(Direction::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_ship.move(Direction::Right);
    }
}
void Game::render() {
    m_window.beginDraw();
    m_ship.render(*m_window.getRenderWindow());
    m_window.endDraw();
}
void Game::update() { getWindow()->update(); }
Window* Game::getWindow() { return &m_window; }
Ship* Game::getShip() { return &m_ship; }