#include "Game.hpp"
#include "textures.hpp"
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

    if(level.load(Level::SAVE_FILE) == false)
        level.create(Level::Difficulty::beginner);
}

#ifndef NDEBUG
    #include <iostream>
    using namespace std;
#endif

void Game::run()
{
    window.draw(level);
    window.display();

    sf::Event event;
    while(window.waitEvent(event))
    {
        if(event.type != sf::Event::Closed)
        {
            #ifndef NDEBUG
            sf::Clock clock;
            sf::Time time;
            clock.restart();
            #endif

            level.handleEvent(event);
            window.draw(level);
            window.display();

            #ifndef NDEBUG
            time = clock.getElapsedTime();
            cout << time.asMicroseconds() << "\n\n";
            #endif
        }
        else
        {
            level.onClosed();
            window.close();
        }
    }
}
