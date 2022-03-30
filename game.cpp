#include <SFML/Graphics.hpp>
#include "game.h"
Game::Game() : m_window{"Space Invaders",sf::Vector2u (800,600)} {
}
Game::~Game() {}

void Game::handleInput() {
}
void Game::render() {
    m_window.beginDraw();
    //
    m_window.endDraw();
}
void Game::update() {
    getWindow()->update();
}
Window* Game::getWindow() { return &m_window; }