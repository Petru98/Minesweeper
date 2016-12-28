#include "Level.hpp"

#include "Exception.hpp"
#include "random.hpp"
#include <ctime>

const Level::Difficulty Level::easy   = {9 , 9 , 10};
const Level::Difficulty Level::medium = {16, 16, 40};
const Level::Difficulty Level::hard   = {16, 30, 99};

/* Draw */
void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    //M_drawMenu(target, states);
    target.draw(m_background, states);
    M_drawHead(target, states);
    M_drawCells(target, states);
}
void Level::M_drawHead(sf::RenderTarget& target, sf::RenderStates& states)const
{

}
void Level::M_drawCells(sf::RenderTarget& target, sf::RenderStates& states)const
{
    for(std::size_t i = 0; i < m_cells.lines(); ++i)
        for(std::size_t j = 0; j < m_cells.columns(); ++j)
            target.draw(m_cells[i][j]);
}


/* Constructor / Destructor */
Level::Level(sf::RenderWindow& window, const sf::Texture& texture) : m_window(window), m_textures(texture), m_background(), m_cells()
{
    Random::seed(std::time(nullptr));
}

Level::~Level()
{}

/* New game */
void Level::create(Level::Difficulty difficulty)
{
    difficulty = S_correctDifficulty(difficulty);
    if(m_cells.create(difficulty.lines, difficulty.columns) == false)
        throw Exception(Error::Allocate, Error::messages[Error::Allocate]);

    M_initializeBackground(difficulty);
    M_initializeCells();
    M_placeMines(difficulty);
    M_resizeWindow();
}
Level::Difficulty Level::S_correctDifficulty(Level::Difficulty difficulty)
{
    if(difficulty.lines == 0)
        difficulty.lines = 1;
    if(difficulty.columns < 8)
        difficulty.columns = 8;
    if(difficulty.mines == 0)
        difficulty.mines = 1;
    else if(difficulty.mines >= difficulty.lines*difficulty.columns)
        difficulty.mines = difficulty.lines*difficulty.columns;
    return difficulty;
}
void Level::M_initializeBackground(const Level::Difficulty difficulty)
{
    m_background.setPosition(0.0f, s_MENU_HEIGHT);
    m_background.setSize(Cell::width * difficulty.columns + Cell::LEFT_OFFSET + Cell::RIGHT_OFFSET,
                         Cell::height* difficulty.lines   + Cell::TOP_OFFSET  + Cell::BOTTOM_OFFSET);
}
void Level::M_initializeCells()
{
    for(std::size_t i = 0; i < m_cells.lines(); ++i)
        for(std::size_t j = 0; j < m_cells.columns(); ++j)
        {
            m_cells[i][j].initialize(m_textures);
            m_cells[i][j].setPosition(Cell::LEFT_OFFSET + j*Cell::width, s_MENU_HEIGHT + Cell::TOP_OFFSET + i*Cell::height);
        }
}
void Level::M_placeMines(Level::Difficulty difficulty)
{
    while(difficulty.mines > 0)
    {
        const std::size_t line = Random::rand() % difficulty.lines;
        const std::size_t column = Random::rand() % difficulty.columns;

        if(m_cells[line][column].hasMine() == false)
        {
            m_cells[line][column].setMine();
            --difficulty.mines;
        }
    }
}
void Level::M_resizeWindow()
{
    const sf::Vector2u size(m_background.getSize().x, m_background.getSize().y + s_MENU_HEIGHT);
    if(m_window.isOpen() == false)
    {
        m_window.create(sf::VideoMode(size.x, size.y), "Minesweeper", sf::Style::Titlebar | sf::Style::Close);
        if(m_window.isOpen() == false)
            throw Exception(Error::CreateWindow, Error::messages[Error::CreateWindow]);
    }
    else
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
