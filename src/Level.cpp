#include "Level.hpp"
#include "random.hpp"
#include <ctime>

const Level::Difficulty Level::easy   = {9 , 9 , 10};
const Level::Difficulty Level::medium = {16, 16, 40};
const Level::Difficulty Level::hard   = {16, 30, 99};

void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

}

Level::Level(sf::RenderWindow& window) : m_window(window), m_cells()
{
    Random::seed(std::time(nullptr));
}

Level::~Level()
{}

void Level::create(Difficulty difficulty)
{
    difficulty = S_correctDifficulty(difficulty);
    m_cells.create()
}
Level::Difficulty Level::S_correctDifficulty(Level::Difficuly difficulty)
{
    if(difficulty.lines == 0)
        difficulty.lines = 1;
    if(difficulty.columns < 8)
        difficulty.column = 8;
    if(difficulty.mines == 0)
        difficulty.mines = 1;
    return difficulty;
}

void Level::onClosed()
{

}

void Level::onResized(const sf::Event::SizeEvent&)
{

}

void Level::onLostFocus()
{

}

void Level::onGainedFocus()
{

}

void Level::onTextEntered(const sf::Event::TextEvent&)
{

}

void Level::onKeyPressed(const sf::Event::KeyEvent&)
{

}

void Level::onKeyReleased(const sf::Event::KeyEvent&)
{

}

void Level::onMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent&)
{

}

void Level::onMouseButtonPressed(const sf::Event::MouseButtonEvent&)
{

}

void Level::onMouseButtonReleased(const sf::Event::MouseButtonEvent&)
{

}

void Level::onMouseMoved(const sf::Event::MouseMoveEvent&)
{

}

void Level::onMouseEntered()
{

}

void Level::onMouseLeft()
{

}
