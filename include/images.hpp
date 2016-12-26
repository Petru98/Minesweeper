#ifndef MINESWEEPER_RESOURCES_IMAGES_HPP_INCLUDED
#define MINESWEEPER_RESOURCES_IMAGES_HPP_INCLUDED

#include "Resource.hpp"

namespace Resources
{
    enum class ImageIndexes
    {
        CellEmpty,
        Cell1,
        Cell2,
        Cell3,
        Cell4,
        Cell5,
        Cell6,
        Cell7,
        Cell8,
        CellMine,
        CellMineClicked,
        CellNormal,
        CellFlag,

        Count
    };

    extern const Resource images[];
}

#endif
