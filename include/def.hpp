#ifndef MINESWEEPER_MSDEF_HPP_INCLUDED
#define MINESWEEPER_MSDEF_HPP_INCLUDED

#include <SFML/Config.hpp>
#include <cstddef>

#define FUNCTION_NO_DUPLICATES inline

#ifdef WIN32
    #define main WinMain
#endif

#endif
