#ifndef MINESWEEPER_STRING_HPP_INCLUDED
#define MINESWEEPER_STRING_HPP_INCLUDED

#include <SFML/Config.hpp>

sf::Uint16 stringToUint16(const char* str)
{
    sf::Uint16 number = 0;

    while((*str) != 0)
    {
        number = number * 10 + ((*str) - '0');
        ++str;
    }

    return number;
}

#endif
