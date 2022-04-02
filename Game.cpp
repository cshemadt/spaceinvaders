#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
Game::Game() : m_window{"Space Invaders",sf::Vector2u {900,650}}, m_ship{getWindow()->getWindowSize()}
{
    initEnemies();
    
}
Game::~Game() = default;

void Game::handleInput() 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
    {
        m_ship.move(Direction::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
    {
        m_ship.move(Direction::Right);
    }
}
void Game::render() 
{
    m_window.beginDraw();
    for (size_t i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < 7; ++j)
        {
            m_enemies.at(i).at(j).render(*m_window.getRenderWindow());
        }
    }
    m_ship.render(*m_window.getRenderWindow());  
    
    m_window.endDraw();
}
void Game::update() 
{
    getWindow()->update();
    float timestep = 1.0f/60;
    if(m_elapsed.asSeconds() >= timestep) 
    {
        m_elapsed-=sf::seconds(timestep);
    }
}
void Game::initEnemies()
{
    for (size_t i = 0; i < 3; ++i)
    {
        std::vector<Enemy> enemies_subvector;
        for (size_t j = 0; j < 7; ++j)
        {
            enemies_subvector.push_back(Enemy(getWindow()->getWindowSize()));
        }
        m_enemies.push_back(enemies_subvector);
    }
    for (size_t i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < 7; ++j)
        {
            int width = m_enemies.at(i).at(j).getSize().x;
            int height = m_enemies.at(i).at(j).getSize().y;
            m_enemies.at(i).at(j).spriteInit(i);
            m_enemies.at(i).at(j).setPosition(m_enemies.at(i).at(j).getPosition().x+j*width+j*10, m_enemies.at(i).at(j).getPosition().y+i*height+i*10);
        }
    }
}
sf::Time Game::getElapsed() { return m_elapsed; }
void Game::restartClock() { m_elapsed+=m_clock.restart(); }
Window* Game::getWindow() { return &m_window; }
Ship* Game::getShip() { return &m_ship; }