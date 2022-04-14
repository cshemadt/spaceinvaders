#include "Button.h" 
#include "Textbox.h"
#include "Win.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Win::Win(Window &window) : mBestScore{},mLastScore{},
                       mWinTextbox{sf::Vector2f(100,200),700,200,25,10,"WINNER WINNER CHICKEN DINNER"}, 
                       mBestScoreTextbox{sf::Vector2f(220,280),500,100,30,13,""},
                       mLastScoreTextbox{sf::Vector2f(220,330), 500,100,30,13,""},
                       mResetButton{sf::Vector2f(120,400), sf::Vector2f(600,30), "PRESS ENTER TO PLAY AGAIN"},
                       mWindowSize{window.getWindowSize()}
{
    mWinTextbox.setColor(sf::Color::Red);
    mBestScoreTextbox.setColor(sf::Color::Yellow);
    mLastScoreTextbox.setColor(sf::Color::Yellow);
}
void Win::render(sf::RenderWindow &window)
{
    mWinTextbox.render(window);
    mBestScoreTextbox.render(window);
    mLastScoreTextbox.render(window);
    mResetButton.render(window);
}
void Win::update(int lastScore, int bestScore)
{
    mLastScore = lastScore;
    mBestScore = bestScore;
    mLastScoreTextbox.setText("LAST SCORE "+std::to_string(mLastScore));
    mBestScoreTextbox.setText("BEST SCORE "+std::to_string(mBestScore));
    mResetButton.update();
}