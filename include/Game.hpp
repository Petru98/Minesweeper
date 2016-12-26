#ifndef MINESWEEPER_GAME_HPP_INCLUDED
#define MINESWEEPER_GAME_HPP_INCLUDED

#include "images.hpp"
#include "Exception.hpp"
#include "def.hpp"
#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow window;
    sf::Texture textures[Resources::Images::Indexes::Count];

public:
    Game();
    ~Game();

    void initialize();
    void run();
};

#endif
