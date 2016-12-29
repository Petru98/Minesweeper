#ifndef MINESWEEPER_HEADER_HPP_INCLUDED
#define MINESWEEPER_HEADER_HPP_INCLUDED

#include "Smiley.hpp"
#include <SFML/Graphics.hpp>

class Header : public sf::Drawable, public sf::Transformable
{
private:
    Smiley m_smiley;

public:
    Header();
    ~Header();
};

#endif
