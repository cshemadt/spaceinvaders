#include <SFML/Graphics.hpp>
#ifndef SPACE_INVADERS_WINDOW_H
#define SPACE_INVADERS_WINDOW_H

class Window {
private:
        sf::RenderWindow m_renderWindow;
        sf::Vector2u m_windowSize;
        std::string m_windowTitle;
        bool m_isClosed;
        bool m_isFullscreen;

        void destroy();
        void create();
public:
        //Constructors & destructors
        Window(const std::string& title, const sf::Vector2u& size);
        ~Window();

        void beginDraw(); // Clear the window
        void endDraw(); // Display the changes
        void update();
        void draw(sf::Drawable& drawable);

        bool isClosed() const;
        bool isFullscreen() const;

        sf::Vector2u getWindowSize() const;
        std::string getWindowTitle() const;
        sf::RenderWindow* getRenderWindow();
        void toggleFullscreen();
};


#endif
