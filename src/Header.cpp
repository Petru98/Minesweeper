#include "Header.hpp"

void Header::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(smiley, states);
    target.draw(moves);
}

Header::Header() : smiley(), m_size()
{
    smiley.setOrigin(sf::Vector2f(Smiley::WIDTH / 2.0f, Smiley::HEIGHT / 2.0f));
}
Header::~Header()
{}

void Header::initialize(const sf::Texture& textures)
{
    smiley.setPosition(static_cast<int>(m_size.x) / 2, static_cast<int>(m_size.y) / 2);
    smiley.initialize(textures);
    moves.setPosition(this->getPosition() + sf::Vector2f(m_size.x - moves.getSize().x - 8, 5));
    moves.initialize(textures);
}
void Header::setTexture(const sf::Texture& textures)
{
    smiley.setTexture(textures);
    moves.setTexture(textures);
}

void Header::setSize(const float width, const float height)
{
    m_size.x = width;
    m_size.y = height;
}
void Header::setSize(const sf::Vector2f size)
{
    this->setSize(size.x, size.y);
}

sf::Vector2f Header::getSize()const
{
    return m_size;
}
