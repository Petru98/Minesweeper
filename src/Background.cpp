#include "Background.hpp"

const sf::Vector2f Background::table_position = {12.0f, 56.0f};

void Background::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());

    sf::RectangleShape rect(m_size);
    rect.setFillColor(sf::Color::White);
    target.draw(rect, states);

    rect.setFillColor(sf::Color(192, 192, 192));
    rect.setPosition(3.0f, 4.0f);
    rect.setSize(sf::Vector2f(m_size.x - 3, m_size.y - 4));
    target.draw(rect, states);

    rect.setFillColor(sf::Color(128, 128, 128));

    rect.setSize(sf::Vector2f(m_size.x - (9 + 6), 2.0f));
    rect.setPosition(9.0f, 10.0f);
    target.draw(rect, states);
    rect.move(0.0f, 43.0f);
    target.draw(rect, states);
    rect.setSize(sf::Vector2f(m_size.x - (9 + 6 + 1), 1.0f));
    rect.move(0.0f, 2.0f);
    target.draw(rect, states);

    rect.setSize(sf::Vector2f(2.0f, 34.0f));
    rect.setPosition(9.0f, 12.0f);
    target.draw(rect, states);
    rect.setSize(sf::Vector2f(2.0f, m_size.y - (56 + 6)));
    rect.move(0.0f, 44.0f);
    target.draw(rect, states);
    rect.setSize(sf::Vector2f(1.0f, m_size.y - (56 + 6 + 1)));
    rect.move(2.0f, 0.0f);
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
