#include "Game.hpp"

Game::Game() : window(), textures(), level(window)
{}

Game::~Game()
{}

void Game::initialize()
{
    using namespace Resources;

    if(textures.loadFromMemory(Textures::pack.data, Textures::pack.size) == false)
        throw Exception(Error::LoadTextures, Error::messages[Error::LoadTextures]);

    level.create(Level::easy);
}

void Game::run()
{
    sf::Event event;
    while(window.waitEvent(event))
    {
        if(event.type != sf::Event::Closed)
        {
            level.handleEvent(event);
            window.draw(level);
        }
        else
        {
            level.onClosed();
            window.close();
        }
    }
}
