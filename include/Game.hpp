#ifndef MINESWEEPER_GAME_HPP_INCLUDED
#define MINESWEEPER_GAME_HPP_INCLUDED

#include "def.hpp"
#include "Exception.hpp"
#include "resources.hpp"

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
