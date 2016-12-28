#ifndef MINESWEEPER_BACKGROUND_HPP_INCLUDED
#define MINESWEEPER_BACKGROUND_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Background : public sf::Drawable, public sf::Transformable
{
private:
    sf::Vector2f m_size;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Background();

    void setSize(const float width, const float height);
    sf::Vector2f getSize()const;
};

#endif
