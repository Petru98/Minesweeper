#include "Header.hpp"

void Header::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(smiley, states);
}

Header::Header() : smiley(), m_size()
{
    smiley.setOrigin(this->getPosition() + sf::Vector2f(Smiley::WIDTH / 2.0f, Smiley::HEIGHT / 2.0f));
}

Header::~Header()
{}

void Header::initialize(const sf::Texture& textures)
{
    smiley.initialize(textures, this->getPosition());
    smiley.setPosition(static_cast<int>(m_size.x) / 2, static_cast<int>(m_size.y) / 2);
}

sf::Vector2f Header::getSize()const
{
    return m_size;
}
