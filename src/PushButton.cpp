#include "PushButton.hpp"

void PushButton::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

PushButton::PushButton() : m_sprite(), m_pressed(false)
{}

PushButton::~PushButton()
{}

void PushButton::initialize(const sf::Texture& textures, const sf::IntRect rect)
{
    m_sprite.setTexture(textures);
    m_sprite.setTextureRect(rect);
    m_pressed = false;
}

void PushButton::press()
{
    m_pressed = true;
}
bool PushButton::release()
{
    if(m_pressed == false)
        return false;
    m_pressed = false;
    return true;
}

bool PushButton::isPressed()const
{
    return m_pressed;
}

sf::Vector2f PushButton::getSize()const
{
    const sf::IntRect rect = m_sprite.getTextureRect();
    return sf::Vector2f(rect.width, rect.height);
}
