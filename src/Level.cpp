#include "Level.hpp"

struct Level::Difficulty
{
    sf::Uint8  width;
    sf::Uint8  height;
    sf::Uint16 mines;

    Difficulty() : width(0), height(0), mines(0) {}
    Difficulty(const sf::Uint8 w, const sf::Uint8 h, const sf::Uint16 m) : width(w), height(h), mines(m) {}
};

const Level::Difficulty easy   = {9 , 9 , 10};
const Level::Difficulty medium = {16, 16, 40};
const Level::Difficulty hard   = {16, 30, 99};

Level::Level(sf::RenderWindow& window) : m_window(window)
{}

Level::~Level()
{}

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
