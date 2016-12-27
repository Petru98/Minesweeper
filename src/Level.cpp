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
    M_drawBackground(target, states);
    M_drawHead(target, states);
    M_drawCells(target, states);
}
void Level::M_drawBackground(sf::RenderTarget& target, sf::RenderStates& states)const
{
    target.clear(sf::Color::White);
    const sf::Vector2f size = {static_cast<float>(target.getSize().x), static_cast<float>(target.getSize().y)};

    M_drawRect(target, sf::Color(236, 233, 216), 0, 0, size.x, s_menu_height);
    M_drawRect(target, sf::Color(192, 192, 192), 3, s_menu_height+4, size.x-3, s_menu_height-s_menu_height-4);
}
void Level::M_drawRect(sf::RenderTarget& target, const sf::Color color, const float x, const float y, const float w, const float h)const
{
    sf::RectangleShape rect(sf::Vector2f(w,h));
    rect.setFillColor(color);
    rect.setPosition(x,y);
    target.draw(rect);
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
Level::Level(sf::RenderWindow& window, const sf::Texture& texture) : m_window(window), m_textures(texture), m_cells()
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

    M_initializeCells();
    M_placeMines(difficulty);
    M_initializeWindow(difficulty);
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
void Level::M_initializeCells()
{
    for(std::size_t i = 0; i < m_cells.lines(); ++i)
        for(std::size_t j = 0; j < m_cells.columns(); ++j)
        {
            m_cells[i][j].initialize(m_textures);
            m_cells[i][j].setPosition(s_cell_left_offset + j*Cell::width, s_cell_top_offset + i*Cell::height);
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
void Level::M_initializeWindow(const Level::Difficulty difficulty)
{
    const sf::Vector2u size(Cell::width * difficulty.columns + s_cell_left_offset + s_cell_right_offset,
                            Cell::height* difficulty.lines   + s_cell_top_offset  + s_cell_bottom_offset);
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
