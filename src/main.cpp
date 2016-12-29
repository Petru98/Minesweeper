#include "Game.hpp"
#include "Exception.hpp"
#include "def.hpp"

#ifndef NDEGUB
    #include <iostream>
    using namespace std;

    void log(const Exception error)
    {
        cout << error.what() << '\n';
    }
    template<typename T> void log(T x)
    {
        cout << x << '\n';
    }
    template<typename T> void log()
    {
        cout << sizeof(T) << '\n';
    }
#else
    #define log(x)
#endif

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
        log(error);
        return error.code();
    }

    return 0;
}
