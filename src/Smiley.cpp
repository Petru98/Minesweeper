#include "Smiley.hpp"

void Smiley::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Smiley::Smiley() : m_sprite(), m_rect()
{}

void Smiley::initialize(const sf::Texture& textures)
{
    m_sprite.setTexture(textures);
    this->reset();
}

void Smiley::reset()
{
    using namespace Resources::Textures::Rectangles;

    m_rect = smiley[Indexes::SmileyNormal];
    m_sprite.setTextureRect(rect);
}
