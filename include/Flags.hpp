#ifndef MINESWEEPER_FLAGS_HPP_INCLUDED
#define MINESWEEPER_FLAGS_HPP_INCLUDED

#include <SFML/Config.hpp>

template <typename T>
class Flags
{
private:
    T m_flags;

public:
    Flags() : m_flags(0) {}
    Flags(const T value) : m_flags(value) {}
    Flags(const Flags& flags) : m_flags(flags.m_flags) {}

    void set(const T mask)    {m_flags |=  mask;}
    void reset(const T mask)  {m_flags &= ~mask;}
    void toggle(const T mask) {m_flags ^=  mask;}

    T get(const T mask)const {return m_flags & mask;}

    Flags& operator= (const T value)      {m_flags = value; return *this;}
    Flags& operator= (const Flags& flags) {m_flags = flags.m_flags; return *this;}

    Flags operator~ ()const {return ~m_flags;}

    Flags operator& (const T mask)const {return m_flags & mask;}
    Flags operator| (const T mask)const {return m_flags | mask;}
    Flags operator^ (const T mask)const {return m_flags ^ mask;}

    Flags& operator&= (const T mask) {m_flags &= mask; return *this;}
    Flags& operator|= (const T mask) {m_flags |= mask; return *this;}
    Flags& operator^= (const T mask) {m_flags ^= mask; return *this;}
};

typedef Flags<sf::Uint8> Flags8;
typedef Flags<sf::Uint16> Flags16;
typedef Flags<sf::Uint32> Flags32;
typedef Flags<sf::Uint64> Flags64;

#endif
