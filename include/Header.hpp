#ifndef MINESWEEPER_HEADER_HPP_INCLUDED
#define MINESWEEPER_HEADER_HPP_INCLUDED

#include "Smiley.hpp"
#include <SFML/Graphics.hpp>

class Header : public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
    Smiley smiley;

    Header();
    ~Header();
};

#endif
