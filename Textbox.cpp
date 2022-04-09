#include <SFML/Graphics.hpp>
#include "Textbox.h"
#include <iostream>
Textbox::Textbox(const sf::Vector2f &position, float width, float height, float fontSize, std::string text)
    : m_width(width), m_height(height), m_position(position), m_fontSize(fontSize), m_text(sf::Text(text, m_font))
{
    m_text.setColor(sf::Color::White);
    if(!m_font.loadFromFile("../assets/fonts/Terminess.ttf"))
    {
        std::cout<<"Couldn't load font\n";
    }
    m_text.setFont(m_font);
}
sf::Text Textbox::getText()
{
    return m_text;
}
void Textbox::setText(std::string &text)
{
    m_text=sf::Text(text, m_font);
}
void Textbox::render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(m_text);
}
