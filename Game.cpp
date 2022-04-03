#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
Game::Game() : m_window{"Space Invaders",sf::Vector2u {800,600}}, m_ship{getWindow()->getWindowSize()}
{
    m_enemiesRows=3;
    m_enemiesColumns=12;
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
    for (size_t i = 0; i < m_enemiesRows; ++i)
    {
        for (size_t j = 0; j < m_enemiesColumns; ++j)
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
    for (size_t i = 0; i < m_enemiesRows; ++i)
    {
        std::vector<Enemy> enemies_subvector;
        for (size_t j = 0; j < m_enemiesColumns; ++j)
        {
            enemies_subvector.push_back(Enemy(getWindow()->getWindowSize()));
        }
        m_enemies.push_back(enemies_subvector);
    }
    for (size_t i = 0; i < m_enemiesRows; ++i)
    {
        for (size_t j = 0; j < m_enemiesColumns; ++j)
        {
            int width = m_enemies.at(i).at(j).getSize().x;
            int height = m_enemies.at(i).at(j).getSize().y;
            m_enemies.at(i).at(j).spriteInit(i);
            m_enemies.at(i).at(j).setPosition(m_enemies.at(i).at(j).getPosition().x+j*width+j*30, m_enemies.at(i).at(j).getPosition().y+i*height+i*30);
        }
    }
}
sf::Time Game::getElapsed() { return m_elapsed; }
void Game::restartClock() { m_elapsed+=m_clock.restart(); }
Window* Game::getWindow() { return &m_window; }
Ship* Game::getShip() { return &m_ship; }