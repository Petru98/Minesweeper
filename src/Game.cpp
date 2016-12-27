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
    if(textures.loadFromMemory(Resources::Textures::pack.data, Resources::Textures::pack.size) == false)
        throw Exception(Error::LoadTextures, Error::messages[Error::LoadTextures]);
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

        sf::Sprite sprite(textures);
        window.draw(sprite);
        window.display();
    }
}
