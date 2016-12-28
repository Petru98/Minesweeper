#include "Background.hpp"

void Background::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());

    sf::RectangleShape rect(m_size);
    rect.setFillColor(sf::Color::White);
    target.draw(rect, states);

    rect.setPosition(3.0f, 4.0f);
    rect.setSize(sf::Vector2f(m_size.x - 3, m_size.y - 4));
    rect.setFillColor(sf::Color(192, 192, 192));
    target.draw(rect, states);
}

Background::Background() : m_size()
{}

void Background::setSize(const float width, const float height)
{
    m_size.x = width;
    m_size.y = height;
}
sf::Vector2f Background::getSize()const
{
    return m_size;
}
