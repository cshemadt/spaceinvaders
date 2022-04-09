#ifndef SPACE_INVADERS_UFO_H
#define SPACE_INVADERS_UFO_H
#include <SFML/Graphics.hpp>
class Ufo
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2u m_size;
    sf::Vector2u m_windowSize;
    int m_speed;
    int m_startLocationOffset;
    bool m_isAlive;
public:
    Ufo(sf::Vector2u windowSize);
    ~Ufo()=default;

    void setPosition(const sf::Vector2f &position);
    void setSpeed(int speed);

    void spriteInit();
    void die();
    void move();
    void reset();
    void render(sf::RenderWindow &renderWindow);
    sf::Vector2f getPosition();
    sf::Sprite *getSprite();
    sf::Vector2u getSize();
    bool isAlive() const;
    int getSpeed() const;
};
#endif