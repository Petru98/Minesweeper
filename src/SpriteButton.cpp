#include "SpriteButton.hpp"

void SpriteButton::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

SpriteButton::SpriteButton() : m_sprite(), m_pressed(false)
{}
SpriteButton::~SpriteButton()
{}

void SpriteButton::initialize(const sf::Texture& textures, const sf::IntRect rect)
{
    this->setTexture(textures, rect);
    m_pressed = false;
}
void SpriteButton::setTexture(const sf::Texture& textures, const sf::IntRect rect)
{
    m_sprite.setTexture(textures);
    m_sprite.setTextureRect(rect);
}

bool SpriteButton::press()
{
    if(m_pressed == true)
        return false;
    m_pressed = true;
    return true;
}
bool SpriteButton::release()
{
    if(m_pressed == false)
        return false;
    m_pressed = false;
    return true;
}
bool SpriteButton::isPressed()const
{
    return m_pressed;
}

sf::Vector2f SpriteButton::getSize()const
{
    const sf::IntRect rect = m_sprite.getTextureRect();
    return sf::Vector2f(rect.width, rect.height);
}
