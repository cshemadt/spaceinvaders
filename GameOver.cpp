#include "Button.h" 
#include "Textbox.h"
#include "GameOver.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameOver::GameOver(Window &window) : mBestScore{}, mLastScore{},
                       mGameOverTextbox{sf::Vector2f(200,200),700,100,50,13,"GAME OVER"}, 
                       mBestScoreTextbox{sf::Vector2f(220,280),500,100,30,13,""},
                       mLastScoreTextbox{sf::Vector2f(220,330), 500,100,30,13,""},
                       mResetButton{sf::Vector2f(120,400), sf::Vector2f(600,30), "PRESS ENTER TO PLAY AGAIN"},
                       mWindowSize{window.getWindowSize()}
{
    mBestScoreTextbox.setColor(sf::Color::Yellow);
    mLastScoreTextbox.setColor(sf::Color::Yellow);
}
void GameOver::render(sf::RenderWindow &window)
{
    mGameOverTextbox.render(window);
    mBestScoreTextbox.render(window);
    mLastScoreTextbox.render(window);
    mResetButton.render(window);
}
void GameOver::update(int lastScore, int bestScore)
{
    mLastScore = lastScore;
    mBestScore = bestScore;
    mLastScoreTextbox.setText("LAST SCORE "+std::to_string(mLastScore));
    mBestScoreTextbox.setText("BEST SCORE "+std::to_string(mBestScore));
    mResetButton.update();
}