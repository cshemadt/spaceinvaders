#ifndef SPACE_INVADERS_BUTTON_H
#define SPACE_INVADERS_BUTTON_H
#include <SFML/Graphics.hpp>
#include "Textbox.h"
class Button
{
private:
    sf::RectangleShape m_shape;
    Textbox m_text;
    bool m_pressed;
public:
    Button(sf::Vector2f position, sf::Vector2f size, std::string text);
    ~Button() = default;
    void render(sf::RenderWindow &window);
    void update();
};
#endif