#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Game.h"
#include <iostream>
Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text) : m_text{sf::Vector2f(position.x+15,position.y), 400,400,25,12,""}
{
    m_text.setText(text);
    m_shape.setSize(size);
    m_shape.setPosition(position);
    m_shape.setFillColor(sf::Color::Transparent);
}
void Button::render(sf::RenderWindow &window)
{
    window.draw(m_shape);
    m_text.render(window);
}
void Button::update()
{
    if(!isPressed && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
    {
        isPressed=true;
    } 
}