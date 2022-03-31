#ifndef SPACE_INVADERS_SHIP_H
#define SPACE_INVADERS_SHIP_H

#include <SFML/Graphics.hpp>
enum Direction {
    None,
    Left,
    Right
};
class Ship {
private:
    sf::Vector2u m_position;
    sf::Vector2u m_windowSize;
    Direction m_direction;
    sf::Sprite m_sprite;
    sf::Texture m_shipTexture;
    int m_hp;
    int m_score;
    int m_scoreIncrement;
    bool m_isAlive;
public:
    Ship(sf::Vector2u windowSize);
    ~Ship();
    void setPosition(sf::Vector2u &position);
    void setPosition(unsigned int x,unsigned int y);
    void setDirection(Direction);

    void spriteInit();
    void increaseScore();
    void decreaseHp();
    void lose();
    void move();
    void fire();
    void reset();
    void render(sf::RenderWindow &renderWindow);

    sf::Vector2u getPosition();
    Direction getDirection();
    sf::Sprite *getSprite();
    int getCurentHp() const;
    int getCurrentScore() const;
};
#endif
