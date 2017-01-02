#ifndef MINESWEEPER_COUNTER_HPP_INCLUDED
#define MINESWEEPER_COUNTER_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Counter : public sf::Drawable, public sf::Transformable
{
private:
    static constexpr std::size_t N = 3;

    sf::Sprite m_sprites[N];
    sf::Uint16 m_count;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Counter();
    virtual ~Counter();

    void initialize(const sf::Texture& textures);

    void increment();
    void decrement();

    void setCount(const sf::Uint16 count);
    sf::Uint16 getCount()const;
};

#endif
