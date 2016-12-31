#ifndef MINESWEEPER_BACKGROUND_HPP_INCLUDED
#define MINESWEEPER_BACKGROUND_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Background : public sf::Drawable, public sf::Transformable
{
public:
    static const sf::Vector2f header_position;
    static const sf::Vector2f table_position;

private:
    sf::RenderTexture m_cache;
    sf::Sprite        m_sprite;
    sf::Vector2f      m_size;

    void M_update();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Background();

    template<typename T> void setSize(const T width, const T height)
    {
        m_size.x = width;
        m_size.y = height;
        M_update();
    }
    template<typename T> void setSize(const sf::Vector2<T> size)
    {
        m_size.x = size.x;
        m_size.y = size.y;
        M_update();
    }

    sf::Vector2f getSize()const;
};

#endif
