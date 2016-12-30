#include "Smiley.hpp"

void Smiley::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Smiley::Smiley() : m_sprite(), m_rect()
{}
Smiley::~Smiley()
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
    m_sprite.setTextureRect(m_rect);
}

void Smiley::press()
{
    using namespace Resources::Textures::Rectangles;
    m_sprite.setTextureRect(smiley[Indexes::SmileyPressed]);
}
void Smiley::release()
{
    m_sprite.setTextureRect(m_rect);
}

void Smiley::setWin()
{
    using namespace Resources::Textures::Rectangles;

    m_rect = smiley[Indexes::SmileyWin];
    m_sprite.setTextureRect(m_rect);
}
void Smiley::setLose()
{
    using namespace Resources::Textures::Rectangles;

    m_rect = smiley[Indexes::SmileyLose];
    m_sprite.setTextureRect(m_rect);
}
void Smiley::setScared()
{
    using namespace Resources::Textures::Rectangles;

    m_rect = smiley[Indexes::SmileyScared];
    m_sprite.setTextureRect(m_rect);
}
