#pragma once
#ifndef SPACE_INVADERS_TEXTBOX_H
#define SPACE_INVADERS_TEXTBOX_H
#include <SFML/Graphics.hpp>
class Textbox
{
private:
    sf::Vector2f m_position;
    float m_width;
    float m_height;
    sf::Text m_text;
    sf::Font m_font;
    float m_fontSize;
public:
    Textbox(const sf::Vector2f &position, float width, float height, float fontSize, float letterSpacing, std::string text);
    ~Textbox()=default;
    void render(sf::RenderWindow &renderWindow);
    sf::Text getText();
    void setText(const std::string &text);
    float getWidth();
    void setWidth(float width);
    float getHeight();
    void setHeight(float height);
    float getFontSize();
    void setFontSize(float size);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f &position);
    void setFont(sf::Font &font);
};

#endif