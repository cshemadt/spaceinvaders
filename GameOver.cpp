#include "Button.h" 
#include "Textbox.h"
#include "GameOver.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameOver::GameOver(Window &window) : mGameOverTextbox{sf::Vector2f(200,200),700,700,50,13,"GAME OVER"}, 
                       mResetButton{sf::Vector2f(100,300), sf::Vector2f(600,30), "PRESS ENTER TO PLAY AGAIN"},
                       mWindowSize{window.getWindowSize()}
{
}
void GameOver::render(sf::RenderWindow &window)
{
    mGameOverTextbox.render(window);
    mResetButton.render(window);
}
void GameOver::update()
{
    mResetButton.update();
}