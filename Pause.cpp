#include "Button.h" 
#include "Textbox.h"
#include "Pause.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Pause::Pause(Window &window,int currentScore) : mPauseTextbox{sf::Vector2f(250,200),200,200,50,13,"PAUSED"},
                                                mUnpauseButton{sf::Vector2f(130,350), sf::Vector2f(600,30), "PRESS ENTER TO UNPAUSE"},
                                                mWindowSize{window.getWindowSize()},
                                                mCurrentScore{currentScore},
                                                mScoreTextbox{sf::Vector2f(130,270),200,200,30,10,"YOUR CURRENT SCORE "+std::to_string(mCurrentScore)} 
{
}
void Pause::render(sf::RenderWindow &window)
{
    mPauseTextbox.render(window);
    mUnpauseButton.render(window);
    mScoreTextbox.render(window);
}
void Pause::update(int score)
{
    mScoreTextbox.setText("YOUR CURRENT SCORE "+std::to_string(score));
    mUnpauseButton.update();
}
Button* Pause::getButton()
{
    return &mUnpauseButton;
}