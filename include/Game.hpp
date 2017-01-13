#ifndef MINESWEEPER_GAME_HPP_INCLUDED
#define MINESWEEPER_GAME_HPP_INCLUDED

#include "Level.hpp"

class Game
{
private:
    sf::RenderWindow window;
    sf::Texture      textures;
    Level            level;

public:
    Game();
    ~Game();

    void initialize();
    void run();
};

#endif
