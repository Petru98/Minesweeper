#include "Smiley.hpp"

void Smiley::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Smiley::Smiley() : m_sprite(), m_sprite_rect(), m_position_offset()
{}
Smiley::~Smiley()
{}

void Smiley::initialize(const sf::Texture& textures, const sf::Vector2f position_offset)
{
    m_sprite.setTexture(textures);
    m_position_offset = position_offset;
    this->reset();
}

void Smiley::reset()
{
    using namespace Resources::Textures::Rectangles;

    m_sprite_rect = smiley[Indexes::SmileyNormal];
    m_sprite.setTextureRect(m_sprite_rect);
}

void Smiley::press()
{
    using namespace Resources::Textures::Rectangles;
    m_sprite.setTextureRect(smiley[Indexes::SmileyPressed]);
}
void Smiley::release()
{
    m_sprite.setTextureRect(m_sprite_rect);
}

void Smiley::setWin()
{
    using namespace Resources::Textures::Rectangles;

    m_sprite_rect = smiley[Indexes::SmileyWin];
    m_sprite.setTextureRect(m_sprite_rect);
}
void Smiley::setLose()
{
    using namespace Resources::Textures::Rectangles;

    m_sprite_rect = smiley[Indexes::SmileyLose];
    m_sprite.setTextureRect(m_sprite_rect);
}
void Smiley::setScared()
{
    using namespace Resources::Textures::Rectangles;

    m_sprite_rect = smiley[Indexes::SmileyScared];
    m_sprite.setTextureRect(m_sprite_rect);
}
