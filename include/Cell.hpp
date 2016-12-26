#ifndef MINESWEEPER_CELL_HPP_INCLUDED
#define MINESWEEPER_CELL_HPP_INCLUDED

#include "images.hpp"
#include <SFML/Graphics.hpp>

class Cell : sf::Drawable
{
private:


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Cell();
};

#endif
