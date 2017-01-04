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
    template<typename T> void log(const char* const type)
    {
        cout << type << " = " << sizeof(T) << '\n';
    }
    #define STRINGIFY(x) #x
    #define log_size(type) log<type>(STRINGIFY(type))
#else
    #define log(x)
#endif

int main()
{
    log_size(Game);
    log_size(Level);
    log_size(MenuBar);
    log_size(GameMenu);
    log_size(Background);
    log_size(Header);
    log_size(Table);
    log_size(Cell);

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
