#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Enemy.h"
#include <iostream>
Game::Game() : m_window{"Space Invaders",sf::Vector2u {800,600}}, m_ship{getWindow()->getWindowSize()}
{
    m_enemiesRows=3;
    m_enemiesColumns=12;
    m_gapBetweenEnemies = 30;
    m_frameTime=0.3;
    m_isEdge = false;
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
    if(m_bullets.size() == 0 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        m_ship.fire(m_bullets);
    }
}
void Game::render() 
{
    m_window.beginDraw();
    //---------------------------- DRAWING ENEMIES ----------------------------
    for (size_t i = 0; i < m_enemiesRows; ++i)
    {
        for (size_t j = 0; j < m_enemiesColumns; ++j)
        {
            if(m_enemies.at(i).at(j).isAlive())
            {
                m_enemies.at(i).at(j).render(*m_window.getRenderWindow());
            }
        }
    }
    //---------------------------- DRAWING BULLET ----------------------------
    for (size_t i = 0; i < m_bullets.size(); ++i)
    {
        if (m_bullets.at(i).isAlive())
        {
            m_bullets.at(i).render(*m_window.getRenderWindow());
        }
    }
    
    m_ship.render(*m_window.getRenderWindow());  
    
    m_window.endDraw();
}
void Game::update() 
{
    getWindow()->update();
    tick();
    
}
void Game::moveEnemiesDown()
{
    for (size_t i = 0; i < m_enemiesRows; ++i)
    {
        for (size_t j = 0; j < m_enemiesColumns; ++j)
        {
            m_enemies.at(i).at(j).setPosition(m_enemies.at(i).at(j).getPosition().x, m_enemies.at(i).at(j).getPosition().y+(m_enemies.at(i).at(j).getSize().y*2));
        }
    }
    
}
void Game::setDirectionToEnemies(Direction direction)
{
    for (size_t i = 0; i < m_enemiesRows; ++i)
    {
        for (size_t j = 0; j < m_enemiesColumns; ++j)
        {
            m_enemies.at(i).at(j).setDirection(direction);
        }
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
    //---------------------------- DRAWING ENEMIES ----------------------------
    for (size_t i = 0; i < m_enemiesRows; ++i)
    {
        for (size_t j = 0; j < m_enemiesColumns; ++j)
        {
            int width = m_enemies.at(i).at(j).getSize().x;
            int height = m_enemies.at(i).at(j).getSize().y;
            m_enemies.at(i).at(j).spriteInit(i);
            m_enemies.at(i).at(j).setDirection(Direction::Right);
            m_enemies.at(i).at(j).setPosition(m_enemies.at(i).at(j).getPosition().x+j*width+j*m_gapBetweenEnemies, m_enemies.at(i).at(j).getPosition().y+i*height+i*m_gapBetweenEnemies);
        }
    }
}
void Game::tick()
{
    //---------------------------- UPDATE BULLETS STATE ----------------------------
    for (size_t i = 0; i < m_bullets.size(); ++i)
    {
        m_bullets.at(i).move(m_elapsed);
    }
    for (size_t i = 0; i < m_bullets.size(); ++i)
    {
        if(m_bullets.at(i).getPosition().y < 0 || !m_bullets.at(i).isAlive())
        {
            m_bullets.clear();
        }
    }   
    //---------------------------- BULLETS COLLISIONS ----------------------------
    if(!m_bullets.empty())
    {
        for (size_t i = 0; i < m_enemiesRows; ++i)
        {
            for (size_t j = 0; j < m_enemiesColumns; ++j)
            {
                if(m_enemies.at(i).at(j).isAlive() && m_bullets.at(0).checkCollisionWith(m_enemies.at(i).at(j).getEnemyCollisionRect()))
                {
                    m_enemies.at(i).at(j).die();
                }
            }
        }    
    }
    //---------------------------- CHECK COLLISION BETWEEN ENEMIES AND SHIP ----------------------------
    if(isLost())
    {
        lose();
    }
    //---------------------------- UPDATE ENEMIES STATE ----------------------------
    if(m_enemyElapsed.asSeconds()>=m_frameTime)
    {
        for (size_t i = 0; i < m_enemiesRows; ++i)
        {
            for (size_t j = 0; j < m_enemiesColumns; ++j)
            {
                
                if(m_enemies.at(i).at(j).isAlive() && (m_enemies.at(i).at(j).getDirection()==Direction::Right) && m_enemies.at(i).at(j).getPosition().x+(m_enemies.at(i).at(j).getSize().x*2)>= m_window.getWindowSize().x)
                {
                    m_isEdge=true;
                }
                else if(m_enemies.at(i).at(j).isAlive() && m_enemies.at(i).at(j).getDirection()==Direction::Left && m_enemies.at(i).at(j).getPosition().x-(m_enemies.at(i).at(j).getSize().x*2) <= 0)
                {
                    m_isEdge=true;
                }
                m_enemies.at(i).at(j).move();
            }
        }       
        if(m_isEdge)
        {
            moveEnemiesDown();
            m_isEdge=false;
            if(m_enemies.at(0).at(0).getDirection()==Direction::Right)
            {
                if(m_frameTime>=0.1)
                {
                    m_frameTime-=0.05;
                }
                std::cout<<m_frameTime<<std::endl;
                setDirectionToEnemies(Direction::Left);
                for (size_t i = 0; i < m_enemiesRows; ++i)
                {
                    for (size_t j = 0; j < m_enemiesColumns; ++j)
                    {
                        m_enemies.at(i).at(j).move();
                    }
                }  
            }
            else if(m_enemies.at(0).at(0).getDirection()==Direction::Left)
            {
                if(m_frameTime>0.1)
                {
                    m_frameTime-=0.05;
                }
                std::cout<<m_frameTime<<std::endl;
                setDirectionToEnemies(Direction::Right);
                for (size_t i = 0; i < m_enemiesRows; ++i)
                {
                    for (size_t j = 0; j < m_enemiesColumns; ++j)
                    {
                        m_enemies.at(i).at(j).move();
                    }
                }  
            }
        }
        
        m_enemyElapsed-=sf::seconds(m_frameTime);
    }

}
bool Game::isLost()
{
    for (size_t i = 0; i < m_enemiesRows; ++i)
    {
        for (size_t j = 0; j < m_enemiesColumns; ++j)
        {
            if(m_enemies.at(i).at(j).isAlive() && m_enemies.at(i).at(j).getEnemyCollisionRect().intersects(m_ship.getSprite()->getGlobalBounds()))
            {
                return true;
            }
        }
    }
    return false;
}
void Game::lose()
{
    m_enemies.clear();
    initEnemies();
    m_frameTime=0.3;
    m_isEdge = false;
    std::cout<<"LOSE!\n";
}
sf::Time Game::getElapsed() { return m_elapsed; }
void Game::restartClock() { m_elapsed=m_clock.restart(); }

sf::Time Game::getEnemyElapsed() { return m_enemyElapsed; }
void Game::restartEnemyClock() { m_enemyElapsed+=m_enemyClock.restart(); }


Window* Game::getWindow() { return &m_window; }
Ship* Game::getShip() { return &m_ship; }