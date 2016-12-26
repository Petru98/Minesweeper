#ifndef MINESWEEPER_RESOURCE_HPP_INCLUDED
#define MINESWEEPER_RESOURCE_HPP_INCLUDED

#include <cstddef>

namespace Resources
{
    struct Resource
    {
        const std::size_t size;
        const void* const data;
    };
}

#endif
