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
    
public:
    Ufo(sf::Vector2u windowSize);
    ~Ufo();
    bool isAlive;
    void setPosition(const sf::Vector2f &position);
    void setSpeed(int speed);

    void spriteInit();
    void die();
    void move(float elapsed);
    void reset();
    void render(sf::RenderWindow &renderWindow);
    sf::Vector2f getPosition();
    sf::Sprite *getSprite();
    sf::Vector2u getSize();
    bool getIsAlive() const;
    int getSpeed() const;
};
#endif