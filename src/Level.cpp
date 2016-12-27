#include "Level.hpp"
#include "random.hpp"
#include <ctime>

/* Static */
const Level::Difficulty Level::easy   = {9 , 9 , 10};
const Level::Difficulty Level::medium = {16, 16, 40};
const Level::Difficulty Level::hard   = {16, 30, 99};

/* Draw */
void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

}

/* Constructor / Destructor */
Level::Level(sf::RenderWindow& window) : m_window(window), m_cells()
{
    Random::seed(std::time(nullptr));
}

Level::~Level()
{}

/* New game */
void Level::create(Difficulty difficulty)
{
    difficulty = S_correctDifficulty(difficulty);
    if(m_cells.create(difficulty.lines, difficulty.columns) == false)
        throw Exception(Error::Allocate, Error::messages[Error::Allocate]);

    M_placeMines(difficulty.mines);
    M_initializeWindow(difficulty);
}
Level::Difficulty Level::S_correctDifficulty(Level::Difficulty difficulty)
{
    if(difficulty.lines == 0)
        difficulty.lines = 1;
    if(difficulty.columns < 8)
        difficulty.column = 8;
    if(difficulty.mines == 0)
        difficulty.mines = 1;
    else if(difficulty.mines >= difficulty.lines*difficulty.columns)
        difficulty.mines = difficulty.lines*difficulty.coulmns;
    return difficulty;
}
void M_placeMines(Difficulty difficulty)
{
    while(difficulty.mines > 0)
    {
        std::size_t line = Random::rand() % difficulty.lines;
        std::size_t column = Random::rand() % difficulty.columns;
    }
}
void Level::M_initializeWindow(const Level::Difficulty difficulty)
{
    const sf::Vector2u size(Cell::width * difficulty.column + s_cell_left_offset + s_cell_right_offset,
                            Cell::height* difficulty.lines  + s_cell_top_offset  + s_cell_bottom_offset);
    m_window.setSize(size);
}

/* Events */
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
