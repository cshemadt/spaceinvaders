#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text)
{
    m_shape.setSize(size);
    m_shape.setPosition(position);
    if(!m_font.loadFromFile("../assets/fonts/ArcadeClassic.ttf"))
    {
        std::cout<<"ArcadeClassic font not found!\n";
    }
    m_text.setString(text);
    m_text.setFont(m_font);
    m_text.setFillColor(sf::Color::White);
    m_text.setCharacterSize(12);
    m_text.setLetterSpacing(30);
    m_text.setPosition(
        m_shape.getPosition().x/2.f - m_text.getGlobalBounds().width/2.f,
        m_shape.getPosition().y/2.f - m_text.getGlobalBounds().height/2.f);
}
void Button::render(sf::RenderWindow &window)
{
    window.draw(m_shape);
}
void Button::update(const sf::Vector2f mousePos)
{
    if(m_shape.getGlobalBounds().contains(mousePos))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_pressed=true;
            std::cout<<"pressed!\n";
        }
    }
}