#include "Counter.hpp"

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

    m_count = 0;
    for(std::size_t i = 0; i < N; ++i)
    {
        m_sprites[i].setTexture(textures);
        m_sprites[i].setTextureRect(counter[0]);
    }
}
void Counter::setTexture(const sf::Texture& textures)
{
    for(std::size_t i = 0; i < N; ++i)
        m_sprites[i].setTexture(textures);
}

void Counter::increment()
{
    ++m_count;
    M_update();
}
void Counter::decrement()
{
    --m_count;
    M_update();
}

void Counter::setCount(const sf::Int16 count)
{
    m_count = count;
    M_update();
}
sf::Int16 Counter::getCount()const
{
    return m_count;
}

sf::Vector2f Counter::getSize()const
{
    return sf::Vector2f(N * Resources::Textures::COUNTER_DIGIT_WIDTH, Resources::Textures::COUNTER_DIGIT_HEIGHT);
}

void Counter::M_update()
{
    using namespace Resources::Textures::Rectangles;

    sf::Int16 number = m_count;
    std::size_t first_digit_index = 0;

    if(number < 0)
    {
        m_sprites[0].setTextureRect(counter[Indexes::CounterMinus]);
        first_digit_index = 1;
        number = -number;
    }

    for(std::size_t i = N; i > first_digit_index; --i)
    {
        m_sprites[i-1].setTextureRect(counter[number % 10]);
        number /= 10;
    }
}

Counter& Counter::operator++ () {this->increment(); return *this;}
Counter& Counter::operator-- () {this->decrement(); return *this;}

Counter& Counter::operator+= (const sf::Int16 count) {m_count += count; M_update(); return *this;}
Counter& Counter::operator-= (const sf::Int16 count) {m_count -= count; M_update(); return *this;}

Counter& Counter::operator=  (const sf::Int16 count) {this->setCount(count); return *this;}
Counter& Counter::operator=  (const Counter& counter) {this->setCount(counter.m_count); return *this;}
