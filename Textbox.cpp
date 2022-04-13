#include <SFML/Graphics.hpp>
#include "Textbox.h"
#include <iostream>
Textbox::Textbox(const sf::Vector2f &position, float width, float height, float fontSize, float letterSpacing, std::string text)
    : m_width(width), m_height(height), m_position(position), m_fontSize(fontSize)
{
    if(!m_font.loadFromFile("../assets/fonts/ArcadeClassic.ttf"))
    {
        std::cout<<"Couldn't load font\n";
    }
    m_text=sf::Text(text, m_font);
    m_text.setFont(m_font);
    m_text.setPosition(position);
    m_text.setCharacterSize(m_fontSize);
    m_text.setLetterSpacing(letterSpacing);
}
sf::Text Textbox::getText()
{
    return m_text;
}
void Textbox::setText(const std::string &text)
{
    m_text.setString(text);
}
void Textbox::render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(m_text);
}
