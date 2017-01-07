#ifndef MINESWEEPER_COUNTER_HPP_INCLUDED
#define MINESWEEPER_COUNTER_HPP_INCLUDED

#include "RectangularObject.hpp"

class Counter : public RectangularObject
{
protected:
    static constexpr std::size_t N = 3;

    sf::Sprite m_sprites[N];
    sf::Int16 m_count;

    void M_update();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Counter();
    virtual ~Counter();

    void initialize(const sf::Texture& textures);
    void setTexture(const sf::Texture& textures);

    void increment();
    void decrement();

    void setCount(const sf::Int16 count);
    sf::Int16 getCount()const;

    sf::Vector2f getSize()const;

    Counter& operator++ ();
    Counter& operator-- ();

    Counter& operator= (const sf::Int16 count);
    Counter& operator= (const Counter& counter);

    Counter& operator+= (const sf::Int16 count);
    Counter& operator-= (const sf::Int16 count);
};

#endif
