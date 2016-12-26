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

        return static_cast<int>(error.code());
    }

    return static_cast<int>(Error::None);
}
