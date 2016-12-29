#ifndef MINESWEEPER_RESOURCES_TEXTURES_HPP_INCLUDED
#define MINESWEEPER_RESOURCES_TEXTURES_HPP_INCLUDED

#include "Resource.hpp"
#include <SFML/Graphics.hpp>

namespace Resources
{
    namespace Textures
    {
        constexpr int CELL_WIDTH = 16;
        constexpr int CELL_HEIGHT = 16;
        constexpr int SMILEY_WIDTH = 26;
        constexpr int SMILEY_HEIGHT = 26;
        constexpr int DIGIT_WIDTH = 13;
        constexpr int DIGIT_HEIGHT = 23;

        namespace Rectangles
        {
            namespace Indexes
            {
                enum Cell
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

                    CellNormal,
                    CellFlag,
                    CellMine,
                    CellMineClicked,
                    CellMineWrong,
                    CellMark,
                    CellMarkPressed
                };
                enum Smiley
                {
                    SmileyNormal,
                    SmileyPressed,
                    SmileyScared,
                    SmileyWin,
                    SmileyLose
                };
                enum Digit
                {
                    None = 10
                };
            }

            extern const sf::IntRect cell[];
            extern const sf::IntRect smiley[];
            extern const sf::IntRect digit[];
        }

        extern const Resource pack;
    }
}

#endif
