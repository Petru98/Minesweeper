#ifndef MINESWEEPER_STRING_HPP_INCLUDED
#define MINESWEEPER_STRING_HPP_INCLUDED

#include <SFML/Config.hpp>

void reverseString(char* begin, char* end)
{
    --end;
    while(end > begin)
    {
        (*begin) ^= (*end);
        (*end) ^= (*begin);
        (*begin) ^= (*end);
        ++begin;
        --end;
    }
}

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

char* Uint16ToString(sf::Uint16 number, char* const str)
{
    char* it = str;

    do
    {
        (*it) = number % 10 + '0';
        number /= 10;
        ++it;
    }while(number != 0);

    (*it) = 0;
    reverseString(str, it);

    return str;
}

#endif
