#ifndef SPACE_INVADERS_GAMEOVER_H
#define SPACE_INVADERS_GAMEOVER_H
#include "Button.h" 
#include "Textbox.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
class GameOver
{
private:
    Textbox mGameOverTextbox;
    Button mResetButton;
    sf::Vector2f mWindowSize;
    
public:
    void update();
    void render(sf::RenderWindow &window);
    GameOver(Window &window);
    ~GameOver()=default;
};
#endif