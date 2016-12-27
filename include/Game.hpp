#ifndef MINESWEEPER_GAME_HPP_INCLUDED
#define MINESWEEPER_GAME_HPP_INCLUDED

#include "textures.hpp"

#include "Exception.hpp"
#include "def.hpp"

#include "Scene.hpp"
#include "Cell.hpp"

class Game
{
private:
    sf::RenderWindow window;
    sf::Texture textures;

    struct Error
    {
        enum
        {
            None,
            LoadTextures
        };

        static constexpr const char* messages[] =
        {
            "No error",
            "Could not load textures from memory"
        };
    };

public:
    Game();
    ~Game();

    void initialize();
    void run();
};

#endif
