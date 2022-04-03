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
        m_ship.move(Direction::Left, m_elapsed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
    {
        m_ship.move(Direction::Right, m_elapsed);
    }
    if(m_bullets.size() == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_ship.fire(m_bullets);
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
    for (size_t i = 0; i < m_bullets.size(); ++i)
    {
        m_window.draw(m_bullets.at(i));
    }
    
    m_ship.render(*m_window.getRenderWindow());  
    
    m_window.endDraw();
}
void Game::update() 
{
    getWindow()->update();
    tick();
    
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
void Game::tick()
{
    for (size_t i = 0; i < m_bullets.size(); ++i)
    {
        m_bullets.at(i).setPosition(m_bullets.at(i).getPosition().x, m_bullets.at(i).getPosition().y-400*m_elapsed.asSeconds());
    }
    for (size_t i = 0; i < m_bullets.size(); ++i)
    {
        if(m_bullets.at(i).getPosition().y < 0)
        {
            m_bullets.clear();
        }
    }
    if(m_bullets.size() != 0)
    {
        for (size_t i = 0; i < m_enemies.size(); ++i)
        {
            for (size_t j = 0; j < m_enemiesColumns; j++)
            {
            }
            
        }
    }
    
    
    
    
}
sf::Time Game::getElapsed() { return m_elapsed; }
void Game::restartClock() { m_elapsed=m_clock.restart(); }
Window* Game::getWindow() { return &m_window; }
Ship* Game::getShip() { return &m_ship; }