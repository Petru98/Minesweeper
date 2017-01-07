#include "Header.hpp"

void Header::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(flags_left, states);
    target.draw(smiley, states);
    target.draw(moves, states);
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
    flags_left.setPosition(6.0f, 5.0f);
    flags_left.initialize(textures);
    moves.setPosition(m_size.x - (moves.getSize().x + 8.0f), 5.0f);
    moves.initialize(textures);
}
void Header::setTexture(const sf::Texture& textures)
{
    smiley.setTexture(textures);
    flags_left.setTexture(textures);
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
