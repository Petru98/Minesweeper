#ifndef MINESWEEPER_CELL_HPP_INCLUDED
#define MINESWEEPER_CELL_HPP_INCLUDED

#include "textures.hpp"
#include <SFML/Graphics.hpp>

class Cell : sf::Drawable
{
private:
    sf::Sprite m_sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Cell();
};

#endif
