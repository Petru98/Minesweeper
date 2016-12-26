#ifndef MINESWEEPER_GAME_HPP_INCLUDED
#define MINESWEEPER_GAME_HPP_INCLUDED

#include "images.hpp"
#include "Exception.hpp"
#include "def.hpp"

class Game
{
private:

public:
    Game();
    ~Game();

    void initialize();
    void run();
};

#endif
