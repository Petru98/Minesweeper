#include "Game.hpp"

int main()
{
    Game game;

    try
    {
        game.initialize();
        game.run();
    }
    catch(Exception error)
    {
        return error.code();
    }

    return 0;
}
