#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Enemy.h"
#include <iostream>
#include <algorithm>
Game::Game() : m_window{"Space Invaders",sf::Vector2u {800,600}}, m_ship{getWindow()->getWindowSize()}
{
    reset();
    
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
    if(getShipBullets()==0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
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
    updateBullets();
    //---------------------------- CHECK COLLISION BETWEEN ENEMIES AND SHIP ----------------------------
    if(isLost())
        lose();
    if(isWin())
    {
        m_enemies.clear();
        std::cout<<"WIN!!\n";
        reset();
    }

    //---------------------------- UPDATE ENEMIES STATE ----------------------------
    updateEnemies();

}
void Game::updateBullets()
{
    for (size_t i = 0; i < m_bullets.size(); ++i)
    {
        m_bullets.at(i).move(m_elapsed);
    }
    for (size_t i = 0; i < m_bullets.size(); ++i)
    {
        if((m_bullets.at(i).getPosition().y < 0 && m_bullets.at(i).getBulletType()==BulletTypes::Ship) || (m_bullets.at(i).getPosition().y>m_window.getWindowSize().y && m_bullets.at(i).getBulletType()==BulletTypes::Enemy)|| !m_bullets.at(i).isAlive())
        {
            m_bullets.erase(m_bullets.begin()+i);
        }
    }   
    //---------------------------- BULLETS COLLISIONS ----------------------------
    if(!m_bullets.empty())
    {
        for (size_t i = 0; i < m_enemiesRows; ++i)
        {
            for (size_t j = 0; j < m_enemiesColumns; ++j)
            {
                for (size_t k = 0; k < m_bullets.size(); ++k)
                {
                    if(m_enemies.at(i).at(j).isAlive() && m_bullets.at(k).getBulletType()==BulletTypes::Ship && m_bullets.at(k).checkCollisionWith(m_enemies.at(i).at(j).getEnemyCollisionRect()))
                    {
                        m_enemies.at(i).at(j).die();
                        m_bullets.erase(m_bullets.begin()+k);
                    }
                }               
            }
        }
        for (size_t i = 0; i < m_bullets.size(); ++i)
        {
            if(m_bullets.at(i).isAlive() && m_bullets.at(i).getBulletType()==BulletTypes::Enemy && m_bullets.at(i).checkCollisionWith(m_ship.getSprite()->getGlobalBounds()))
            {
                lose();
            }
        }
        
    }
}
void Game::updateEnemies()
{
    std::srand(std::time(0));
    int rndRow=rand()%m_enemiesRows;
    int rndCol=rand()%m_enemiesColumns;
    //COULD BE BUGS!!!!!!
    while(!m_enemies.at(rndRow).at(rndCol).isAlive())
    {
        rndRow=rand()%m_enemiesRows;
        rndCol=rand()%m_enemiesColumns;
    }
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
                setDirectionToEnemies(Direction::Right);
                for (size_t i = 0; i < m_enemiesRows; ++i)
                {
                    for (size_t j = 0; j < m_enemiesColumns; ++j)
                    {
                        m_enemies.at(i).at(j).move();
                    }
                }  
            }

            m_currentEnemyBullets=0;
        }
        m_enemyElapsed-=sf::seconds(m_frameTime);
    }
    if(m_enemyShootingIntervalElapsed.asSeconds()>= m_shootingInterval)
    {
        if(m_enemies.at(rndRow).at(rndCol).isAlive() && m_currentEnemyBullets<m_enemyBulletsLimit)
        {
            m_enemies.at(rndRow).at(rndCol).fire(m_bullets);
            m_currentEnemyBullets++;
            std::cout<<m_currentEnemyBullets<<" "<< m_enemyBulletsLimit<<std::endl;
            std::cout<<"-----------\n";
        }
        m_enemyShootingIntervalElapsed-=sf::seconds(m_shootingInterval);
        
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
bool Game::isWin()
{
    bool flag=true;
    for (size_t i = 0; i < m_enemiesRows; ++i)
    {
        for (size_t j = 0; j < m_enemiesColumns; ++j)
        {
            if(m_enemies.at(i).at(j).getPosition().y < m_window.getWindowSize().y)
            {
                flag=false;
            }
        }
    }
    return flag || isAllDead();
}
void Game::reset()
{
    m_isWin=false;
    m_enemiesRows=3;
    m_enemiesColumns=12;
    m_gapBetweenEnemies = 30;
    m_frameTime=0.7;
    m_shootingInterval=1.0;
    m_isEdge = false;
    m_currentEnemyBullets = 0;
    m_enemyBulletsLimit = 3;
    initEnemies();
}
void Game::lose()
{
    m_enemies.clear();
    reset();
    //std::cout<<"LOSE!\n";
}
sf::Time Game::getElapsed() { return m_elapsed; }
void Game::restartClock() { m_elapsed=m_clock.restart(); }

sf::Time Game::getEnemyElapsed() { return m_enemyElapsed; }
void Game::restartEnemyClock() { m_enemyElapsed+=m_enemyClock.restart(); }

sf::Time Game::getEnemyShootingIntervalElapsed(){ return m_enemyShootingIntervalElapsed; }
void Game::restartEnemyShootingIntervalClock() { m_enemyShootingIntervalElapsed+=m_enemyShootingIntervalClock.restart(); }

Window* Game::getWindow() { return &m_window; }
Ship* Game::getShip() { return &m_ship; }
int Game::getShipBullets()
{
    int count=0;
    for (size_t i = 0; i < m_bullets.size(); ++i)
    {
        if(m_bullets.at(i).getBulletType()==BulletTypes::Ship && m_bullets.at(i).isAlive())
            ++count;
    }
    return count;
}
std::vector<Enemy> Game::getAliveEnemies()
{
    std::vector<Enemy> vector;
    for (size_t i = 0; i < m_enemiesRows; i++)
    {
        for (size_t j = 0; j < m_enemiesColumns; j++)
        {
            if(m_enemies.at(i).at(j).isAlive())
            {
                vector.push_back(m_enemies.at(i).at(j));
            }
        }
    }
    return vector;
}
bool Game::isAllDead()
{
    for (size_t i = 0; i < m_enemiesRows; i++)
    {
        for (size_t j = 0; j < m_enemiesColumns; j++)
        {
            if(m_enemies.at(i).at(j).isAlive())
            {
                return false;
            }
        }
    }
    return true;
}