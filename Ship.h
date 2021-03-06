#ifndef SPACE_INVADERS_SHIP_H
#define SPACE_INVADERS_SHIP_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
enum Direction 
{
    None,
    Left,
    Right,
    Down
};
class Ship 
{
private:
    sf::Vector2f m_position;
    sf::Vector2f m_windowSize;
    Direction m_direction;
    sf::Sprite m_sprite;
    sf::Texture m_shipTexture;
    int m_hp;
    int m_speed;
    bool m_isAlive;
public:
    Ship(sf::Vector2u windowSize);
    ~Ship()=default;
    void setPosition(sf::Vector2f &position);
    void setPosition(float x,float y);
    void setDirection(Direction);

    void spriteInit();
    void increaseScore();
    void decreaseHp();
    void lose();
    void move(const Direction &direction, sf::Time elapsed);
    void fire(std::vector<Bullet> &bullets);
    void reset();
    void render(sf::RenderWindow &renderWindow);

    sf::Vector2f getPosition();
    Direction getDirection();
    sf::Sprite *getSprite();
    int getCurentHp() const;
    int getCurrentScore() const;
};
#endif
