#include "Counter.hpp"
#include "textures.hpp"

void Counter::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform.combine(this->getTransform());

    for(std::size_t i = 0; i < N; ++i)
        target.draw(m_sprites[i], states);
}

Counter::Counter() : m_count(0)
{
    using namespace Resources::Textures;
    const sf::Vector2f offset = {COUNTER_DIGIT_WIDTH, 0.0f};

    for(std::size_t i = 1; i < N; ++i)
        m_sprites[i].setPosition(static_cast<float>(i) * offset);
}

Counter::~Counter()
{}

void Counter::initialize(const sf::Texture& textures)
{
    using namespace Resources::Textures::Rectangles;

    for(std::size_t i = 0; i < N; ++i)
    {
        m_sprites[i].setTexture(textures);
        m_sprites[i].setTextureRect(counter[0]);
    }
}

void Counter::increment()
{
    ++m_count;
}
void Counter::decrement()
{
    --m_count;
}

void Counter::setCount(const sf::Uint16 count)
{
    m_count = count;
}
sf::Uint16 Counter::getCount()const
{
    return m_count;
}
