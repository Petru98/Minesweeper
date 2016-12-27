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

void Level::create(const Difficulty difficulty)
{

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
