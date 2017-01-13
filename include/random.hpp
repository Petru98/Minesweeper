#ifndef MINEWEEPER_RANDOM_HPP_INCLUDED
#define MINEWEEPER_RANDOM_HPP_INCLUDED

#include <cstdint>
#include <random>

namespace Random
{
    typedef std::mt19937 Engine;
    typedef std::uniform_int_distribution<std::size_t> Distribution;

    extern Engine engine;
}

#endif
