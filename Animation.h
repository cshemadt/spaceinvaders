#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation();
    Animation(sf::Texture *texture, unsigned int imageCount, float switchTime);
    ~Animation()=default;
    sf::IntRect uvRect;
    sf::Texture m_texture;
    void update(float deltaTime);
private:
    unsigned int m_imageCount;
    unsigned int m_currentImage;
    float totalTime;
    float switchTime; 
};