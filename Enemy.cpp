#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Enemy::Enemy(sf::Vector2u windowSize) : m_windowSize{windowSize}
{
    reset();    
    updateCollisionRect();
}    

//---------------------------- SETTERS ----------------------------
void Enemy::setPosition(unsigned int x, unsigned int y) 
{
    m_enemySprite.setPosition(sf::Vector2f(x, y));
    updateCollisionRect();

}
void Enemy::setPosition(const sf::Vector2f &position) 
{
    m_enemySprite.setPosition(sf::Vector2f(position));
    updateCollisionRect();

}
void Enemy::setSpeed(int speed) { m_speed = speed; }
void Enemy::setDirection(Direction direction) { m_direction = direction; }


//---------------------------- GAME LOGIC ----------------------------
void Enemy::reset() 
{
    m_size=sf::Vector2u{16,16};
    m_currentTextureIndex=0;
    m_enemySprite.setPosition(m_windowSize.x/5-30,100);
    m_isAlive=true;
    m_speed=20;
    explosionFlag=false;
    m_currentExplosionIndex=0;
}
void Enemy::spriteInit(int index)
{
    std::string path="../assets/Enemy"+std::to_string(index)+".png";
    if(!m_enemyTexture.loadFromFile(path))
    {
        std::cout<<"Textures not found. \n";
        return;
    }
    explosionTexture.loadFromFile("../assets/Explosion.png");
    m_enemySprite.setTexture(m_enemyTexture);
    m_enemySprite.setScale(3.f,3.f);
    m_enemySprite.setTextureRect(sf::IntRect(m_currentTextureIndex*16,0,16,16));
    m_enemySprite.setOrigin(m_enemySprite.getTextureRect().width/2.f, m_enemySprite.getTextureRect().height/2.f);
}
void Enemy::updateCollisionRect()
{
    m_enemyCollisionRect = sf::FloatRect(m_enemySprite.getGlobalBounds().left, m_enemySprite.getGlobalBounds().top, m_enemySprite.getGlobalBounds().width-8,m_enemySprite.getGlobalBounds().height-8);
}
void Enemy::update(float deltaTime)
{
    if(!explosionFlag)
    {
        if(m_currentTextureIndex == 0 && m_isAlive)
        {
            m_currentTextureIndex = 1;
        }
        else if(m_currentTextureIndex == 1 && m_isAlive)
        {
            m_currentTextureIndex = 0;
        }
        m_enemySprite.setTextureRect(sf::IntRect(m_currentTextureIndex*16,0,16,16));
    }
}
void Enemy::updateExplosionAnimation()
{
    if(explosionFlag)
    {
        if(m_currentExplosionIndex == 14) { m_currentExplosionIndex = 0; explosionFlag = false; }
        m_currentExplosionIndex++;
        m_enemySprite.setTexture(explosionTexture);
        m_enemySprite.setTextureRect(sf::IntRect(m_currentExplosionIndex*16,0,16,16));
        }
}

void Enemy::die() 
{
    m_isAlive = false;
}
void Enemy::move() 
{
    if(m_isAlive || explosionFlag)
    {
        switch(m_direction)
        {
            case Direction::Right:
                setPosition(sf::Vector2f(m_enemySprite.getPosition().x+m_speed, m_enemySprite.getPosition().y));
            break;
            case Direction::Left: 
                setPosition(sf::Vector2f(m_enemySprite.getPosition().x-m_speed, m_enemySprite.getPosition().y));
            break;
            case Direction::None:
                setPosition(sf::Vector2f(m_enemySprite.getPosition().x, m_enemySprite.getPosition().y));
            break;
            case Direction::Down:
                setPosition(sf::Vector2f(m_enemySprite.getPosition().x, m_enemySprite.getPosition().y+m_speed));
            break;
        }
    }
}
void Enemy::fire(std::vector<Bullet> &bullets) 
{
    Bullet bullet;
    bullet.setBulletType(BulletTypes::Enemy);
    bullet.setSpeed(500);
    bullet.setPosition(sf::Vector2f(getPosition().x, getPosition().y+getSprite()->getGlobalBounds().height/2));    
    bullets.push_back(bullet);
}
void Enemy::render(sf::RenderWindow &renderWindow) 
{
    renderWindow.draw(m_enemySprite);
}
//---------------------------- GETTERS   ----------------------------
sf::Vector2f Enemy::getPosition() { return m_enemySprite.getPosition(); }
Direction Enemy::getDirection() { return m_direction; }
sf::Sprite *Enemy::getSprite() { return &m_enemySprite; }
sf::Vector2u Enemy::getSize() { return m_size; }
bool Enemy::isAlive() const { return m_isAlive; }
sf::FloatRect Enemy::getEnemyCollisionRect() { return m_enemyCollisionRect; }
int Enemy::getSpeed() const { return m_speed; }
