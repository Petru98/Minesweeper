#include "Background.hpp"
#include "LineShape.hpp"
#include "Exception.hpp"
#include "Counter.hpp"

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

void Background::setSize(const float width, const float height)
{
    m_size.x = width;
    m_size.y = height;

    if(M_update() == false)
        throw "Could not allocate memory for the background";
}
void Background::setSize(const sf::Vector2f size)
{
    this->setSize(size.x, size.y);
}
sf::Vector2f Background::getSize()const
{
    return m_size;
}

bool Background::M_update()
{
    if(m_cache.getSize() != sf::Vector2u(m_size.x, m_size.y))
        if(m_cache.create(m_size.x, m_size.y) == false)
            return false;

    // Fill white
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(m_size.x, m_size.y));
    rect.setFillColor(sf::Color::White);
    m_cache.draw(rect);

    // Fill Grey
    rect.setFillColor(sf::Color(192, 192, 192));
    rect.setPosition(3.0f, 4.0f);
    rect.setSize(sf::Vector2f(m_size.x - 3, m_size.y - 4));
    m_cache.draw(rect);

    LineShape line;
    line.setColor(sf::Color(128, 128, 128));

    // Header top
    line.setPosition(9.0f, 10.0f);
    line.setOffset(m_size.x - (9 + 6), 0.0f);
    m_cache.draw(line);
    line.move(0.0f, 1.0f);
    line.moveOffset(-1.0f, 0.0f);
    m_cache.draw(line);

    //Table top
    line.setPosition(9.0f, 54.0f);
    line.moveOffset(1.0f, 0.0f);
    m_cache.draw(line);
    line.move(0.0f, 1.0f);
    line.moveOffset(-1.0f, 0.0f);
    m_cache.draw(line);
    line.move(0.0f, 1.0f);
    line.moveOffset(-1.0f, 0.0f);
    m_cache.draw(line);

    // Counters top
    line.setPosition(16.0f, 17.0f);
    line.setOffset(Counter::N * Counter::WIDTH + 1, 0.0f);
    m_cache.draw(line);
    line.setPosition(m_size.x - (15 + Counter::N * Counter::WIDTH + 1), line.getPosition().y);
    m_cache.draw(line);

    // Header left
    line.setPosition(10.0f, 11.0f);
    line.setOffset(0.0f, 35.0f);
    m_cache.draw(line);
    line.move(1.0f, 0.0f);
    line.moveOffset(0.0f, -1.0f);
    m_cache.draw(line);

    // Counters left
    line.setPosition(17.0f, 17.0f);
    line.setOffset(0.0f, Counter::HEIGHT);
    m_cache.draw(line);
    line.setPosition(m_size.x - (15 + Counter::N * Counter::WIDTH), line.getPosition().y);
    m_cache.draw(line);

    // Table left
    line.setPosition(10.0f, 56.0f);
    line.setOffset(0.0f, m_size.y - (56 + 6));
    m_cache.draw(line);
    line.move(1.0f, 0.0f);
    line.moveOffset(0.0f, -1.0f);
    m_cache.draw(line);
    line.move(1.0f, 0.0f);
    line.moveOffset(0.0f, -1.0f);
    m_cache.draw(line);

    line.setColor(sf::Color::White);

    // Header bottom
    line.setPosition(11.0f, 46.0f);
    line.setOffset(m_size.x - (10 + 5 + 1), 0.0f);
    m_cache.draw(line);
    line.move(-1.0f, 1.0f);
    line.moveOffset(1.0f, 0.0f);
    m_cache.draw(line);

    //Table bottom
    line.setPosition(12.0f, m_size.y - 8 + 1);
    line.moveOffset(-3.0f + 1.0f, 0.0f);
    m_cache.draw(line);
    line.move(-1.0f, 1.0f);
    line.moveOffset(1.0f, 0.0f);
    m_cache.draw(line);
    line.move(-1.0f, 1.0f);
    line.moveOffset(1.0f, 0.0f);
    m_cache.draw(line);

    // Counters bottom
    line.setPosition(17.0f, 41.0f);
    line.setOffset(Counter::N * Counter::WIDTH + 1, 0.0f);
    m_cache.draw(line);
    line.setPosition(m_size.x - (15 + Counter::N * Counter::WIDTH), line.getPosition().y);
    m_cache.draw(line);

    // Header right
    line.setPosition(m_size.x - 6.0f, 11.0f);
    line.setOffset(0.0f, 34.0f);
    m_cache.draw(line);
    line.move(1.0f, -1.0f);
    line.moveOffset(0.0f, 1.0f);
    m_cache.draw(line);

    // Counters right
    line.setPosition(18 + Counter::N * Counter::WIDTH, 17.0f);
    line.setOffset(0.0f, Counter::HEIGHT);
    m_cache.draw(line);
    line.setPosition(m_size.x - 15 + 1, line.getPosition().y);
    m_cache.draw(line);

    // Table right
    line.setPosition(m_size.x - 7.0f, 56.0f);
    line.setOffset(0.0f, m_size.y - (56 + 8));
    m_cache.draw(line);
    line.move(1.0f, -1.0f);
    line.moveOffset(0.0f, 1.0f);
    m_cache.draw(line);
    line.move(1.0f, -1.0f);
    line.moveOffset(0.0f, 1.0f);
    m_cache.draw(line);

    m_cache.display();
    m_sprite.setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));

    return true;
}
