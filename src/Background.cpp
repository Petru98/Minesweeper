#include "Background.hpp"
#include "Exception.hpp"

const sf::Vector2f Background::header_position = {11.0f, 12.0f};
const sf::Vector2f Background::table_position = {12.0f, 56.0f};

void Background::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());
    target.draw(m_sprite, states);
}

Background::Background() : m_cache(), m_sprite(m_cache.getTexture()), m_size()
{}
Background::~Background()
{}

void Background::M_update()
{
    if(m_cache.getSize() != sf::Vector2u(m_size.x, m_size.y))
        if(m_cache.create(m_size.x, m_size.y) == false)
            throw Exception(__LINE__, __FILE__);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(m_size.x, m_size.y));
    rect.setFillColor(sf::Color::White);
    m_cache.draw(rect);

    rect.setFillColor(sf::Color(192, 192, 192));
    rect.setPosition(3.0f, 4.0f);
    rect.setSize(sf::Vector2f(m_size.x - 3, m_size.y - 4));
    m_cache.draw(rect);

    rect.setFillColor(sf::Color(128, 128, 128));

    rect.setSize(sf::Vector2f(m_size.x - (9 + 6), 2.0f));
    rect.setPosition(9.0f, 10.0f);
    m_cache.draw(rect);
    rect.move(0.0f, 43.0f);
    m_cache.draw(rect);
    rect.setSize(sf::Vector2f(m_size.x - (9 + 6 + 1), 1.0f));
    rect.move(0.0f, 2.0f);
    m_cache.draw(rect);

    rect.setSize(sf::Vector2f(2.0f, 34.0f));
    rect.setPosition(9.0f, 12.0f);
    m_cache.draw(rect);
    rect.setSize(sf::Vector2f(2.0f, m_size.y - (56 + 6)));
    rect.move(0.0f, 44.0f);
    m_cache.draw(rect);
    rect.setSize(sf::Vector2f(1.0f, m_size.y - (56 + 6 + 1)));
    rect.move(2.0f, 0.0f);
    m_cache.draw(rect);

    m_cache.display();
    m_sprite.setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));
}

sf::Vector2f Background::getSize()const
{
    return m_size;
}
