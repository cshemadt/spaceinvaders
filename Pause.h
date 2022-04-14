#ifndef SPACE_INVADERS_PAUSE_H
#define SPACE_INVADERS_PAUSE_H
#include "Button.h" 
#include "Textbox.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
class Pause
{
private:
    Textbox mPauseTextbox;
    Textbox mScoreTextbox;
    Button mUnpauseButton;
    sf::Vector2f mWindowSize;
    int mCurrentScore;
    
public:
    Pause(Window &window, int currentScore);
    ~Pause()=default;
    void update(int score);
    void render(sf::RenderWindow &window);
    Button* getButton();
};
#endif