#ifndef MINESWEEPER_HEADER_HPP_INCLUDED
#define MINESWEEPER_HEADER_HPP_INCLUDED

#include "Smiley.hpp"
#include <SFML/Graphics.hpp>

class Header : public sf::Drawable, public sf::Transformable
{
public:
    static constexpr std::size_t HEIGHT = 33;

    Smiley smiley;
private:
    sf::Vector2f m_size;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Header();
    ~Header();

    void initialize(const sf::Texture& textures);

    template<typename T> void setSize(const T width, const T height)
    {
        m_size.x = width;
        m_size.y = height;
    }
    template<typename T> void setSize(const sf::Vector2<T> size)
    {
        m_size.x = size.x;
        m_size.y = size.y;
    }

    sf::Vector2f getSize()const;
};

#endif
