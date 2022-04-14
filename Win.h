#ifndef SPACE_INVADERS_WIN_H
#define SPACE_INVADERS_WIN_H
#include "Button.h" 
#include "Textbox.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
class Win
{
private:
    Textbox mWinTextbox;
    Textbox mBestScoreTextbox;
    Textbox mLastScoreTextbox;
    Button mResetButton;
    sf::Vector2f mWindowSize;
    int mBestScore;
    int mLastScore;
    
public:
    void update(int lastScore, int bestScore);
    void render(sf::RenderWindow &window);
    Win(Window &window);
    ~Win()=default;
};
#endif