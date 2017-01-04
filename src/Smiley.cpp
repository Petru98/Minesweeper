#include "Smiley.hpp"

void Smiley::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Smiley::Smiley() : m_sprite(), m_sprite_rect()
{}
Smiley::~Smiley()
{}

void Smiley::initialize(const sf::Texture& textures)
{
    this->setTexture(textures);
    this->reset();
}
void Smiley::setTexture(const sf::Texture& textures)
{
    m_sprite.setTexture(textures);
}
void Smiley::reset()
{
    using namespace Resources::Textures::Rectangles;

    m_sprite_rect = smiley[Indexes::SmileyNormal];
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

bool Smiley::press()
{
    using namespace Resources::Textures::Rectangles;

    if(this->isPressed() == true)
        return false;

    m_sprite.setTextureRect(smiley[Indexes::SmileyPressed]);
    return true;
}
bool Smiley::release()
{
    if(this->isPressed() == false)
        return false;

    m_sprite.setTextureRect(m_sprite_rect);
    return true;
}
bool Smiley::isPressed()const
{
    using namespace Resources::Textures::Rectangles;
    return m_sprite.getTextureRect() == smiley[Indexes::SmileyPressed];
}

sf::Vector2f Smiley::getSize()const
{
    return sf::Vector2f(this->WIDTH, this->HEIGHT);
}
