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

        namespace Rectangles
        {
            extern const sf::IntRect CellEmpty;
            extern const sf::IntRect Cell1;
            extern const sf::IntRect Cell2;
            extern const sf::IntRect Cell3;
            extern const sf::IntRect Cell4;
            extern const sf::IntRect Cell5;
            extern const sf::IntRect Cell6;
            extern const sf::IntRect Cell7;
            extern const sf::IntRect Cell8;
            extern const sf::IntRect CellMine;
            extern const sf::IntRect CellMineClicked;
            extern const sf::IntRect CellNormal;
            extern const sf::IntRect CellFlag;

            extern const sf::IntRect SmileyNormal;
            extern const sf::IntRect SmileyScared;
            extern const sf::IntRect SmileyWin;
            extern const sf::IntRect SmileyDead;
        }

        extern const Resource pack;
    }
}

#endif
