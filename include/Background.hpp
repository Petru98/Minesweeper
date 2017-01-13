#ifndef MINESWEEPER_BACKGROUND_HPP_INCLUDED
#define MINESWEEPER_BACKGROUND_HPP_INCLUDED

#include "ResizableRectangularObject.hpp"

class Background : public ResizableRectangularObject
{
public:
    static const sf::Vector2f header_position;
    static const sf::Vector2f table_position;

private:
    sf::RenderTexture m_cache;
    sf::Sprite        m_sprite;
    sf::Vector2f      m_size;

    bool M_update();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Background();
    virtual ~Background();

    virtual void setSize(const float width, const float height);
    virtual void setSize(const sf::Vector2f size);

    virtual sf::Vector2f getSize()const;
};

#endif
