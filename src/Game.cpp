#include "Game.hpp"

Game::Game() : window()
{
    window.create(sf::VideoMode(800,600), "Minesweeper");
}

Game::~Game()
{
}

void Game::initialize()
{
}

void Game::run()
{
    sf::Event event;
    while(window.waitEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            window.close();
        }
    }
}
