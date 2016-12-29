#include "Game.hpp"

#include "Exception.hpp"

Game::Game() : window(), textures(), level(window, textures)
{}

Game::~Game()
{}

void Game::initialize()
{
    using namespace Resources;

    if(textures.loadFromMemory(Textures::pack.data, Textures::pack.size) == false)
        throw Exception(Error::LoadTextures, Error::messages[Error::LoadTextures]);

    level.create(Level::beginner);
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
            window.display();
        }
        else
        {
            level.onClosed();
            window.close();
        }
    }
}
