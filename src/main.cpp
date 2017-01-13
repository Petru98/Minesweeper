#include "Game.hpp"
#include "Exception.hpp"
#include "def.hpp"
#include "os.hpp"

int main()
{
    Game game;

    try
    {
        game.initialize();
    }
    catch(const std::exception& error)
    {
        os::error(error.what());
        return 0x80000000;
    }
    catch(...)
    {
        os::error("Unknown error");
        return 0xFFFFFFFF;
    }

    game.run();

    return 0;
}
