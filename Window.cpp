#include <SFML/Graphics.hpp>
#include "Window.h"
Window::Window(const std::string &title, const sf::Vector2u &size) : m_windowTitle{title}, m_windowSize{size} 
{
    m_isClosed = false;
    m_isFullscreen = false;
    create();
}
Window::~Window() {}
void Window::destroy() { m_renderWindow.close(); }
void Window::create() 
{
    auto style = m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
    sf::VideoMode videoMode{m_windowSize.x, m_windowSize.y, 32};
    m_renderWindow.create(videoMode, m_windowTitle, style);
}
void Window::update() 
{
    sf::Event event;
    while (m_renderWindow.pollEvent(event)) 
    {
        if(event.type == sf::Event::Closed) 
        {
            m_isClosed=true;
        }
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) 
        {
            toggleFullscreen();
        }
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LAlt+sf::Keyboard::F4) 
        {
            m_isClosed=true;
        }
    }
}
void Window::beginDraw() { m_renderWindow.clear(sf::Color::Black); }
void Window::endDraw() { m_renderWindow.display(); }
void Window::draw(sf::Drawable &drawable) { m_renderWindow.draw(drawable); }
void Window::toggleFullscreen() 
{
    m_isFullscreen = !m_isFullscreen;
    destroy();
    create();
}
// Some getters
sf::Vector2u Window::getWindowSize() const { return m_windowSize; }
sf::RenderWindow* Window::getRenderWindow() { return &m_renderWindow; }
std::string Window::getWindowTitle() const { return m_windowTitle; }
bool Window::isClosed() const { return m_isClosed; }
bool Window::isFullscreen() const { return m_isFullscreen; }
