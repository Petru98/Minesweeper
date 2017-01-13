#include "Game.hpp"
#include "textures.hpp"
#include "Exception.hpp"
#include "random.hpp"
#include <chrono>

Game::Game() : window(), textures(), level(window, textures)
{}
Game::~Game()
{}

void Game::initialize()
{
    using namespace Resources;
    using namespace std::chrono;

    Random::engine.seed(system_clock::to_time_t(system_clock::now()));

    if(textures.loadFromMemory(Textures::pack.data, Textures::pack.size) == false)
        throw Exception("Could not load the textures");

    if(level.load(Level::SAVE_FILE) == false)
        level.create(Level::Difficulty::beginner);
}

void Game::run()
{
    window.draw(level);
    window.display();

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
