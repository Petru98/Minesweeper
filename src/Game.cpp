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

#include <iostream>
using namespace std;
void Game::run()
{
    window.draw(level);
    window.display();

    sf::Event event;
    while(window.waitEvent(event))
    {
        if(event.type != sf::Event::Closed)
        {
            sf::Clock clock;
            sf::Time time;

            clock.restart();
            level.handleEvent(event);
            time = clock.getElapsedTime();
            cout << time.asMicroseconds() << '\n';

            clock.restart();
            window.draw(level);
            time = clock.getElapsedTime();
            cout << time.asMicroseconds() << '\n';

            clock.restart();
            window.display();
            time = clock.getElapsedTime();
            cout << time.asMicroseconds() << "\n\n";
        }
        else
        {
            level.onClosed();
            window.close();
        }
    }
}
