#include "Animation.h"
#include <iostream>
Animation::Animation(sf::Texture *texture, unsigned int imageCount, float switchTime)
{
    m_texture = *texture;
    m_imageCount=imageCount;
    this->switchTime = switchTime;
    totalTime=0.f;
    m_currentImage=0;
    uvRect.width = texture->getSize().x / float(imageCount);
    uvRect.height = 16;
}
Animation::Animation(){}
void Animation::update(float deltaTime)
{
    totalTime+=deltaTime;
    if(totalTime >= switchTime)
    {
        totalTime-=switchTime;
        m_currentImage++;
        if(m_currentImage==m_imageCount)
        {
            m_currentImage=0;
        }
    }
    uvRect.left = m_currentImage*uvRect.width;
    std::cout<<uvRect.left<<std::endl;
}